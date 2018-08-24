#include <iostream>  
using namespace std;  

// Implementation of Binary Heap with min heap property  
void swap(int *x, int *y)  
{  
    int temp;  
    temp = *y;  
    *y = *x;  
    *x = temp;  
}  

// Implementatiton of a min heap  
class Heap{  
private:   
    int capacity; // Total capacity  
    int size; // Current size  
    int * arr;  
public:  
    Heap(int cap);  
    void printer();  
    void insertkey(int val);  
    void deletekey(int val);  
    int parent(int n);  
    int leftchild(int n);  
    int rightchild(int n);  
    int getmin(){ return arr[0]; }  
    void minHeapify(int i);  
    int extractmin();  
    void decreasekey(int i, int new_key);  
};  


Heap::Heap(int cap)  
{  
    this->capacity = cap;  
    this->size = 0;  
    this->arr = new int[cap]; // Dynamic allocation since inside a function  
}

int Heap::parent(int n) { return (n-1)/2; }  
int Heap::leftchild(int n) { return 2*n+1; }  
int Heap::rightchild(int n) { return 2*n+2; }  
void Heap::insertkey(int val)  
{  
    if(this->size == this->capacity) { cout<<"Cannot Insert"<<endl; return; }  
    size++;  
    int i = size-1;  
    arr[i] = val;  
    if (i == 0){ return; }  
    while( arr[i] < arr[parent(i)] )   
    {   
         swap(&arr[i], &arr[parent(i)]);  
         i = parent(i);   
    }   
}  
//Heapify the tree from root i  
//Assumes subtrees are already heapified  
//To be called in extractmin  
void Heap::minHeapify(int i)  
{     int smallest = i;  
    if( leftchild(i)< size && arr[i] > arr[leftchild(i)]) { smallest = leftchild(i); }  
    if( rightchild(i)< size && arr[smallest] > arr[rightchild(i)]) { smallest = rightchild(i); }  
    if(i != smallest) {  
         swap(&arr[i], &arr[smallest]);  
         minHeapify(smallest);  
    }  
}  
int Heap::extractmin()  
{  
    if (this->size <= 0) {cout<<"No element in heap, cannot extract "<<endl; return INT_MAX; }  
    else if(this->size == 1) { size--; return arr[0]; }  
    int min = arr[0];  
    arr[0] = arr[size-1];  
    size--;  
    minHeapify(0);  
    return min;  
}  
// Decreases the key of the element at index i to new_key  
// new_key should be smaller than arr[i]  
void Heap::decreasekey(int i, int new_key)  
{  
    arr[i] = new_key;  
    while(i != 0 && arr[i] < arr[parent(i)])  
    {  
         swap(&arr[i], &arr[parent(i)]);  
         i = parent(i);  
    }  
}  
// Delete key at index  
void Heap::deletekey(int index)  
{  
    decreasekey(index, INT_MIN);  // takes INT_MIN to root
    extractmin();  
}  
void Heap::printer()  
{  
    for(int i = 0; i<size; i++)  
    {  
         cout<<"i "<<i<<" -> "<<arr[i]<<endl;  
    }  
    return;  
} 

 
int main()  
{  
    Heap x(10);  
    x.insertkey(99);  
    x.insertkey(98);  
    x.insertkey(100);  
    x.insertkey(29);  
    x.insertkey(198);  
    x.insertkey(10);  
    x.deletekey(2);  
    x.printer();  
    return 1;  
}  
