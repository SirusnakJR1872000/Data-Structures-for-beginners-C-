// lets write a code to implement queues

# include <iostream>
using std :: cout;
using std :: endl;

class ListNode {
public:
    int val_;
    ListNode* next = nullptr;

    ListNode(int val) {
        val_ = val;
    }
};

class Queue {
public: 
    ListNode* left;
    ListNode* right;
    
    Queue() {}
    // now lets try adding values to the queue
    void enqueue(int val) {
        ListNode* newNode = new ListNode(val);

        // if queue is not empty
        if (right != nullptr) {
            right -> next = newNode;
            right = right -> next;
        }

        else {
            left = right = newNode; // since both are at same location
        }
    }

    // lets try to delete the value from the queue
    // here we need to remember that queue follows a FIFO concept (First In First Out)

    int dequeue() {
        // check if list is empty
        if (left == nullptr) {
            return -1; // throw an exception
        }

        // remove the left node and return the left value
        int val = left -> val_;
        left = left -> next;
        // now if there was only one element and there is no value to assign to left
        if (! left) { 
            right = nullptr;
        }
        return val;
    }

    void print() {
        ListNode* curr = left;
        while (curr) {
            cout << curr -> val_ << " -> ";
            curr = curr -> next;
        }
        cout << endl;
    }
};