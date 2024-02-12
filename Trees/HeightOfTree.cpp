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

int findHeight( Node* root ){
    if( root == NULL )return 0;
    int leftHeight = findHeight( root->left );
    int rightHeight = findHeight( root->right );
    int rootHeight = 1 + max( leftHeight , rightHeight );
    return rootHeight;
}

int main(){
    Node* root = NULL;
    root = buildTreeInLevelOrder( root );
    // depth of a tree is 1 more than it's height
    cout << "Depth of tree " << findHeight(root) << endl;
    cout << "Height of tree " << findHeight(root)-1;
}