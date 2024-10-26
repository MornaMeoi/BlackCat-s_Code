//Task: https://leetcode.com/problems/insert-delete-getrandom-o1/
//Difficulty: Medium
#include <bits/stdc++.h>
using namespace std;

#define ALLOCATED -1094795586
#define START_HASH_SIZE 256
class RandomizedSet {
public:
    RandomizedSet() : _hash_capacity{START_HASH_SIZE}
    {
        _data = new int[_hash_capacity];
    }
    
    ~RandomizedSet()
    {
        delete[] _data;
    }

    bool insert(int val)
    {
        if(_data[hash_f(val)] == val)
            return false;
        else
        {
            while(_data[hash_f(val)] != ALLOCATED)
                rehash();
            _data[hash_f(val)] = val; 
            return true;
        }
    }
    
    bool remove(int val)
    {
        if(_data[hash_f(val)] == val)
        {
            _data[hash_f(val)] = ALLOCATED;
            return true;
        }
        else
            return false;
    }
    
    int getRandom()
    {
        size_t rand_idx = hash_f(rand());
        while(_data[rand_idx] == ALLOCATED)
            rand_idx = hash_f(rand());
        return _data[rand_idx];
    }
    void print_set()
    {
        for(int i = 0; i < _hash_capacity; ++i)
            cout << _data[i] << ' ';
        cout << endl;
    }

private:
    int* _data;
    size_t _hash_capacity;

    size_t hash_f(int val)
    {
        return _hash_capacity / 2 + val % (_hash_capacity / 2);
    }
    void rehash()
    {
        _hash_capacity *= 2;
        int *temp_data = new int[_hash_capacity];
        for(size_t i = 1; i < _hash_capacity / 2; ++i)
            if(_data[i] != ALLOCATED)
                temp_data[hash_f(_data[i])] = _data[i];
        delete[] _data;
        _data = temp_data;
        temp_data = nullptr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    /* test_1
    RandomizedSet randomizedSet;
    cout << randomizedSet.insert(1) << endl; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << randomizedSet.remove(2) << endl; // Returns false as 2 does not exist in the set.
    cout << randomizedSet.insert(2) << endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << randomizedSet.getRandom() << endl; // getRandom() should return either 1 or 2 randomly.
    randomizedSet.print_set();
    cout << randomizedSet.remove(1) << endl; // Removes 1 from the set, returns true. Set now contains [2].
    cout << randomizedSet.insert(2) << endl; // 2 was already in the set, so return false.
    cout << randomizedSet.getRandom() << endl; // Since 2 is the only number in the set, getRandom() will always return 2.*/

    RandomizedSet randomizedSet;
    cout << randomizedSet.insert(2) << endl;
    randomizedSet.print_set();
    cout << randomizedSet.insert(0) << endl;
    randomizedSet.print_set();
    cout << randomizedSet.getRandom() << endl;
    cout << randomizedSet.insert(-2) << endl;
    cout << randomizedSet.insert(-2) << endl;
    cout << randomizedSet.remove(3) << endl;
    cout << randomizedSet.remove(3) << endl;
    cout << randomizedSet.remove(1) << endl;
    cout << randomizedSet.insert(-3) << endl;
    cout << randomizedSet.remove(3) << endl;
    cout << randomizedSet.getRandom() << endl;
    randomizedSet.print_set();
    cout << randomizedSet.insert(-3) << endl;
    cout << randomizedSet.remove(-1) << endl;
    cout << randomizedSet.remove(3) << endl;
    cout << randomizedSet.insert(1) << endl;
    cout << randomizedSet.insert(1) << endl;
    cout << randomizedSet.insert(1) << endl;
    randomizedSet.print_set();
    cout << randomizedSet.insert(-2) << endl;
    cout << randomizedSet.insert(2) << endl;
    cout << randomizedSet.insert(-3) << endl;
    randomizedSet.print_set();
    return 0;
}