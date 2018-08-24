//Implementation of queue using array

#include <iostream>  
using namespace std;  
// This is implementation of queue of size 10  
struct queue{  
	  int front = 0;  
	  int rear = 9;  
	  int array[10];  
	  int size = 0;  

	  void enqueue(int val){  
             if(size == 10) { return; }  
             rear = (rear+1) % 10;  
             array[rear] = val;  
             size = size + 1 ;  
             cout<<"Rear after enqueue : "<<rear<<endl;  
	  }

	  int dequeue(){  
	        if(size == 0) { return 0; }  
	        int x = array[front];  
	        front = (front+1) % 10;  
	        size = size - 1 ;  
	        cout<<"Front after dequeue : "<<front<<endl;   
	        return x;  
	  }  
};  


int main()  
{       
	  struct queue x;  
	  x.enqueue(1);  
	  x.enqueue(10);  
	  x.enqueue(20);  
	  x.enqueue(30);  
	  x.enqueue(40);  
	  x.enqueue(50);  
	  x.enqueue(1);  
	  x.dequeue();  
	  x.dequeue();  
	  x.dequeue();  
	  x.enqueue(20);  
	  x.enqueue(30);  
	  x.dequeue();  
	  x.dequeue();  
	  x.dequeue();  
	  x.dequeue();  
	  return 0;  
}  