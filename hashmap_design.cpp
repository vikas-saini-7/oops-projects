// HASHMAP using C++
#include <iostream>
#include <vector>
using namespace std;

class HashMap
{
private:
    // storing data in table
    int capacity;
    int count;
    vector<vector<pair<int, string>>> table; // [[{}]]

    // HASH FUNCTION
    int hashFunction(int key)
    {
        return abs(key) % capacity;
    }

public:
    // CONSTRUCTOR
    HashMap()
    {
        this->capacity = 100;
        table.resize(100);
        this->count = 0;
    }
    HashMap(int capacity)
    {
        this->capacity = capacity;
        table.resize(capacity);
        this->count = 0;
    }

    // METHODS

    /// @brief Printing
    void print()
    {
        for (int i = 0; i < table.size(); i++)
        {
            cout << i << " : ";

            for (auto &bucket : table[i])
            {
                cout << "{" << bucket.first << " -> " << bucket.second << "} ";
            }

            cout << endl;
        }
    }

    // OPERATIONS

    /// @brief Add Item
    /// @param key
    /// @param value
    void insert(int key, string value)
    {
        int index = hashFunction(key);
        for (auto &bucket : table[index])
        {
            if (bucket.first == key)
            {
                bucket.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
        count++;
    }

    /// @brief Delete Item
    /// @param key
    bool remove(int key)
    {
        int index = hashFunction(key);

        auto &bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); it++)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                count--;
                return true;
            }
        }

        return false;
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
        return count;
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
    cout << mpp.size() << endl;
    return 0;
}