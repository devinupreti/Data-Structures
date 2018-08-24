#include <iostream>

using namespace std;  

void modref( int & x ) { x = 0; } // call by reference using reference  

void modp (int * x ) { *x = 1; } // call by reference using pointer  

void nomod (int x ) { x = 30; } // call by value  

int main()  
{    
	int y = 20;  
	cout<<y<<endl; // 20  

	modref(y);  
	cout<<y<<endl; // 0  
	
	modp(&y);  
	cout<<y<<endl; // 1  
	
	nomod(y);  
	cout<<y<<endl; // 1  
}  