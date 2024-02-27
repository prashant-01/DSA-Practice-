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
vector<Node*>inorder;
void inOrderTraversal( Node* root ){
    if( root == NULL )return;
    inOrderTraversal( root -> left );
    inorder.push_back(root);
    inOrderTraversal( root -> right );
} 

void convertBSTtoLL( Node* &head ){
    for(int i=0 ; i<inorder.size() ; i++){
        inorder[i]->left=NULL;
        if(i == inorder.size()-1){
            inorder[i]->right=NULL;
        }
        else inorder[i]->right=inorder[i+1];
    }
    head = inorder[0];
}
void printLL( Node* head ){
    cout << "Sorted Linked List " << endl;
    while( head != NULL){
        cout << head->data << " ";
        head = head->right;
    }
}

int main(){
    Node* root = NULL ; 
    Node* head = NULL;
    takeInput( root );
    inOrderTraversal(root);
    convertBSTtoLL( head );
    printLL( head );
}