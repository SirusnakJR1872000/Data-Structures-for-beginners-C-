// implementing double linked list
// the difference between singly and doubly is that the doubly linked list has a next and previous pointer

# include <iostream>

using std :: cout;
using std :: endl;

class ListNode {
public:
    // getting a value to store in the list
    int val_;
    // initializing the prev and next to Null pointer
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    ListNode(int val){
        val_ = val;
    }
};

class LinkedList {
public:
    // creating a head and tail pointer
    ListNode* head;
    ListNode* tail;

    LinkedList() {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head -> next = tail;
        tail -> prev = head;
    }

    // lets insert value at the front of the list

    void insertFront(int val) {
        // we will create a newNode to insert value
        ListNode* newNode = new ListNode(val);
        newNode -> prev = head;
        newNode -> next = head -> next;

        head -> next -> prev = newNode;
        head -> next = newNode;
    }

    // inserting at the end

    void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        newNode -> next = tail;
        newNode -> prev = tail -> prev;

        tail -> prev -> next = newNode;
        tail -> prev = newNode;
    }

    // removing from the front

    void removeFront() {
        head -> next -> next -> prev = head;
        head -> next = head -> next -> next;
    }

    // remove from the end

    void removeEnd() {
        tail -> prev -> prev -> next = tail;
        tail -> prev = tail -> prev -> prev;
    }

    // print the list
    void print() {
        ListNode* curr = head -> next;
        while(curr) {
            cout << curr -> val_ << "->";
            curr = curr -> next;
        }
        cout << endl;
    }


};

