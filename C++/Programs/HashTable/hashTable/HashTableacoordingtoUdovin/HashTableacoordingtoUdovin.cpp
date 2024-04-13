// HashTableacoordingtoUdovin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Person {
private:
    int id;
    std::string name;
    std::string phone;
public:
    Person* next = nullptr;
    Person(int id_, std::string name_, std::string phone_) :
        id(id_), name(name_), phone(phone_) {};
    void Print();
    int GetId();
    std::string GetName(); void SetName(std::string name_);
    std::string GetPhone(); void SetPhone(std::string phone_);
};
class PersonList {
protected:
    int count;
    Person* head = nullptr;  Person* tail = nullptr;
public:
    PersonList() : count(0) {};   ~PersonList();
    void Add(Person* person);
    void Add(Person* new_person, int index);
    void Remove(int index);
    void RemoveById(int id);
    Person* Search(int id);
    void Print();
    int GetLength();
};

class PersonHashTable {
public:
    PersonHashTable(int size); ~PersonHashTable();
    void Insert(int id, std::string name, std::string phone);
    int CalculateHash(int key);
    Person* Search(int id);
    void Remove(int id);
    void Print();
private:
    int size;
    int count;
    PersonList** items;
};

void PersonHashTable::Insert(int id, string name, string phone) {
    int index = this->CalculateHash(id);
    PersonList* persons = this->items[index];
    if (this->count == this->size)
        return;
    Person* existing_person = persons->Search(id);
    if (existing_person) {
        existing_person->SetName(name);
        existing_person->SetPhone(phone);
    }
    else {
        Person* new_person = new Person(id, name, phone);
        persons->Add(new_person, persons->GetLength());
    }
}

Person* PersonHashTable::Search(int id) {
    int index = this->CalculateHash(id);
    PersonList* persons = this->items[index];
    return persons->Search(id);
}

void PersonHashTable::Remove(int id) {
    int index = this->CalculateHash(id);
    PersonList* persons = this->items[index];
    return persons->RemoveById(id);
}

int PersonHashTable::CalculateHash(int key) {
    return key % this->size;
}

void PersonHashTable::Print() {
    for (int i = 0; i < this->size; i++) {
        this->items[i]->Print();
    }
}


int main() {
    srand(time(NULL));
    PersonHashTable* table = new PersonHashTable(10);

    for (int key = 1; key < 59; key++) {
        table->Insert(
            key,
            "User " + to_string(key), GetRandomPhone()
        );
    }

    table->Print();

    return 0;
}
