#include "HashMapTable.h"
int HashMapTable::hashFunc(int key)
{
    return key % this->size;
}

HashMapTable::HashMapTable(int size = 10)
{
    this->size = size;
    this->arr = new HashMapEntry *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->arr[i] = nullptr;
    }
}

void HashMapTable::put(int key, int value)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr && this->arr[index]->getKey() != key)
    {
        index = hashFunc(index + 1);
    }
    if (this->arr[index] != nullptr)
        delete this->arr[index];
    this->arr[index] = new HashMapEntry(key, value);
}
HashMapEntry &HashMapTable::search(int key)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr && this->arr[index]->getKey() != key)
    {
        index = hashFunc(index + 1);
    }
    if (this->arr[index] == nullptr)
        throw "Key not found";
    else
        return *this->arr[index];
}
HashMapEntry &HashMapTable::remove(int key)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr)
    {
        if (this->arr[index]->getKey() == key)
            break;
        index = hashFunc(index + 1);
    }
    if (this->arr[index] == nullptr)
        throw "Key not found";
    else
    {
        HashMapEntry *temp = this->arr[index];
        delete this->arr[index];
        return *temp;
    }
}
HashMapTable::~HashMapTable()
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] != nullptr)
        {
            delete this->arr[i];
            delete[] this->arr;
        }
    }
}