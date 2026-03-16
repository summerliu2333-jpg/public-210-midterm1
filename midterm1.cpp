//COMSC-210-5068, Midterm1, Yang Liu
#include <iostream>
using namespace std;

// Constant values
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//DLL class implementation
class DoublyLinkedList {
private:
    // Node structure to store data and pointers
    struct Node {
        int data;                   // Stores integer value
        Node* prev;                 // Pointer to the previous node
        Node* next;                 // Pointer to the next node
        // Constructor for Node, initializes value and pointers
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;                     // Pointer to the first node of the list
    Node* tail;                     // Pointer to the last node of the list

public:
    // Default constructor, initialize empty list
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // Insert a new node after given position
    void insert_after(int value, int position) {
        // Check if position is a valid non-negative number
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        // Dynamically create a new node with the given value
        Node* newNode = new Node(value);

        // If list is empty, set head and tail to the new node
        if (!head) {
            head = tail = newNode;
            return;
        }

        // Create temporary pointer to traverse the list
        Node* temp = head;

        // Move temp to the node at the target position
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        // If position exceeds list size, cancel insertion
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        // Link newNode to the next node
        newNode->next = temp->next;
        // Link newNode back to temp
        newNode->prev = temp;
        // If there is a next node, update its prev pointer
        if (temp->next)
            temp->next->prev = newNode;
        // Otherwise, update tail to newNode
        else
            tail = newNode;
        // Link temp to newNode
        temp->next = newNode;
    }

    // Deletes the first node that contains the given value
    void delete_val(int value) {
        // If list is empty, do nothing
        if (!head) return;

        // Start from head to search for the value
        Node* temp = head;
        
        // Traverse until value is found or list ends
        while (temp && temp->data != value)
            temp = temp->next;

        // If value not found, do nothing
        if (!temp) return; 

        // Update previous node's next pointer
        if (temp->prev)
            temp->prev->next = temp->next;
        // If temp is head, move head forward
        else
            head = temp->next; 
        // Update next node's prev pointer
        if (temp->next)
            temp->next->prev = temp->prev;
        // If temp is tail, move tail backward
        else
            tail = temp->prev; 
        // Free memory of the deleted node
        delete temp;
    }
    
    // Deletes the node at the given 1-based position
    void delete_pos(int pos) {
        // If list is empty, display message and exit
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        
        // If deleting first position, call pop_front()
        if (pos == 1) {
            pop_front();
            return;
        }
        
        // Temp pointer to traverse the list
        Node* temp = head;
        
        // Move temp to the target position
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }

        // If temp is null, position is invalid
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
        
        // If deleting last node, call pop_back()
        if (!temp->next) {
            pop_back();
            return;
        }
    
        // Store pointer to previous node
        Node* tempPrev = temp->prev;
        // Bypass the deleted node
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}