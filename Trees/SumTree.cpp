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

bool isLeaf( Node* node ){
    return ( node != NULL && node->left == NULL && node->right == NULL );
}

bool isSumTree( Node* root ){
    if( root == NULL || isLeaf( root ) )return true ;

    bool checkLeft = isSumTree( root->left );
    bool checkRight = isSumTree( root->right );
    if( checkLeft && checkRight ){
        int leftSum , rightSum;

        if( root->left == NULL )leftSum=0;
        else if( isLeaf( root->left ) )leftSum=root->left->data;
        else leftSum = 2 * root->left->data;

        if( root->right == NULL )rightSum=0;
        else if( isLeaf( root->right ) )rightSum=root->right->data;
        else rightSum = 2 * root->right->data;

        return root->data == (leftSum + rightSum) ;
    }
    return false;
}

int main(){
    Node* root;
    root = buildTreeInLevelOrder(root);
    cout << isSumTree(root);
}