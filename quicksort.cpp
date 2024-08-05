// now lets implement a quick sort algorithm
// in quick sort we assign a pivot value and we compare all the values with the pivot value
// when the comparison is done the elements to the left are smaller than pivot
// elements to the right are greater than pivot

# include <vector>

using std :: vector;

vector<int> quickSort(vector<int>& arr, int s, int e) {
    // we will check if the array is empty or has only 1 element
    // if so we return the array itself
    if (e - s + 1 <= 1) {
        return arr;
    }

    // we will assign pivot as the end value
    int pivot = arr[e];
    // left most value as the start
    int left = s;

    // now we will traverse through the array
    for (int i = 0; i < e; i++) {
        // now we will compare the elements with the pivot
        if (arr[i] < pivot) {
            // if the condition is satisfied we swap with the left value since it is at first position
            int temp = arr[left];
            arr[left] = arr[i];
            arr[i] = temp;
            left ++ 
        }
    }

    // now we have the pivot in between the left and right sides
    arr[e] = arr[left];
    arr[left] = pivot;

    // quicksort the left side
    quickSort(arr, s, left - 1);

    //quicksort the right side
    quickSort(arr, left + 1, e);

    return arr;
    
}