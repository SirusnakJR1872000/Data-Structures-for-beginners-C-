// lets write a code for the insertion sort
// in insertion sort we assign the first pointer to the second element because we know that if there is only one element then it is already sorted
// next pointer would be on the left side of the first one to compare the values
// if the next value is less than previous then we can swap them
# include <vector>

using std :: vector;

vector<int>  insertionSort(vector<int>& arr) { // we will return a vector of integers and the vector is passed by reference and not by value 
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        // till the array is not out of bounds and the next value is less than previous then we swap
        while (j >= 0 && arr[j+1] < arr[j]){ 
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            // decrement the pointer
            j --;
        }
    }
    return arr;
}