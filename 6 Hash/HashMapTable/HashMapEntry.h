#include <iostream>
class HashMapEntry
{
    int key;
    int value;

public:
    HashMapEntry(int, int);
    void setKey(int);
    int getKey();
    void setValue(int);
    int getValue();
    friend std::ostream &operator<<(std::ostream &, HashMapEntry);
};