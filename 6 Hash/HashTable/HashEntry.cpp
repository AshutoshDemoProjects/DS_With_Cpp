#include "HashEntry.h"
HashEntry::HashEntry(int key)
{
    this->key = key;
}
void HashEntry::setKey(int key)
{
    this->key = key;
}
int HashEntry::getKey()
{
    return this->key;
}
std::ostream &operator<<(std::ostream &out, HashEntry entry)
{
    out << entry.key;
    return out;
}