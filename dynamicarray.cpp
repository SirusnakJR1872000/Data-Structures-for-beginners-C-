// now lets write a code to implement dyanmic arrays

# include <iostream>

using std::cout;
using std::endl;

// in dynamic array the size of the array can be increased later

class Array {
public:
    // first we will initialize a base size of the array
    int capacity = 2; // we will define an array of size 2
    int length = 0; // since there are no elements intially the length is going to be 0
    int *arr = new int[2]; // array of capacity 2

    Array(){};



    // now lets try pushing a value in the array at the end position

    void insertEnd(int n) {
        // first we need to check if we have space or not
        // if we do not have space we will double the size of our array
        if (length == capacity){
            resize(); // calling the resize function to increase the size
        }

        // now since the array is resized and we have space we can insert the value at the end
        arr[length++] = n; // inserting at the next available position
    }

    void resize() {
        // we will create an new array of double the size of the original array
        capacity = 2 * capacity;
        int *newArr = new int[capacity];

        // now we need to copy the elements of the original array to the new array
        for (int i = 0; i < length; i ++){
            newArr[i] = arr[i];
        }
        arr = newArr; // update the reference to the origianl array
    }

    // suppose we want to insert at a particular position
    void insertMiddle(int i, int n){
        // we will first check if the mentioned index is within the bounds of the array
        if (i< length) {
            arr[i] = n;
            return;
        }
        // otherwise we throw an out of bounds exception
    }

    // now we will remove the element from the last position of the array
    void removeLast(){
        // we will first check if the array is empty or not
        if (length > 0){
            length --; // this will automatically reduce the length by 1
        }
    }

    // now if we want to get a value from a particular index
    int get(int i){
        // we will check if that index is within the bounds of array
        if (i < length) {
            return arr[i];
        }
        // here we would throw an out of bounds exception
    }

    // now if we want to print an array
    void print(){
        // we will traverse through the array
        for (int i = 0; i < length; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};