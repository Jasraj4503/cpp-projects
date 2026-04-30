#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning\n";
    }

    // Append (insert at end)
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        cout << "Appended successfully\n";
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search element
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Element not found\n";
    }

    // Delete node
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        // If head is to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element not found\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Node deleted\n";
    }

    // Reverse linked list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "List reversed\n";
    }
};

// Main function (Menu-driven)
int main() {
    LinkedList list;
    int choice, data;

    while (true) {
        cout << "\n===== Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Append (Insert at End)\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete\n";
        cout << "6. Reverse\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> data;
                list.append(data);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> data;
                list.search(data);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;

            case 6:
                list.reverse();
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}