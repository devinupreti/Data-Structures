#include <iostream>

using namespace std;  

int * myfunction(int *p)   
{  
	p[0] = 10;  
	return p;  
}


int main()   
{  
	int array[] = { 1,2,3,4,5 };  
	int * p2;  
	p2 = myfunction(array);  
	for(int i = 0; i < 5; i++)  
		{  cout<<"*(p2 + "<<i<<") : "<<*(p2+i)<<endl;  }  
	return 1;  
}  