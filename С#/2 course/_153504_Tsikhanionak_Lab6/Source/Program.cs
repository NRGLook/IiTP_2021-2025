using System.Reflection;
using System.Linq;

namespace Source
{
    public class Program
    {
        public static void Main()
        {
            string[] names = new string[5] { "Vasya", "Kolya", "Kirya", "Dima", "Ulya"};
            int[] ids = new int[5] { 123, 999, 555, 444, 891 };
            Employee[] employees = new Employee[5];
            for (int i = 0; i < names.Length; i++)
            {
                employees[i] = new Employee(ids[i], i % 2 == 0, names[i]);
            }
            Console.WriteLine("Input data:");
            Array.ForEach(employees, e => Console.WriteLine($"Name: {e.Name}; Id:{e.Id}; isDeleted:{e.IsDeleted};"));
            //load DLL
            Assembly asm = Assembly.LoadFrom("FileService.dll");
            //look at the type name of FileService from type list 
            //Array.ForEach(asm.GetTypes(), e => Console.WriteLine(e.FullName));
            
            Type? FileService = asm.GetType("FileService.FileSevice`1")?.MakeGenericType(typeof(Employee));
            object? instance = Activator.CreateInstance(FileService);
            //get methods from dll
            MethodInfo? SaveData = FileService.GetMethod("SaveData");
            MethodInfo? ReadFile = FileService.GetMethod("ReadFile");

            SaveData?.Invoke(instance, new object[] { employees, "json.json" });

            var resList = ReadFile?.Invoke(instance, new object[] { "json.json" }) as List<Employee>;

            Console.WriteLine("\nData from json:");
            resList?.ForEach(e => Console.WriteLine($"Name: {e.Name}; Id:{e.Id}; isDeleted:{e.IsDeleted};"));

        }
    }
}