#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        cout << ">>> " << newNode->data << " is inserted at front" << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cout << ">>> " << newNode->data << " is inserted at back" << endl;
    }

    void push_position(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
            return;
        }
        else
        {
            Node *temp = head;

            for(int i = 0; i < pos; i++)
            {
                if(temp == NULL)
                {
                    cout << ">>>Invalid Position" << endl;
                    return;
                }
                
                temp = temp->next;
            }

            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << ">>>List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }

        cout << ">>>First element deleted" << endl;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << ">>>List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = NULL;

            delete tail;
            tail = temp;
        }

        cout << ">>>Last element deleted" << endl;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};
int main()
{
    List ll;
    int choice, val, pos;
    while(true)
    {
        //Main Menu
        cout << "Singly Linked List Operations" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Back" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Front" << endl;
        cout << "5. Delete Back" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> val;
            ll.push_front(val);
            break;
        case 2:
            cout << "Enter value to insert at back: ";
            cin >> val;
            ll.push_back(val);
            break;
        case 3:
            cout << "Enter value and position to insert: ";
            cin >> val >> pos;
            ll.push_position(val, pos);
            break;
        case 4:
            ll.pop_front();
            break;
        case 5:
            ll.pop_back();
            break;
        case 6:
            ll.display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}