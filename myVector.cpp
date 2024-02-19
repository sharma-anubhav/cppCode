#include <iostream>
using namespace std;

template <typename T>
class myVector
{

    T *arr;
    int capacity, current;

public:
    myVector()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push_back(T data)
    {
        if (current == capacity)
        {
            T *temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = 2 * capacity;
        }
        arr[current] = data;
        current++;
    }

    T operator[](int a)
    {
        if (a > (capacity - 1))
        {
            cout << "Index out of bounds";
            exit(0);
        }
        return arr[a];
    }
};

int main()
{

    return 0;
}