# include<iostream>

using std::cout;
using std::endl;

// we have to insert a value in the next open position in the array
// length -> no. of values in array , capacity is the size of the array

void insertEnd(int arr[], int n, int length, int capacity) {
    // we will check if there is space or not
    if (length < capacity){
        arr[length] = n; // inserting at the length means at the last position
    }
}

// now lets try inserting the value in the middle of the array
// inserting in the middle means shifting the rest of the elements to the right position
void insertMiddle(int arr[], int i, int n, int length){
    // we will start backwards and start shifting from end to i
    for (int index = length - 1; index >= i; index--){ // this condition makes sure that the elements are shifted to the right as we access the index before to the specified one
        arr[index + 1] = arr[index];
    }
    // now we will insert at that particular index
    arr[i] = n;
}

// next we will delete the element from the last position of the array
void removeEnd(int arr[], int length){
    // we will just overwrite the last element with 0 as it is the defualt value
    arr[length - 1] = 0;
}

// now lets try removing the element from the middle or any specified position
void removeMiddle(int arr[], int i, int length){
    // now we start shifting from i+1 to end
    for(int index = i + 1; index < length; index++){ // this condition makes sure that the elements are shifted to the left as we access the index next to the specified one
        arr[index - 1] =  arr[index];
    }
}

// now lets try printing the array
void printArray(int arr[], int capacity){
    for(int i = 0; i < capacity; i++){
        cout << arr[i] << ' ';
    }
    cout<< endl;
}
