#include <iostream>
#include <map>
#include <unordered_map>


using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    unordered_map<int, string> MyMap;

    cout<< endl<< endl<< MyMap.load_factor();

    cout<< endl<<endl<<MyMap.max_bucket_count();

    return 0;
}

