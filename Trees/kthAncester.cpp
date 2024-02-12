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

// using vector
bool solve( Node* root , int val , vector<int>&v ){
    if( root == NULL )return false;
    if( root->data == val )return true;

    bool checkLeft = solve( root->left , val , v );
    bool checkRight = solve( root->right , val , v );

    if( checkLeft || checkRight ){
        v.push_back( root->data );
        return true;
    }
    return false;
}

// without using vector
bool solve1( Node* root , int &k , int node , int &ans ){
    if( root == NULL )return false;
    if( root->data == node )return true;
    
    bool leftCheck = solve1( root->left , k , node , ans );
    bool rightCheck = solve1( root->right , k , node , ans );
    
    if( leftCheck || rightCheck ){
        k--;
        if( k == 0 ){
            ans = root->data;
        }
        return true;
    }
    return false;
}


int main(){
    Node* root = NULL;
    root = buildTreeInLevelOrder( root );
    int val , k ;vector<int>v;
    cout << "Enter k value" << endl;
    cin >> k;
    cout << "Enter node value" << endl;
    cin >> val;
    
    if(solve( root , val , v )){
        if( k > v.size() )cout << "Ancestor not found!" << endl;
        else{
            cout << "Here is the Kth ancestor " << v[k-1] ;
        }
    }else{
        cout << "Node not found!";
    }
}