// HASHMAP using C++
#include <iostream>
#include <vector>
using namespace std;

class HashMap
{
private:
    // storing data in table
    vector<pair<int, string>> table;

public:
    // constructors
    HashMap()
    {
        table;
    }
    HashMap(vector<pair<int, string>> data)
    {
        table = data;
    }

    // methods
    void push(pair<int, string> data)
    {
        table.push_back(data);
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