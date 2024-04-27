#include <iostream>
using namespace std;

// Defining a node in the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    // Constructor to initialize a node with a value
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// This Function prints the entire linked list
void printList(Node* node) {
    cout << "Linked List: ";
    while (node != nullptr) {
        cout << node->data << " ";  
        node = node->next; 
    }
    cout << endl;
}

// Function to add a new node at the end of the linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;  

    // If the list is empty set the new node as the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Otherwise find the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last; 
}

// function to find the last node of the list
Node* lastNode(Node* root) {
    while (root && root->next) {
        root = root->next;
    }
    return root;
}

// function to partition the list for quicksort
Node* partition(Node* l, Node* h) {
    int x = h->data;  // This is the pivot element
    Node* i = l->prev;

    // here i rearrange elements based on the pivot
    for (Node* j = l; j != h; j = j->next) {
        if (j->data <= x) {
            i = (i == nullptr) ? l : i->next;
            swap(i->data, j->data);
        }
        i = (i == nullptr) ? l : i->next;
        swap(i->data, h->data);
        return i;
    }
}

// Recursively apply quicksort to the list
void recursiveQuickSort(Node* l, Node* h) {
    if (h != nullptr && l != h && l != h->next) {
        Node* p = partition(l, h);  
        recursiveQuickSort(l, p->prev); 
        recursiveQuickSort(p->next, h); 
    }
}

// Function to sort the doubly linked list using quicksort
void sortDoublyLinkedList(Node* head) {
    Node* h = lastNode(head);  
    recursiveQuickSort(head, h); 
}


int main() {
    Node* a = nullptr; 

    append(&a, 30);
    append(&a, 3);
    append(&a, 4);
    append(&a, 20);
    append(&a, 5);

    cout << "Linked List before sorting:\n";
    printList(a);

    sortDoublyLinkedList(a);

    cout << "Linked List after sorting:\n";
    printList(a);

    return 0;
}
