#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[101];
    int size;

    Heap() { size = 0; }

    void insert(int value)
    {
        // value insert karo end me
        size = size + 1;
        int index = size;
        arr[size] = value;

        // value ko right position me leke jao
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int deleted()
    {
        int ans = arr[1];
        // replace root node value with last node
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left < size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right < size && arr[largest] < arr[right])
            {
                largest = right;
            }
            if (index == largest)
            {
                break;
            }
            else
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
        }
        return ans;
    }
};

int main()
{
    // Heap insert and delete using the class created
    Heap h;
    //   h.arr[0] = -1;
    //   h.arr[1] = 100;
    //   h.arr[2] = 50;
    //   h.arr[3] = 60;
    //   h.arr[4] = 40;
    //   h.arr[5] = 45;
    //   h.size = 5;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout << "printing the heap " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
}