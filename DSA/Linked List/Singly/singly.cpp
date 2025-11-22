/*
    Project: Singly Linked List Implementation in C++
    Developed and Implemented by: Om Channawar
    Date  : Nov 2025

    ------------------------------------------------------
    📘 THEORY: What is a Singly Linked List?

    A Singly Linked List is a linear data structure where each element is stored
    in a separate node. Each node contains:
        ➤ Data (value)
        ➤ Pointer to the next node in the list

    Unlike arrays, linked lists are dynamic in nature. Memory is allocated during
    runtime, allowing efficient insertion and deletion without shifting elements.

    Main Components:
        📍 Head: Pointer to the first node
        📍 Tail: Pointer to the last node
        📍 Next: Points to the next node in the list

    Advantages:
        ✔ Dynamic size
        ✔ Efficient insertion/deletion (front/back/position)
        ✔ No memory wastage

    Disadvantages:
        ❌ No direct access (must traverse)
        ❌ Extra memory for pointer storage

    Core Operations in this Program:
        ➤ Insert at front
        ➤ Insert at back
        ➤ Insert at specific position
        ➤ Delete from front
        ➤ Delete from back
        ➤ Reverse list
        ➤ Display list

    ------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Node class for Linked List
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node with value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Singly Linked List class
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // Insert element at the beginning of the list
    void push_front(int val)
    {
        if (head == NULL)
            cout << ">>> List is empty. Inserting first node..." << endl;

        Node *newNode = new Node(val);

        // If list is empty, both head and tail point to the new node
        if (head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }

        cout << ">>> " << val << " inserted at front" << endl;
    }

    // Insert element at the end of the list
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

    // Insert element at a specific position
    void push_position(int val, int pos)
    {
        if (pos < 0)
        {
            cout << ">>> Invalid Position" << endl;
            return;
        }

        // Handle empty list
        if (head == NULL)
        {
            if (pos == 0)
            {
                cout << ">>> List is empty. Inserting first node..." << endl;
                push_front(val);
            }
            else
            {
                cout << ">>> List is empty. Invalid position." << endl;
            }

            return;
        }

        // Insert at front if pos is zero
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        // Traverse to (pos - 1)th node
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

    // Delete element from the front
    void pop_front()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        // If list becomes empty after deletion
        if (head == NULL)
            tail = NULL;

        delete temp;

        cout << ">>> First element deleted" << endl;
    }

    // Delete element from the end
    void pop_back()
    {
        if (head == NULL)
        {
            cout << ">>> List is empty" << endl;
            return;
        }

        // When only one node exists
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            cout << ">>> Last element deleted" << endl;
            return;
        }

        Node *temp = head;
        // Traverse till second last node
        while (temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = NULL;

        cout << ">>> Last element deleted" << endl;
    }

    // Display all elements in the list
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

    // Reverse the entire linked list
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        // Iterate and reverse links
        while (curr != NULL)
        {
            next = curr->next;      // Note: we cannot perform this step before 'curr->next = prev', as we have to store the next node.
            curr->next = prev;      // Reverse the link
            prev = curr;
            curr = next;
        }

        head = prev; // Update head to new front
        cout << ">>> List reversed" << endl;
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
            cout << "Invalid choice\n";
        }
    }
}