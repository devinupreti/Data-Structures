 #include <iostream>  
 using namespace std;  
 // Implementation of Binary Tree in C++  
 
 struct tree{  
      int data;  
      struct tree * left;  
      struct tree * right;  
 };  
 
 int main()  
 {            
      struct tree *root;  
      struct tree A;  
      struct tree B;  
      struct tree C;  
      root = &A;  
      root->left = &B;  
      root->right = &C;  
      root->data = 10;  
      B.data = 20;  
      C.data = 30;  
      cout<<A.data<<endl;     // 10  
      cout<<root->left->data<<endl; // 20  
      cout<<root->right->data<<endl; // 30  
 } 