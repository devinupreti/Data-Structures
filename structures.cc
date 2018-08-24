#include <iostream>

using namespace std;  

struct Dog {  
	int age;  
	char name[50];  
	char owner[100];  
	string type;  
};  

void myfunction(struct Dog d) {} // function with structure as argument  

int main()
{
	struct Dog d1;  
 	struct Dog d2;

 	strcpy(d1.name, "Shera");  
	strcpy(d2.name, "Jimmy");  
	d1.type = "Labrador";  

	// Structures can be used as any other variables to pass to other functions and to create structure pointers
	struct Dog * dp; // structure pointer  
 	dp = &d1;  
}