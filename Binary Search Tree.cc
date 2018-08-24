 #include <iostream>  
 using namespace std;  
 // Implementation of Binary Tree in C++  
 struct tree{  
      int data;  
      struct tree * left;  
      struct tree * right;  
 }; 

 struct tree * NewNode(int val)  
 {  
      struct tree * node = (struct tree *)malloc(sizeof(struct tree));  
      // struct tree * node;  
      //struct tree NewNode;  
      //node = &NewNode;  
      node->data = val;  
      node->left = node->right = NULL;  
      return node;  
 } 

 struct tree * insertNode(struct tree * t, int val)  
 {  
      if(t == NULL) { return NewNode(val); }  
      if(t->data > val){ t->left = insertNode(t->left, val); }  
      else { t->right = insertNode(t->right, val); }  
      return t;  
 }  

 struct tree * inorderSuccessor(struct tree* t)  
 {  
   struct tree * current = t;  
   while (current->left != NULL) { current = current->left; }  
   return current;  
 }  

 struct tree * Delete(struct tree * t, int target)  
 {  
      if (t == NULL) { return t; }  
      if (t->data > target)   
      { t->left = Delete(t->left, target); }  
      else if (t->data < target)  
      { t->right = Delete(t->right, target); }  
      else  
      {       
           if(t->left == t->right && t->right == NULL) // This block can be avoided as the next block takes care of this case.  
           {  
                struct tree * temp;  
                temp = NULL;  
                free(t);  
                return temp;  
           }  
           else if(t->left == NULL)  
           {  
                struct tree * temp = t->right;  
                free(t);  
                return temp;  
           }  
           else if (t->right == NULL)  
           {  
                struct tree * temp = t->left;  
                free(t);  
                return temp;  
           }  
           else  
           {  
                // This is when t has two children  
                struct tree * temp = inorderSuccessor(t->right);  
                t->data = temp->data;  
                t->right = Delete(t->right, temp->data); // This is to delete inorder successor in right subtree  
           }  
      }   
      return t;  
 } 

  
 int main()  
 {            
      struct tree * root = NULL;   
      root = insertNode(root,10);  
      insertNode(root,20);  
      insertNode(root,30);  
      insertNode(root,40);  
      insertNode(root,5);  
      insertNode(root,15);  
      /* The generated tree will be of the structure :  
                          10  
                         /  \  
                        5    20  
                            /  \  
                           15  30  
                                 \  
                                 40  
      */  
      Delete(root,5);  
      /* The generated tree will be of the structure :  
                          10  
                            \  
                             20  
                            /  \  
                           15  30  
                                 \  
                                 40  
      */  
      Delete(root,20);  
      /* The generated tree will be of the structure :  
                          10  
                            \  
                             30  
                            /  \  
                           15   40  
      */  
      return 1;  
 } 