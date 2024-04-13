namespace Bank
{
    public class BankClient
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool OpenedAccount { get; set; }

        public BankClient(int id, string name, bool openedAccount)
        {
            Id = id;
            Name = name;
            OpenedAccount = openedAccount;
        }

        public BankClient()
        {
            Id = 0;
            Name = "Name";
            OpenedAccount = false;
        }
    }
}