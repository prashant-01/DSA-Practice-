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

Node* buildTreeInLevelOrder( Node* root ){
    queue<Node*>q;
    cout << "Enter root data\n";
    int data; cin>>data;
    root = new Node(data);
    q.push(root);

    while( !q.empty() ){
        Node* temp = q.front();
        q.pop();
        cout << "Enter data for left node\n";
        int leftdata; cin >> leftdata;
        if( leftdata != -1 ){
            temp->left= new Node( leftdata );
            q.push( temp->left );
        }

        cout << "Enter data for right node\n";
        int rightdata; cin >> rightdata;
        if( rightdata != -1 ){
            temp->right= new Node( rightdata );
            q.push( temp->right );
        }
    }
    return root;
}

void levelOrderTraversal( Node* root , map<int , int>&hash ){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    hash[ root->data ] = NULL;
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
            // cout << temp->data << " ";
            if( temp->left ){
                hash[ temp->left->data ] = temp->data; 
                q.push( temp->left );
            }
            if( temp->right ){
                hash[ temp->right->data ] = temp->data; 
                q.push( temp->right );
            }
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTreeInLevelOrder( root );
    map<int , int>hash;
    levelOrderTraversal( root , hash );
    
}