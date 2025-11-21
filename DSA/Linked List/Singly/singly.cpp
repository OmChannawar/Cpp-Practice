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
        if (head == NULL)
            cout << ">>> List is empty. Inserting first node..." << endl;

        Node *newNode = new Node(val);

        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }

        cout << ">>> " << val << " inserted at front" << endl;
    }

    void push_back(int val)
    {
        if (head == NULL)
            cout << ">>> List is empty. Inserting first node..." << endl;

        Node *newNode = new Node(val);

        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cout << ">>> " << val << " inserted at back" << endl;
    }

    void push_position(int val, int pos)
    {
        if (pos < 0)
        {
            cout << ">>> Invalid Position" << endl;
            return;
        }

        if (head == NULL)
        {
            if (pos == 0)
            {
                cout << ">>> List is empty. Inserting first node..." << endl;
                push_front(val);
            }
            else
                cout << ">>> List is empty. Invalid position." << endl;

            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << ">>> Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << ">>> " << val << " inserted at position " << pos << endl;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete temp;

        cout << ">>> First element deleted" << endl;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            cout << ">>> Last element deleted" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = NULL;

        cout << ">>> Last element deleted" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

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

    while (true)
    {
        cout << "\nSingly Linked List Operations\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Back\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Front\n";
        cout << "5. Delete Back\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            ll.push_front(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            ll.push_back(val);
            break;
        case 3:
            cout << "Enter value and position: ";
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
            cout << "Invalid choice\n";
        }
    }
}