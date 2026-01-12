// HASHMAP using C++
#include <iostream>
#include <vector>
using namespace std;

class HashMap
{
private:
    // storing data in table
    int capacity;
    vector<vector<pair<int, string>>> table; // [[{}]]

    // HASH FUNCTION
    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    // CONSTRUCTOR
    HashMap()
    {
        this->capacity = 100;
        table.resize(100);
    }
    HashMap(int capacity)
    {
        this->capacity = capacity;
        table.resize(capacity);
    }

    // METHODS

    /// @brief Printing
    void print()
    {
        for (auto &row : table)
        {
            for (auto &bucket : row)
            {
                cout << "{" << bucket.first << "->" << bucket.second << "}" << " ";
            }
            // cout << endl;
        }
        cout << endl;
    }

    // OPERATIONS

    /// @brief Add Item
    /// @param key
    /// @param value
    void insert(int key, string value)
    {
        int index = hashFunction(key);
        for (auto bucket : table[index])
        {
            if (bucket.first == key)
            {
                bucket.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    /// @brief Delete Item
    /// @param key
    void remove(int key)
    {
    }

    /// @brief Get value at key
    /// @param key
    /// @return string
    string get(int key)
    {
        int index = hashFunction(key);
        for (auto &bucket : table[index])
        {
            if (bucket.first == key)
            {
                return bucket.second;
            }
        }
        return "Value for provided key Does Not Exist";
    }
    /// @brief To check if key is present
    /// @param key
    /// @return boolean
    bool isPresent(int key)
    {
        int index = hashFunction(key);
        for (auto &bucket : table[index])
        {
            if (bucket.first == key)
            {
                return true;
            }
        }
        return false;
    }

    int size()
    {
        return 0;
    }
};

int main()
{
    HashMap mpp;
    mpp.insert(1, "Vikas");
    mpp.insert(1, "Roshan");
    mpp.insert(1, "Rohan");
    mpp.insert(3, "Saini");
    mpp.print();
    return 0;
}