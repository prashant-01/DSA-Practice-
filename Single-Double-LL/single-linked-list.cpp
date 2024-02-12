 #include<bits/stdc++.h>
 using namespace std;
struct Node {
    int data;
    struct Node* next;

    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

    //Iterate over LL
void traverse(struct Node* head){
    struct Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout <<endl;
    return;
}

    //Insertion in LL : 
    // 1. Before Head 
    // 2. After Tail 
    // 3. In-between two nodes
void insertNode(struct Node** head , int val , int index){
    struct Node* temp = new Node(val);
    if(*head == NULL){//if LL is empty
        *head = temp;
        return;
    }
    if(index == 0){//Insertiion Before Head 
        temp->next = *head;
        *head=temp;
        return;
    }
    struct Node* prev=*head;
    for(int i=0;i<index-1;i++){//Insertion in-between nodes / after tail
        prev=prev->next;
    }
    if(prev->next != NULL){
        temp->next = prev->next;
    }
    prev->next=temp;
    return;
}

void deleteNode(struct Node** head , int index){
    if(*head == NULL)return;
    struct Node* temp;
    struct Node* prev=*head;
    if(index == 0){
        temp=*head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    for(int i=0 ; i<index-1;i++){
        prev=prev->next;
    }
    temp=prev->next;
    if(prev -> next -> next == NULL){
        prev->next = NULL;
        free(temp);
        return;
    }
    prev->next = (prev->next)->next;
    free(temp);
    return;
}
 int main(){
    struct Node* head = NULL;
    insertNode(&head ,  2 , 1);
    insertNode(&head ,  5 , 0);
    insertNode(&head ,  6 , 1);
    insertNode(&head ,  3 , 0);
    insertNode(&head ,  7 , 3);
    insertNode(&head ,  8 , 2);
    insertNode(&head ,  0 , 0);
    deleteNode(&head , 5);
    traverse(head);
 }