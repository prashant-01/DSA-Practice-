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

void verticleOrder( Node* root , map<int , vector<int>>&hash){
    // Level order traversal  will be used
    queue<pair<Node* , int>>q;
    q.push(make_pair(root , 0));
    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();
        hash[temp.second].push_back(temp.first->data);
        if( temp.first->left ){
            q.push( make_pair( temp.first->left , temp.second-1 ) );
        }
        if( temp.first->right ){
            q.push( make_pair( temp.first->right , temp.second+1 ) );
        }
    }
}

int main(){
    map<int , vector<int>>hash;
    map<int , vector<int>>::iterator itr;
    Node* root = NULL;
    root = buildLevelOrder(root);
    cout << "Verticle Order\n";
    verticleOrder( root , hash);
    for( itr = hash.begin() ; itr != hash.end() ; itr++ ){
        vector<int>ans = itr->second;
        for(int i=0 ; i<ans.size() ; i++){
            cout << ans[i] << " ";
        }
    }
}