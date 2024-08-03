# include <iostream>

using std :: cout;
using std :: endl;

class ListNode {
public:
    int val_;
    ListNode* next = nullptr; //pointer to the next node and is initially set to null

    ListNode(int val){ // constructor which takes the value 'val'
        val_ = val;
    }
};

// now lets implement a singly linked list
class LinkedList {
public:
    // initializing the head and tail pointers
    ListNode* head;
    ListNode* tail;

    LinkedList() {
        // now we will make a dummy node which will make removing a node from the beginning easier
        head = new ListNode(-1);
        tail = head;
    }

    // insert the value at the end of the list
    void insertEnd(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    // now lets remove a value from the list
    void remove(int index) {
        // we will keep a pointer to traverse through the list
        int i = 0;
        // a pointer to current node which is initially set to head
        ListNode *curr = head;
        while (i < index && curr) {
            i++; // moving the i to next 
            curr = curr->next; // moving the curr to next pointer
        }

        // remove the node ahead of curr
        // we will check if the curr and curr exists
        if (curr && curr->next) {
            // if the element to be removed is the last element then jus assign next of curr to tail
            if (curr->next == tail){
                tail = curr;
            }
            // now update the next tail pointer to the next of it
            curr->next = curr->next->next;
        }
    }

    void print(){
        // we want to skip the dummy node at the beginning
        ListNode* curr = head->next; 
        // now we will run the loop till curr is not Null
        while(curr) {
            cout << curr->val_ << "->"; // print the value of current node
            curr = curr->next; // move the curr pointer to next node
        }
        cout << endl;
    }


};