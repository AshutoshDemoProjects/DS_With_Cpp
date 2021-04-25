#include <iostream>
class ArrayList
{
    int *arr;
    int size;
    int index;
    bool isValidIndex(int indx);
    void makeEmpty();
    void grow();
public:
    ArrayList();
    ArrayList(int);
    ArrayList(const ArrayList &);
    ArrayList operator=(const ArrayList &);
    ~ArrayList();
    int lastIndex();
    int get(int);
    int &operator[](int);
    bool isEmpty();
    bool isFull();
    void insert(int);
    void insert(int, int);
    int remove();
    int remove(int);

    friend std::ostream &operator<<(std::ostream &, ArrayList);
};