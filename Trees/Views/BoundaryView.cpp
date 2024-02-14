#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildLevelOrder( Node* root ){
    queue<Node*>q;
    int data;
    cout << "Enter root data\n";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while( !q.empty() ){
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left node data\n";
        cin >> data;
        if( data != -1 ){
            temp -> left = new Node( data );
            q.push( temp -> left );
        }

        cout << "Enter right node data\n";
        cin >> data;
        if( data != -1 ){
            temp -> right = new Node( data );
            q.push( temp -> right );
        }
    }
    return root;
}

void leftBoundary( Node* root , vector<int>&ans){
    if( root == NULL || (root->left == NULL && root->right == NULL) )return;
    ans.push_back(root->data);
    if( root->left ){
        leftBoundary( root->left , ans );
    }
    else{
        leftBoundary( root->right , ans );
    }
    return;
}

void leafNodes( Node* root , vector<int>&ans){
    if( root == NULL )return;
    if( root->left == NULL && root->right == NULL ){
        ans.push_back( root->data );
        return;
    }
    leafNodes( root->left , ans );
    leafNodes( root->right , ans );
    return;
}

void rightBoundary( Node* root , vector<int>&ans){
    if( root == NULL || (root->left == NULL && root->right == NULL) )return;
    ans.push_back(root->data);
    if( root->left ){
        leftBoundary( root->left , ans );
    }
    else{
        leftBoundary( root->right , ans );
    }
    return;
}

void boundaryView( Node* root ){
    vector<int>ans , ansRight;
    ans.push_back(root->data);

    // Print left boundary except leaf node
    leftBoundary( root->left , ans );

    // Print all leaf nodes
    leafNodes( root , ans );

    // Print right boundary except leaf node
    rightBoundary( root->right , ansRight );
    for(int i=ansRight.size()-1 ; i>=0 ; i--){
        ans.push_back(ansRight[i]);
    }
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return;
}

int main(){
    Node* root = NULL;
    root = buildLevelOrder(root);
    cout << "Boundary View\n";
    boundaryView( root );
}