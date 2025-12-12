/*
    Project : Singly Linked List Implementation in C++
    Author  : Om Channawar
    Date    : Nov 2025

    --------------------------------------------------------------------
    📘 OVERVIEW: Singly Linked List

    A Singly Linked List is a dynamic linear data structure made of nodes.
    Each node stores:
        • data   → the value
        • next   → pointer to the next node

    --------------------------------------------------------------------
    🔍 Characteristics
        • Dynamic memory allocation
        • Efficient insertion/deletion at the head (O(1))
        • No direct indexing (sequential access only)
        • Additional memory needed for pointer fields

    --------------------------------------------------------------------
    ⚙️ Supported Operations
        1. Insert at front
        2. Insert at back
        3. Insert at a specific position
        4. Delete from front
        5. Delete from back
        6. Reverse the list
        7. Display all nodes

    NOTE:
    Since no tail pointer is used, operations involving the end of the list
    require traversal (O(n)). All space complexities are O(1) because
    operations only allocate one node (if needed) and use constant extra
    pointers.
    --------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Node structure
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

// Singly Linked List (no tail pointer)
class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    // Insert at front
    // Time: O(1)
    // Space: O(1)
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        cout << ">>> " << val << " inserted at front" << endl;
    }

    // Insert at back
    // Time: O(n)
    // Space: O(1)
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }

        cout << ">>> " << val << " inserted at back" << endl;
    }

    // Insert at given position (0-based)
    // Time: O(n)
    // Space: O(1)
    void push_position(int val, int pos)
    {
        if (pos < 0)
        {
            cout << ">>> Invalid Position" << endl;
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
        newNode->next = (temp ? temp->next : NULL);

        if (temp)
            temp->next = newNode;

        cout << ">>> " << val << " inserted at position " << pos << endl;
    }

    // Delete front node
    // Time: O(1)
    // Space: O(1)
    void pop_front()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;

        cout << ">>> First element deleted" << endl;
    }

    // Delete last node
    // Time: O(n)
    // Space: O(1)
    void pop_back()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << ">>> Last element deleted" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;

        cout << ">>> Last element deleted" << endl;
    }

    // Display list
    // Time: O(n)
    // Space: O(1)
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

    // Reverse list
    // Time: O(n)
    // Space: O(1)
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        cout << ">>> List reversed" << endl;
    }
};

// Menu-driven main
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
        cout << "6. Reverse List\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

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
            ll.reverse();
            break;

        case 7:
            ll.display();
            break;

        case 8:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}