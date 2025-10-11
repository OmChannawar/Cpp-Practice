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
            return;
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
        else if (pos = 0)
        {
            push_front(val);
            return;
        }
        else
        {
            Node *temp = head;

            for(int i = 0; i < pos; i++)
            {
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

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    ll.push_position(5, 2);

    ll.display();

    return 0;
}