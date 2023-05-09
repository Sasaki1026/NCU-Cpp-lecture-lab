#include <bits/stdc++.h>
using namespace std;
struct tree                       
{
   int data;                      
   struct tree *left;             
   struct tree *right;            
};
typedef struct tree treenode;     
typedef treenode *btree;          


btree create_btree(int*, int);
btree insert_node(btree, int);
void print_btree(btree);
btree remove_node(btree,int);
void levelOrder(btree);

int main()
{
   btree root = NULL;        
 

   int data[7] = { 25,20,50,10,22,40,60 };
   root = create_btree(data,7);   
   printf("data in tree: \n");
   print_btree(root); 
   root = remove_node(root,25);
   printf("data in tree: \n");
   print_btree(root);
   levelOrder(root);
   system("PAUSE");
   return 0;
}
 

btree create_btree(int *data,int len)
{
   btree root = NULL;            
   int i;
 
   for ( i = 0; i < len; i++ )   
      root = insert_node(root,data[i]);
   return root;
}
 

btree insert_node(btree root,int value)
{
 
   btree newnode;                 
   btree current;                
   btree back;                   
 
   
   newnode = ( btree ) malloc(sizeof(treenode));
   newnode->data = value;         
   newnode->left = NULL;         
   newnode->right = NULL;        
   if ( root == NULL )            
   {
      return newnode;             
   }
   else
   {
      current = root;          
      while ( current != NULL )
      {
         back = current;         
         if ( current->data < value )   
            current = current->right;     
         else
            current = current->left;     
      }
      if ( back->data < value )   
         back->right = newnode;    
      else
         back->left = newnode;   
   }
   return root;                   
}
 

void print_btree(btree root)
{
   btree ptr;
 
   ptr = root->left;
   printf("left:\n");
   while ( ptr != NULL )          
   {
      cout << ptr->data << "\n";  
      ptr = ptr->left;            
   }
   ptr = root->right;
   printf("right:\n");
   while ( ptr != NULL )         
   {
      cout << ptr->data << "\n";  
      ptr = ptr->right;           
   }
}

btree remove_node(btree root, int x)
{
    btree tmp = root;
    while(tmp->data != x && tmp){

        if(tmp->data > x)tmp = tmp->left;
        else tmp = tmp->right;
    }
    if(!tmp){
        cout << "ERROR: NULL Exception\n";
        return NULL;
    }
    btree newRoot = tmp->right,parent;
    while(newRoot->left){
        parent = newRoot;
        newRoot = newRoot->left;
    }
    tmp->data = newRoot->data;
    free(newRoot);
    parent->left = NULL;
    return root;
}

void levelOrder(btree root)
{
    cout << "Level Order:\n";
    queue<btree> q;
    q.push(root);
    while(!q.empty()){
        btree tmp = q.front();
        q.pop();
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
        cout << tmp->data << "\n";
    }
}

