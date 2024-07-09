#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int size;
        int rear;
        vector<int> arr;
    public:
        Heap(int x = 5){
            size = x;
            rear = 0;
            arr.resize(size);
        }
};

int heapify(int n, int index, vector<int> &arr){
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if(left < n && arr[largest] > arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] > arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(n, largest, arr);
    }
}
