/*
Problem Statement : Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to 
simulate the system using circular queue using array.
*/

// CODE :

#include <iostream>
const int MAX = 5;
using namespace std;

class PizzaParlour
{
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour()
    {
        front = rear = -1;
    }
    
    bool addOrder(int data);
    void serveOrder();
    void display();
};

bool PizzaParlour::addOrder(int id)
{
    if (rear == -1)
    {
        front = rear = 0;
        orders[rear] = id;
        return true;
    }
    else
    {
        rear = (rear + 1) % MAX;
        if (rear == front)
        {
            cout << "\nCafe Is Full. Please Wait For Some Time" << endl;
            return false;
        }
        else
        {
            orders[rear] = id;
            return true;
        }
    }
}

void PizzaParlour::serveOrder()
{
    if (front == -1)
    {
        cout << "\nNo Orders In Cafe" << endl;
        return;
    }
    else
    {
        cout << "\nOrder No." << orders[front] << " Is Processed\n";

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void PizzaParlour::display()
{
    int i = front;
    if (front == -1)
    {
        cout << "\nCafe Is Empty. No Orders" << endl;
        return;
    }
    else
    {
        cout << "Order Ids are:" << endl;
        while (i != rear)
        {
            cout << orders[i] << endl;
            i = (i + 1) % MAX;
        }
        cout << orders[rear] << endl;  // Print the last order
    }
}

int main()
{
    int ch, id = 0;
    PizzaParlour p;
    
    do
    {
        cout << "\n********MENU************";
        cout << "\n1. Accept Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Orders" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            id++;
            if (p.addOrder(id))
            {
                cout << "Thanks For Your Order. Your Order Id Is: " << id << endl;
            }
            else
                id--;  // Decrease id as order was not added due to full cafe
            break;

        case 2:
            p.serveOrder();
            break;

        case 3:
            p.display();
            break;
        }
    } while (ch != 4);

    cout << "Thank You! Keep Visiting" << endl;
}
