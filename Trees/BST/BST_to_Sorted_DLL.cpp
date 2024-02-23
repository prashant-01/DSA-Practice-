#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data ;
    Node* left ;
    Node* right ;

    Node( int val ){
        this -> data = val;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

Node* insertNodeInBST( Node* root , int val){
    if( root == NULL ){
        Node* root = new Node( val );
        return root;
    }
    if( val < root->data ){
        root->left = insertNodeInBST( root->left , val );
    }
    if( val > root->data ){
        root->right = insertNodeInBST( root->right , val );
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cout << "Enter input";
    cin >> data;

    while(data != -1){
        root = insertNodeInBST(root , data);
        cin >> data;
        
    }
}

void convertBSTtoDLL( Node* root , Node* &head ){
    if( root == NULL )return;
    convertBSTtoDLL( root->right , head );

    // jo bhi right side se LL create hoke ayi h uska head current root node ke right se link krdo
    root->right = head;

    // if head is not NULL then Link that head also to current root node;
    if( head != NULL ){
        head->left = root;
    }
    head = root;

    convertBSTtoDLL( root->left , head );
}

void printDLL( Node* head ){
    cout << "Sorted Doubly Linked List " << endl;
    while( head != NULL){
        cout << head->data << " ";
        head = head->right;
    }
}

int main(){
    Node* root = NULL ; 
    Node* head = NULL;
    takeInput( root );
    convertBSTtoDLL( root , head );
    printDLL( head );
}

