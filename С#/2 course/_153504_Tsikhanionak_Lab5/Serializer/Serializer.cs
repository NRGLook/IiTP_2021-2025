using System.Text;
using Domain;
using System.Xml.Serialization;
using System.Text.Json;
using System.Xml.Linq;

namespace _Serializer
{
    public class Serializer : ISerializer
    {
        public IEnumerable<Station>? DeSerializeByJSON(string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return JsonSerializer.Deserialize(fs, typeof(List<Station>)) as IEnumerable<Station>;
            }
        }

        public IEnumerable<Station>? DeSerializeByLINQ(string fileName)
        {
            XDocument xdoc = XDocument.Load(fileName);
            List<Station> list = new List<Station>();
            
            foreach(var elem in xdoc.Root.Elements())
            {
                var lug_compartment = elem.Element("Luggage_Compartment");
                bool isFull = lug_compartment.Attribute("isFull").Value == "true";
                double capacity = double.Parse(lug_compartment.Attribute("Capacity").Value);
                var directions = elem.Element("Directions").Value.Trim().Split().ToList();
                list.Add(new Station(capacity, isFull, directions));
            }
            return list;
        }

        public IEnumerable<Station>? DeSerializeByXML(string fileName)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Station>));
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return serializer.Deserialize(fs) as List<Station>;
            }
        }

        public void SerializeByJSON(IEnumerable<Station> value, string fileName)
        {
            var json = JsonSerializer.Serialize(value.ToList());
            File.WriteAllBytes(fileName, Encoding.ASCII.GetBytes(json));
        }

        public void SerializeByLINQ(IEnumerable<Station> value, string fileName)
        {
            //root 
            XDocument document = new XDocument(new XElement("Stations"));
            foreach (var station in value) {
                //main element of node
                var currentStation = new XElement("Station");
                //first sibling of node
                var compartment = new XElement("Luggage_Compartment");
                compartment.Add(new XAttribute("isFull", station.LuggageCompartment.IsFull));
                compartment.Add(new XAttribute("Capacity", station.LuggageCompartment.Capacity));
                //second sibling of node
                var directions = new XElement("Directions");
                foreach (var direction in station.Directions) {
                    directions.Value += direction + " ";
                }
                currentStation.Add(compartment);
                currentStation.Add(directions);

                document.Root.Add(currentStation);
            }
            document.Save(fileName);
        }

        public void SerializeByXML(IEnumerable<Station> value, string fileName)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Station>));
            using (FileStream fileStream = new FileStream(fileName, FileMode.Create))
            {
                serializer.Serialize(fileStream, value.ToList());
            }
        }
    }
}
