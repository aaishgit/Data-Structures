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
    node* parent;
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
    p->parent=NULL;
    while (x!=NULL) {
        y=x;
        if(x->data<p->data){
            x=x->right;
        }
        else{
            x=x->left;
        }
    }
   // x=p;
    p->parent=y;
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
        //dupliinsert(a[i]);
        insert(a[i]);
    }
    return 0;
}

int inorder(node* a){
    if(a!=NULL){
        inorder(a->left);
        if (a->data==root->data) {
            cout<<a->data<<" "<<"parent is NULL"<<endl;
        }
        else{
        cout<<a->data<<" "<<"parent is "<<a->parent->data<<endl;
        }
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

int max(node *x){
    while(x->right!=NULL){
        x=x->right;
    }
    return x->data;
}

int min(node *x){
    while(x->left!=NULL){
        x=x->left;
    }
    return x->data;
}

node* min_node(node *x){
    while(x->left!=NULL){
        x=x->left;
    }
    return x;
}

//bst search recursively
node* bstsearch(int ele,node* x){
    if (x==NULL) {
        return NULL;
    }
    else if(x->data==ele){
        return x;
    }
    else if(ele>x->data){
        return bstsearch(ele,x->right);
    }
    else{
        return bstsearch(ele,x->left);
    }
}

int successor(int ele){
    node* p=bstsearch(ele,root);
    if(p==NULL){
        cout<<"Incorrect element";
        return -1;
    }
    else{
        if (p->right!=NULL) {
            return min(p->right);
        }
        else{
            node* y=p->parent;
            while(y!=NULL&&p==y->right){
                p=y;
                y=y->parent;
            }
            if (y==NULL) {
                cout<<"No successor";
                return -1;
            }
            else{
                return y->data;
            }
        }
    }
}

node* successor_node(int ele){
    node* p=bstsearch(ele,root);
    if(p==NULL){
        cout<<"Incorrect element";
        return NULL;
    }
    else{
        if (p->right!=NULL) {
            return min_node(p->right);
        }
        else{
            node* y=p->parent;
            while(y!=NULL&&p==y->right){
                p=y;
                y=y->parent;
            }
            if (y==NULL) {
                cout<<"No successor";
                return NULL;
            }
            else{
                return y;
            }
        }
    }
}


int bstdelete(int ele){
    node* x=bstsearch(ele,root);
    node* y;
    if(x->left==NULL&&x->right==NULL){
        y=x->parent;
        if (x->data>y->data) {
            y->right=NULL;
        }
        else{
            y->left=NULL;
        }
    }
    else if(x->left==NULL){
        y=x->parent;
        if (x->data>y->data) {
            y->right=x->right;
            y->right->parent=y;
        }
        else{
            y->left=x->right;
            y->left->parent=y;
        }
    }
    else if(x->right==NULL){
        y=x->parent;
        if (x->data>y->data) {
            y->right=x->left;
            y->right->parent=y;
        }
        else{
            y->left=x->left;
            y->left->parent=y;
        }
    }
    else{
        y=x->parent;
        node* p=successor_node(ele);
        if(p==x->right){
            p->left=x->left;
            x->left->parent=p;
            if (x->data>y->data) {
                y->right=p;
                y->right->parent=y;
            }
            else{
                y->left=p;
                y->left->parent=y;
            }
        }
        else{
            bstdelete(p->data);
            p->left=x->left;
            p->right=x->right;
            x->left->parent=p;
            x->right->parent=p;
            if (x->data>y->data) {
                y->right=p;
                y->right->parent=y;
            }
            else{
                y->left=p;
                y->left->parent=y;
            }
        }
    }
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
    cout<<"Maximum element is "<<max(root)<<endl;
    cout<<"Minimum element is "<<min(root)<<endl;
    int ele;
    /*cout<<"Enter element you want to search"<<endl;
    cin>>ele;
    node* p=bstsearch(ele,root);
    if(p==NULL){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found"<<endl;
    }
    cout<<"Enter element you want successor of"<<endl;
    cin>>ele;
    int z=successor(ele);
    if(z!=-1){
        cout<<"Successor is "<<z<<endl;
    }*/
    cout<<"Enter element you want to delete"<<endl;
    cin>>ele;
    bstdelete(ele);
    inorder(root);
    return 0;
}
