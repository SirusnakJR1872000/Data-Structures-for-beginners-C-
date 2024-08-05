// lets write a code for merge sort
// we will keep splitting the array into various halves until the subarray hits the size one
// we call it divide and conquer

#include <vector>

using std :: vector;

void merge(vector<int>&arr, int s, int m, int e) {
    // copy the sorted left and right half into temp arrays
    vector<int> L = {arr.begin() + s, arr.begin() + m+1};
    vector<int> R = {arr.begin() + m+1, arr.begin() + e+1};

    int i = 0; // index for L
    int j = 0; // index for R
    int k = s; // index for arr

    // now we will run the loop till there are elements in the array

    while (i < L.size() && R.size()){
        // we will compare the elements of the left and right array
        if (L[i] <= R[j]) {
            // placing in the array
            arr[k] = L[i++];
        }
        else {
            // placing in the array
            arr[k] = R[j++];
        }
        k++;
    } 

    // if there are elements remaining after comparison we will just add them 
    while(i < L.size()) {
        arr[k++] = L[i++];
    }
    while(j < R.size()) {
        arr[k++] = R[i++];
    }
}

vector<int> mergeSort(vector<int>&arr, int s, int e) {
    // first we will check if the array is empty or not or has only 1 element
    if (e - s + 1 <= 1){
        return arr;
    }

    // calculate the middle value
    int m = (s+e) / 2;

    // sort the left side
    mergeSort(arr, s, m);

    // sort the right side
    mergeSort(arr, m+1, e);

    // merge sorted halves
    merge(arr, s, m, e);

    return arr;
}