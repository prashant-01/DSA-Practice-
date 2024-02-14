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

void rightView( Node* root ){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    bool flag=false;
    cout << root->data << " ";
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if( temp == NULL ){
            flag = true;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            if( flag ){
                cout << temp->data << " ";
                flag = false;
            }
            if( temp->right ){
                q.push(temp->right);
            }
            if( temp->left ){
                q.push(temp->left);
            }
        }
    }
}

int main(){
    map<int , vector<int>>hash;
    map<int , vector<int>>::iterator itr;
    Node* root = NULL;
    root = buildLevelOrder(root);
    cout << "Left View\n";
    rightView( root );
}