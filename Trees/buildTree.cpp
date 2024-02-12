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

/* Depth traversal , think of recursion */
Node* buildTree( Node* root ){
    int data;
    cout << "Enter data\n" ;
    cin >> data;
    if( data == -1 )return NULL ;
    root = new Node(data);
    root -> data = data;

    cout << "Enter leftnode data\n" ;
    root -> left = buildTree( root -> left );
    cout << "Enter rightnode data\n" ;
    root -> right = buildTree( root -> right );
    return root;
}

void depthOrderTraversal( Node* root ){
    cout << root->data << " ";
    if( root -> left == NULL )return;
    if( root -> right == NULL )return;
    levelOrderTraversal( root->left );
    levelOrderTraversal( root->right );
    return;
}
/* ****************************** */

/* Anything related to level order then think of queue */
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

void reverseLevelOrderTraversal( Node* root ){
    queue<Node*>q;
    stack<Node*>s;
    q.push(root);
    q.push(NULL);
    while( !q.empty() ){
        Node* temp = q.front();
        q.pop();
        if( temp == NULL ){
            if( !q.empty() ){
                s.push(NULL);
                q.push(NULL);
            }
        }
        else{
            s.push(temp);
            if( temp->left ){
                q.push( temp->right );
            }
            if( temp->right ){
                q.push( temp->left );
            }
        }
    }
    while( !s.empty() ){
        if( s.top() == NULL )cout << endl;
        else cout << s.top() -> data;
        s.pop();
    }
}

/* ****************************************** */



void inOrderTraversal( Node* root ){
    if( root == NULL )return;
    inOrderTraversal( root -> left );
    cout << root->data << " ";
    inOrderTraversal( root -> right );
}

void preOrderTraversal( Node* root ){
    if( root == NULL )return;
    cout << root->data << " ";
    preOrderTraversal( root -> left );
    preOrderTraversal( root -> right );
}

void postOrderTraversal( Node* root ){
    if( root == NULL )return;
    postOrderTraversal( root -> left );
    postOrderTraversal( root -> right );
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;
    // root = buildTree(root);
    root = buildTreeInLevelOrder( root );
    // levelOrderTraversal( root );
    // reverseLevelOrderTraversal(root);
    // inOrderTraversal(root);
    // preOrderTraversal(root);
    // postOrderTraversal(root);
}