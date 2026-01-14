// HASHMAP using C++
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int capacity = 0;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mpp;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // find in mpp if dont get return -1
        if (mpp.find(key) == mpp.end())
            return -1;

        // move that key to front
        auto it = mpp[key];
        int val = it->second;
        dll.erase(it);
        dll.push_front({key, val});
        mpp[key] = dll.begin();

        return val;
    }
};

int main()
{

    return 0;
}