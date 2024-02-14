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

void zigZagView( Node* root ){
    deque<Node*>dq;
    int level=0;
    dq.push_back( root );
    dq.push_back(NULL);
    while( !dq.empty() ){
        Node* temp;
        if( level % 2 == 0 ){
            temp = dq.front();
            dq.pop_front();

            if( temp == NULL ){
                level++;
                if( !dq.empty() ){
                    dq.push_front(NULL);
                }
            }
            else{
                cout << temp->data << " ";
                if( temp->left ){
                    dq.push_back( temp->left );
                }
                if( temp->right ){
                    dq.push_back( temp->right );
                }
            }
        }
        else{
            temp = dq.back();
            dq.pop_back();

            if( temp == NULL ){
                level++;
                if( !dq.empty() ){
                    dq.push_back(NULL);
                }
            }
            else{
                cout << temp->data << " ";
                if( temp->right ){
                    dq.push_front( temp->right );
                }
                if( temp->left ){
                    dq.push_front( temp->left );
                }
            }
        }
    }
}


// void zigZagView( Node* root ){
//     queue<Node*>q;
//     q.push(root);
//     q.push(NULL);
//     bool leftToRight = false;
//     while( !q.empty() ){
//         Node* temp = q.front();
//         q.pop();
//         if( temp == NULL ){
//             leftToRight = !leftToRight;
//             if( !q.empty() ){
//                 q.push(NULL);
//             }
//         } 
//         else{
//             cout << temp->data << " ";
//             if( leftToRight ){
//                 if( temp->left ){
//                     q.push( temp->left );
//                 }
//                 if( temp->right ){
//                     q.push( temp->right );
//                 }
//             }
//             else{
//                 if( temp->right ){
//                     q.push( temp->right );
//                 }
//                 if( temp->left ){
//                     q.push( temp->left );
//                 }
//             }
//         }
//     }
// }
int main(){
    map<int , int>hash;
    map<int , int>::iterator itr;
    Node* root = NULL;
    root = buildLevelOrder(root);
    cout << "ZigZag View\n";
    zigZagView( root );
}