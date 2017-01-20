//  Inserting in a Binary search tree , inorder ,preorder , postorder, max , min and removing duplicate elements from an array using bst
//  prog2.cpp
//  
//
//  Created by Aaish Sindwani on 19/01/17.
//
//
using namespace std;
#include <iostream>
struct node{
    int data;
    node* left;
    node* right;
};

node* root=NULL;
int n;
//BST insertion
int insert(int ele){
    node* y=NULL;
    node* x=root;
    node* p=new node();
    p->data=ele;
    p->left=NULL;
    p->right=NULL;
    while (x!=NULL) {
        y=x;
        if(x->data<p->data){
            x=x->right;
        }
        else{
            x=x->left;
        }
    }
    x=p;
    
    if (y==NULL) {
        root=p;
    }
    else if(p->data>y->data){
        y->right=p;
    }
    else{
        y->left=p;
    }
    //cout<<x->data<<" ";
    return 0;
}
//removing duplicate elements from an array using bst
int dupliinsert(int ele){
    node* y=NULL;
    node* x=root;
    node* p=new node();
    p->data=ele;
    p->left=NULL;
    p->right=NULL;
    while (x!=NULL) {
        y=x;
        if(x->data<p->data){
            x=x->right;
        }
        else if(x->data>p->data){
            x=x->left;
        }
        else{
            return 0;
        }
    }
    x=p;
    
    if (y==NULL) {
        root=p;
    }
    else if(p->data>y->data){
        y->right=p;
    }
    else{
        y->left=p;
    }
    //cout<<x->data<<" ";
    return 0;
}


int buildtree(int *a,int n){
    for(int i=0;i<n;i++){
        dupliinsert(a[i]);
        //insert(a[i]);
    }
    return 0;
}

int inorder(node* a){
    if(a!=NULL){
        inorder(a->left);
        cout<<a->data<<" ";
        inorder(a->right);
    }
    else{
        return 0;
    }
}

int preorder(node* a){
    if (a!=NULL) {
        cout<<a->data<<" ";
        preorder(a->left);
        preorder(a->right);
    }
    else{
        return 0;
    }

}

int postorder(node* a){
    if (a!=NULL) {
        preorder(a->left);
        preorder(a->right);
        cout<<a->data<<" ";
    }
    else{
        return 0;
    }
    
}

int max(){
    node *x=root;
    while(x->right!=NULL){
        x=x->right;
    }
    return x->data;
}

int min(){
    node *x=root;
    while(x->left!=NULL){
        x=x->left;
    }
    return x->data;
}


int main(){
    cout<<"No of elements"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildtree(a,n);
    //cout<<root->data<<" "<<root->left->data;//<<" "<<root->right->data;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Maximum element is "<<max()<<endl;
    cout<<"Minimum element is "<<min();
    return 0;
}
