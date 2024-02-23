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
int ans;

void kthLargest(Node* root , int &k){
    if( root == NULL )return;
    kthLargest( root->right , k );
    k--;
    if( k==0 ){
        ans = root->data;
        return;
    }
    kthLargest( root->left , k );
    return;
}
int main(){
    Node* root = NULL;
    takeInput( root );
    int k;
    cout << "Enter k value " << endl;
    cin >> k;
    kthLargest( root , k);
    cout << ans;
}