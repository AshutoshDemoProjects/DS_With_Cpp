#include "HashEntry.h"
class HashTable
{
    HashEntry **arr;
    int size;
    int hashFunc(int);

public:
    HashTable(int = 10);
    void put(int);
    HashEntry *search(int);
    HashEntry *remove(int);
    ~HashTable();
};