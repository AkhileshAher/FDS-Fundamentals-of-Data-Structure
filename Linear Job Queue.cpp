/*
  
*/


//CODE :

#include <iostream>
#define max 10
using namespace std;

int queue[100], front = -1, rear = -1;

void Insert() {
    int job;
    if (rear == max - 1)
        cout << "Queue Is Overflow" << endl;
    else {
        if (front == -1)
            front = 0;
        cout << "Enter The Computer Job In Queue:" << endl;
        cin >> job;
        rear++;
        queue[rear] = job;
    }
}

void Delete() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Job Deleted From Queue Is:" << queue[front] << endl;
        front++;
    }
}

void Display() {
    if (front == -1)
        cout << "Queue Is Empty" << endl;
    else {
        cout << "Computer Jobs Queues Are: " << endl;
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main() {
    int ch;
    cout << "1. Insert Job To Queue" << endl;
    cout << "2. Delete Job From Queue" << endl;
    cout << "3. Display All Job Of Queue" << endl;
    cout << "4. Exit" << endl;

    do {
        cout << "Enter Your Choice:";
        cin >> ch;
        switch (ch) {
            case 1: Insert(); break;
            case 2: Delete(); break;
            case 3: Display(); break;
            case 4: cout << "Exiting Program" << endl; break;
            default: cout << "Invalid Choice" << endl; break;
        }
    } while (ch != 4);
    return 0;
}
