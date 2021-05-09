#include "HashMapEntry.h"
HashMapEntry::HashMapEntry(int key, int value)
{
    this->key = key;
    this->value = value;
}
void HashMapEntry::setKey(int key)
{
    this->key = key;
}
int HashMapEntry::getKey()
{
    return this->key;
}
void HashMapEntry::setValue(int value)
{
    this->value = value;
}
int HashMapEntry::getValue()
{
    return this->value;
}
std::ostream &operator<<(std::ostream &out, HashMapEntry entry)
{
    out << entry.key << "=>" << entry.value;
    return out;
}