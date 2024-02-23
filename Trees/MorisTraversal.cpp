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


Node* find_pre( Node* current ){
    // How to find predecessor ? 
    // 1 baar left jao 
    Node* rightMost = current->left;
    // and tab tk right jate raho jab tk right ka right null na mil jaye
    while (rightMost->right != NULL && 
    // ye wali condition dubara isiliye lagai kyuki wha p NULL ki jgh temp link bhi hoskta h i.e 
    // pred ya to NULL ko point krta h ya current node ko to ini p while loop chalana h 
    rightMost->right != current){
        rightMost = rightMost->right;
    }
    return rightMost;
}

// This Moris for Inorder Traversal ( LNR )
void MorrisTraversal(Node* root){
    Node *current, *pre;
    if (root == NULL)return;
    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            // if left not exist then print root node and shift to right child
            cout << current->data << " ";
            current = current->right;
        }
        else {
            pre = find_pre( current );
            if (pre->right == NULL) {
                // If pre -> right is null it means no temp link has been created ... so create a temp link 
                // this link will help to get back to top without using stack
                pre->right = current;
                current = current->left;
            }
            else {
                // it means temp link already exist .. delete that link as it is not required now
                pre->right = NULL;
                // root print krdo
                cout << current->data << " ";
                // right child me shift krlo
                current = current->right;
            } 
        } 
    }
}

int main(){
    Node* root = NULL;
    root = buildTreeInLevelOrder( root );
    MorrisTraversal(root);
}