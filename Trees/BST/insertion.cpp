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

void levelOrderTraversal( Node* root ){
    cout << "Printing tree " << endl;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        // handling enter press
        if( temp == NULL ){
            cout << endl ;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if( temp->left ){
                q.push( temp->left );
            }
            if( temp->right ){
                q.push( temp->right );
            }
        }
    }
}

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

int main(){
    Node* root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
}