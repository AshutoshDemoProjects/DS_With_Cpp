#include "HashMapEntry.h"
class HashMapTable
{
    HashMapEntry **arr;
    int size;
    int hashFunc(int);

public:
    HashMapTable(int = 10);
    void put(int, int);
    HashMapEntry &search(int);
    HashMapEntry &remove(int);
    ~HashMapTable();
};