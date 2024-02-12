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

bool findHeight( Node* root , int val , int &ans ){
    if( root == NULL )return false;
    if( root->data == val )return true;

    bool checkLeft = findHeight( root->left , val , ans );
    bool checkRight = findHeight( root->right , val , ans );

    if( checkLeft || checkRight ){
        ans++;
        return true;
    }
    return false;
}

int main(){
    Node* root = NULL;
    root = buildTreeInLevelOrder( root );
    int ans = 0 , val;
    cout << "Enter node value to be searched!" << endl;
    cin >> val;

    if( findHeight( root , val , ans ) )cout << ans;
    else cout << "Node not found!";
}