// Stack implementation using array
#include <iostream>   

using namespace std;   

// This is implementation of stack of size 10   
struct stack{   
	int top = -1;   
	
	void push(int val)   
	{      
	   if(top<9)   
	   { top = top + 1;   
	   cout<<"top after push: "<<top<<" -> value : "<<val<<endl;    
	   arr[top] = val; }   
	   else   
	   { cout<<"Stack Overflow, could not insert "<<val<<" in stack"<<endl; }   
	}   
	
	int pop()   
	{   
	   if(top<0) { cout<<"Stack Underflow"; return 0; }   
	   int x = arr[top];   
	   top = top - 1;    
	   return x;   
	}   
	
	int arr[10]; // maximum size for stack is 100   
};  


int main()   
{   
	struct stack x;   
	x.push(1);   
	x.push(2);   
	x.push(3);   
	x.push(4);   
	x.push(5);   
	x.push(6);   
	x.push(7);   
	x.push(8);   
	x.push(9);   
	x.push(10);   
	x.push(20);   
	x.push(30);   
	cout<<"Value popped out : "<<x.pop()<<endl;  
	cout<<"Value popped out : "<<x.pop()<<endl;  
	cout<<"Value popped out : "<<x.pop()<<endl;   
}  