// HASHMAP using C++
#include <iostream>
#include <vector>
using namespace std;

class HashMap
{
private:
    // storing data in table
    int size;
    vector<pair<int, string>> table; // key, value

public:
    // constructors

    HashMap()
    {
        this->size = 100;
        table.resize(100);
    }
    HashMap(int size)
    {
        this->size = size;
        table.resize(size);
    }
    HashMap(vector<pair<int, string>> data)
    {
        table = data;
    }

    // Hash Function

    int hashFunction(int key)
    {
        key % size;
    }

    // methods
    void push(pair<int, string> data)
    {
        for(auto el: table){
            if(el.first == data.first){
                
            }
        }
    }

    void print()
    {
        cout << "##########" << endl;
        for (auto it : table)
        {
            cout << it.first << " " << it.second << endl;
        }
        cout << "##########" << endl;
    }
};

int main()
{
    HashMap mpp;

    mpp.push({2, "vikas"});
    mpp.push({3, "rohan"});
    mpp.push({3, "rohan"});
    mpp.push({3, "rohan"});
    mpp.push({3, "rohan"});
    mpp.print();
    return 0;
}