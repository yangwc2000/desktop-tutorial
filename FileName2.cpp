#include <iostream>

template <typename T>
class SimpleVector 
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

    void resize() 
    {
        int newCapacity = currentCapacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    SimpleVector() : currentSize(0), currentCapacity(10) 
    {
        data = new T[currentCapacity];
    }

    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) 
    {
        data = new T[currentCapacity];
    }

    ~SimpleVector()
    {
        delete[] data;
    }

    void push_back(const T& value) 
    {
        if (currentSize >= currentCapacity) 
        {
            return;
        }
        data[currentSize++] = value;
    }

    void pop_back() 
    {
        if (currentSize > 0) 
        {
            --currentSize;
        }
    }

    int size() const
    {
        return currentSize;
    }

    int capacity() const
    {
        return currentCapacity;
    }
};

int main() 
{
    SimpleVector<int> vec(5);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Size: " << vec.size() << "\n";         
    std::cout << "Capacity: " << vec.capacity() << "\n"; 

    vec.pop_back();
    std::cout << "Size after pop: " << vec.size() << "\n"; 

    return 0;
}
