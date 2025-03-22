#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node *head = NULL;
void createNode();
void insertBeg();
void insertEnd();
void insertPos();
void deleteBeg();
void deleteEnd();  
void deletePos();
void display();

int main(){
    int choice;
    cout <<"1->Create Node\n";
    cout <<"2->Insert node at begining\n";
    cout <<"3->Insert node at last\n";
    cout <<"4->Insert node at the Specific position\n";
    cout <<"5->Delet node at begining\n";
    cout <<"6->Delete node at last\n";
    cout <<"7->Delete node at the Specific position\n";
    cout <<"8->Display Node\n";
    cout <<"9->Exit\n";
    while(1){
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: createNode();
                    break;
            case 2: insertBeg();
                    break;
            case 3: insertEnd();
                    break;
            case 4: insertPos();
                    break;
            case 5: deleteBeg();
                    break;
            case 6: deleteEnd();
                    break;
            case 7: deletePos();
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
            default: cout << "Invalid choice\n";
        }
    }

    return 0;
}

void createNode(){
    int item;
    struct Node *newNode = new Node;
    cout << "Enter the element to insert: ";
    cin >> item;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insertBeg(){
    int item;
    struct Node *newNode = new Node;
    cout << "Enter the element to insert: ";
    cin >> item;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}


void insertEnd(){
    int item;
    struct Node *newNode = new Node;
    cout << "Enter the element to insert: ";
    cin >> item;
    newNode->data = item;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void insertPos(){
    int item, pos;
    struct Node *newNode = new Node;
    struct Node *temp = head;
    cout << "Enter the element to insert: ";
    cin >> item;
    cout << "Enter the position to insert: ";
    cin >> pos;
    newNode->data = item;
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteBeg(){
    if(head == NULL){
        cout << "List is empty\n";
    }else{
        struct Node *temp = head;
        head = head->next;
        delete temp;
    }
}


void display(){
    if(head == NULL){
        cout << "List is empty\n";
    }else{
        struct Node *temp = head;
        cout << "List elements are: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


void deleteEnd(){
    if(head == NULL){
        cout << "List is empty\n";
    }else{
        struct Node *temp = head;
        struct Node *prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}


void deletePos(){
    int pos;
    struct Node *temp = head;
    struct Node *prev = NULL;
    cout << "Enter the position to delete: ";
    cin >> pos;
    for(int i = 1; i < pos; i++){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}