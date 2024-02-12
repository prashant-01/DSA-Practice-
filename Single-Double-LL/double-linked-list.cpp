 #include<bits/stdc++.h>
 using namespace std;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;

    Node(int val){
        this->prev=NULL;
        this->data=val;
        this->next=NULL;
    }
};

    //Iterate over LL
void traverseRight(struct Node* head){
    struct Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout <<endl;
    return;
}

void traverseLeft(struct Node* tail){
    struct Node* curr = tail;
    while(curr != NULL){
        cout << curr->data << " ";
        curr=curr->prev;
    }
    cout <<endl;
    return;
}

void insertNode(struct Node** head , struct Node** tail , int val , int index){
    struct Node* temp = new Node(val);
    if(*head == NULL){
        *head=temp;
        *tail=temp;
        return;
    }
    if(index==0){
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
        return;
    }
    struct Node* prev=*head;
    for(int i=0;i<index-1;i++){
        prev=prev->next;
    }
    if(prev->next == NULL){
        prev->next = temp;
        temp->prev=prev;
        *tail=temp;
        return;
    }
    temp->prev=prev;
    temp->next=prev->next;
    (prev->next)->prev=temp;
    prev->next=temp;
    return;
}

void deleteNode(struct Node** head , struct Node** tail , int index){
    
    if(*head == NULL){
        return;
    }
    Node* temp ;
    if(index == 0){
        temp=*head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    
    Node* curr= *head;
    for(int i=0 ; i<index ; i++){
        curr=curr->next;
    }
    if(curr->next == NULL){
        *tail=curr->prev;
        (*tail)->next=NULL;
        free(curr);
        return;
    }
    
    (curr->next)->prev = curr->prev;
    (curr->prev)->next=curr->next;
    free(curr);
    return;
}

 int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    insertNode(&head , &tail , 2 , 1);
    insertNode(&head , &tail , 5 , 0);
    insertNode(&head , &tail , 6 , 1);
    insertNode(&head , &tail , 3 , 0);
    insertNode(&head , &tail , 7 , 3);
    insertNode(&head , &tail , 8 , 2);
    insertNode(&head , &tail , 11 , 6);
    traverseLeft(tail);
    deleteNode(&head , &tail , 6);
    traverseRight(head);
    
 }