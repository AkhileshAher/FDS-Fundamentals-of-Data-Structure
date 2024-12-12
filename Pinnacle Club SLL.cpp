/*
The Department of Computer Engineering has a student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of a club. First node is reserved for the president of the club and the last node is reserved for the secretary of the club.
Write C++ program to maintain club member‘s information using singly linked lists. Store student PRN and Name. 
Write functions to:
A . Add and delete the members as well as president or even secretary.
B . Compute total number of members of club
C . Display members
Two linked lists exist for two divisions. Concatenate two lists.
*/

//CODE : 

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
} *start;


class SLL {
public:
    SLL() { start = NULL; }
    void accept();
    void display();
    void search();
    void insert_beginning();
    void insert_after();
    void insert_end();
    void delete_start();
    void delete_end();
    void delete_after();
};


Node* createNode() {
    Node* newNode = new Node;
    cout << "Enter Data: ";
    cin >> newNode->data;
    newNode->next = NULL;
    return newNode;
}


void SLL::accept() {
    int n;
    cout << "How Many Nodes You Want To Enter: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node* newNode = createNode();
        if (start == NULL) {
            start = newNode;
        } else {
            Node* trav = start;
            while (trav->next != NULL) {
                trav = trav->next;
            }
            trav->next = newNode;
        }
    }
}


void SLL::display() {
    Node* trav = start;
    while (trav != NULL) {
        cout << trav->data << " -> ";
        trav = trav->next;
    }
    cout << "NULL" << endl;
}


void SLL::search() {
    Node* trav = start;
    int target, found = 0;
    cout << "Enter the number to search: ";
    cin >> target;
    while (trav != NULL) {
        if (trav->data == target) {
            found = 1;
            break;
        }
        trav = trav->next;
    }
    if (found) {
        cout << "Number found!" << endl;
    } else {
        cout << "Number not found!" << endl;
    }
}


void SLL::insert_beginning() {
    cout << "Add Node To The Beginning:" << endl;
    Node* newNode = createNode();
    newNode->next = start;
    start = newNode;
    display();
}


void SLL::insert_after() {
    cout << "Enter Data To Insert After:" << endl;
    Node* newNode = createNode();
    Node* trav = start;
    int target;
    cout << "After Which Node You Want To Insert? ";
    cin >> target;
    while (trav->data != target && trav->next != NULL) {
        trav = trav->next;
    }
    if (trav != NULL) {
        newNode->next = trav->next;
        trav->next = newNode;
        display();
    } else {
        cout << "Node not found!" << endl;
    }
}


void SLL::insert_end() {
    cout << "Add Node To The End:" << endl;
    Node* newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        Node* trav = start;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
    display();
}


void SLL::delete_start() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = start;
    start = start->next;
    delete temp;
    cout << "First element deleted." << endl;
    display();
}


void SLL::delete_end() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* trav = start;
    Node* prev = NULL;
    while (trav->next != NULL) {
        prev = trav;
        trav = trav->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        start = NULL;
    }
    delete trav;
    cout << "Last element deleted." << endl;
    display();
}


void SLL::delete_after() {
    Node* trav = start;
    Node* temp = NULL;
    int target;
    cout << "Enter the node after which you want to delete: ";
    cin >> target;
    while (trav != NULL && trav->data != target) {
        trav = trav->next;
    }
    if (trav != NULL && trav->next != NULL) {
        temp = trav->next;
        trav->next = temp->next;
        delete temp;
        display();
    } else {
        cout << "Node not found or no node after target!" << endl;
    }
}


int main() {
    SLL s;
    s.accept();
    s.display();
    int choice;
    cout << "\n*********** MENU ***********" << endl;
    cout << "1. Search" << endl;
    cout << "2. Insert at Beginning" << endl;
    cout << "3. Insert After Specific Node" << endl;
    cout << "4. Insert at End" << endl;
    cout << "5. Delete First Node" << endl;
    cout << "6. Delete After Specific Node" << endl;
    cout << "7. Delete Last Node" << endl;
    cout << "0. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            s.search();
            break;
        case 2:
            s.insert_beginning();
            break;
        case 3:
            s.insert_after();
            break;
        case 4:
            s.insert_end();
            break;
        case 5:
            s.delete_start();
            break;
        case 6:
            s.delete_after();
            break;
        case 7:
            s.delete_end();
            break;
        case 0:
            cout << "Thanks for using!" << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}


