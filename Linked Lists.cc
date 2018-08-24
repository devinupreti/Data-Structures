#include <string>  
#include <iostream>  

using namespace std;  

struct LLNode 
{  
      int data;  
      struct LLNode * pointer; // pointer that points to Node in Linked List  
};   

void printlist(struct LLNode * head) 
{  
      int i = 1;  
      while (head)  
      {  
           cout<<head->data<<"    Node : "<<i<<endl;  
           i++;  
           head = head->pointer;  
      }  
}  


int main()  
{  
      struct LLNode *l1 = new struct LLNode;  
      struct LLNode *l2 = new struct LLNode;  
      
      struct LLNode *head = l1;  
      
      head->data = 2;  
      l2->data = 4;  
      l1->pointer = l2; // l1 points to l2   
      l2->pointer = null;  
      
      cout<<l1->pointer->data<<endl; // print data value of node that l1 points to  
      cout<<l1->data<<endl;  
      
      delete l1;  
      delete l2;  
      return 1;  
}  