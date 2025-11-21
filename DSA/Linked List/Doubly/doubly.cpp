#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;

        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;

        delete temp;
    }

    void popBack()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = tail;

        tail = tail->prev;
        ;
        if (tail != NULL)
            tail->next = NULL;
        temp->prev = NULL;

        delete temp;
    }

    void search(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Element " << key << " found at index " << idx << endl;
                return;
            }
            temp = temp->next;
            idx++;
        }

        cout << "Element " << key << " not found in the list." << endl;
    }
};

int main()
{
    DoublyList dll;
    int choice, val;

    while (true)
    {
        cout << "\nDoubly Linked List Menu\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Back\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Back\n";
        cout << "5. Search\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dll.pushFront(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            dll.pushBack(val);
            break;

        case 3:
            dll.popFront();
            break;

        case 4:
            dll.popBack();
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            dll.search(val);
            break;

        case 6:
            dll.display();
            break;

        case 7:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}