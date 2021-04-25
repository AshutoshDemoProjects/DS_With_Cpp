#include "Array.h"
bool ArrayList::isValidIndex(int indx)
{
    return (indx >= 0 && indx <= this->index);
}
void ArrayList::makeEmpty()
{
    for (int i = 0; i < this->size; i++)
        this->arr[i] = 0;
    this->size = 0;
    this->index = -1;
    delete[] this->arr;
    this->arr = nullptr;
}

ArrayList::ArrayList()
{
    this->size = 5;
    this->index = -1;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        arr[i] = 0;
}
ArrayList::ArrayList(int size)
{
    this->size = size;
    this->index = -1;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        arr[i] = 0;
}
ArrayList::ArrayList(const ArrayList &al)
{
    this->size = al.size;
    this->index = al.index;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->arr[i] = al.arr[i];
}
ArrayList ArrayList::operator=(const ArrayList &al)
{
    this->makeEmpty();
    this->size = al.size;
    this->index = al.index;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->arr[i] = al.arr[i];
    return *this;
}
ArrayList::~ArrayList()
{
    this->makeEmpty();
}
int ArrayList::lastIndex()
{
    return this->index;
}
int ArrayList::get(int indx)
{
    if (isValidIndex(indx))
        return arr[indx];
    else
        throw "Array index outOfBound";
}
int &ArrayList::operator[](int indx) //O(1)
{
    if (isValidIndex(indx)) //O(1)
        return arr[indx];
    else
        throw "Array index outOfBound";
}
bool ArrayList::isEmpty()
{
    return this->index == -1;
}
bool ArrayList::isFull()
{
    return this->index == this->size - 1;
}
void ArrayList::grow() //O(n)
{
    int *oldArr = this->arr;  //1
    int oldSize = this->size; //1
    //this->size = oldSize *2; //200%
    this->size = oldSize + (oldSize / 2); //150%//new size//1
    this->arr = new int[this->size];      //new array//1
    if (this->arr == nullptr)             //1
        throw "memory full...";
    for (int i = 0; i <= this->index; i++) //copy old data//n
        this->arr[i] = oldArr[i];          //1
    delete[] oldArr;                       //1
}
void ArrayList::insert(int data) //O(n)
{
    if (isFull()) //o(1)
    {
        this->grow(); //O(n)
    }
    ++this->index;                 //O(1)
    this->arr[this->index] = data; //O(1)
}
void ArrayList::insert(int data, int pos) //O(n)
{
    if (isValidIndex(pos - 1))
    {
        if (isFull())
        {
            this->grow();
        }
        for (int i = index; i >= pos - 1; i--) //O(n)
        {
            this->arr[i + 1] = this->arr[i];
        }
        this->arr[pos - 1] = data; //O(n)
        ++this->index;             //O(1)
    }
    else
    {
        throw "invalid Position";
    }
}
int ArrayList::remove() //O(1)
{
    if (!isEmpty())
    {
        int temp = this->arr[this->index];
        this->arr[this->index] = 0;
        this->index--;
        return temp;
    }
    else
    {
        throw "ArrayList is Empty con't perform delete operation...";
    }
}

int ArrayList::remove(int pos) //O(n)
{
    if (isValidIndex(pos - 1))
    {
        if (!isEmpty())
        {
            int temp = this->arr[pos - 1];
            for (int i = pos; i <= this->index; i++) //O(n)
                this->arr[i - 1] = this->arr[i];
            this->arr[this->index] = 0;
            this->index--;
            return temp;
        }
        else
        {
            throw "ArrayList is Empty con't perform delete operation...";
        }
    }
    else
    {
        throw "invalid position";
    }
}
std::ostream &operator<<(std::ostream &out, ArrayList al)
{
    if (!al.isEmpty())
    {
        for (int i = 0; i <= al.index; i++)
        {
            out << al[i] << ", ";
        }
    }
    else
        out << "ArrayList is empty";
    return out;
}
