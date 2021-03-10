#include<iostream>
#include<queue>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
}*temp;

node* newnode(int data)
{
    temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root,int data)
{
   if(root==NULL)
   root = newnode(data);
   
  else if(data<=root->data)  root->left = insert(root->left,data);
   
   else  root->right = insert(root->right,data);
    return root;
}


void levelorder(node* root){
    
    if(root==NULL) return;
    else {
        
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            
            node* current = q.front();
            cout<<current->data;
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
            q.pop();
        }
    }
}


int main()
{
   node* root = NULL;
   root =  insert(root,7);
   root =  insert(root,8);
   root =   insert(root,6);
   cout<<endl<<"LEVEL-ORDER TRAVERSAL : ";
   levelorder(root);
    return 0;
}
