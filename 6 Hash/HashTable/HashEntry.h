#include <iostream>
class HashEntry
{
    int key;

public:
    HashEntry(int);
    void setKey(int);
    int getKey();
    friend std::ostream &operator<<(std::ostream &, HashEntry);
};