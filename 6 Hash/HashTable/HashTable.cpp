#include "HashEntry.h"
#include "HashTable.h"
int HashTable::hashFunc(int key)
{
    return key % this->size;
}

HashTable::HashTable(int size = 10)
{
    this->size = size;
    this->arr = new HashEntry *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->arr[i] = nullptr;
    }
}

void HashTable::put(int key)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr && this->arr[index]->getKey() != key)
    {
        index = hashFunc(index + 1);
    }
    if (this->arr[index] != nullptr)
        delete this->arr[index];
    this->arr[index] = new HashEntry(key);
}
HashEntry *HashTable::search(int key)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr && this->arr[index]->getKey() != key)
    {
        index = hashFunc(index + 1);
    }
    if (this->arr[index] == nullptr)
        return nullptr;
    else
        return this->arr[index];
}
HashEntry *HashTable::remove(int key)
{
    int index = hashFunc(key);
    while (this->arr[index] != nullptr)
    {
        if (this->arr[index]->getKey() == key)
            break;
        index = hashFunc(index + 1);
    }
    if (this->arr[index] == nullptr)
        return nullptr;
    else
    {
        HashEntry *temp = this->arr[index];
        delete this->arr[index];
        return temp;
    }
}
HashTable::~HashTable()
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