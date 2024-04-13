using Domain;
using _Serializer;

namespace _153504_Tsikhanionak_Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Station[] stations = new Station[3];
            string[] directions = new string[] { "Minsk", "Gomel", "Grodno", "Brest", "Vitebsk", "Mogilev" };
            for (int i = 0; i < stations.Length; i++)
            {
                stations[i] = new Station(i * 123, i % 2 == 0, new List<string> { directions[i << 1], directions[(i << 1) + 1] });
            }
            Serializer serializer = new Serializer();
            serializer.SerializeByXML(stations, "XML.xml");
            var XMLSerializer = serializer.DeSerializeByXML("XML.xml");
            if (XMLSerializer != null)
            {
                Console.WriteLine("\nXML Serializer\n");
                foreach (var s in XMLSerializer)
                {
                    Console.WriteLine(s);
                }
            }

            serializer.SerializeByJSON(stations, "JSON.json");
            var JSONSerializer = serializer.DeSerializeByJSON("JSON.json");
            if (JSONSerializer != null)
            {
                Console.WriteLine("\nJSON Serializer\n");
                foreach (var s in JSONSerializer)
                {
                    Console.WriteLine(s);
                }
            }

            serializer.SerializeByLINQ(stations, "LinqToXML.xml");
            var LINQToXMLSerializer = serializer.DeSerializeByLINQ("LinqToXML.xml");
            if (LINQToXMLSerializer != null)
            {
                Console.WriteLine("\nJSON Serializer\n");
                foreach (var s in LINQToXMLSerializer)
                {
                    Console.WriteLine(s);
                }
            }
        }
    }
}