// now lets implement binary search algorithm
// in binary search we find the middle value and then comapare with the target value
// if the target value is smaller than the mid value the right array is discarded
// else the left array is discarded

# include <vector>
using std :: vector;

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    // now we will run through the array only if left pointer is less than right pointer
    // otherwise we know it will be out of bounds

    while(left <= right) {
        int mid = (left + right) / 2;

        // now we will compare the target
        if (target > arr[mid]) {
            left = mid + 1;
        } 

        else if (target < arr[mid]) {
            right = mid - 1;
        }

        else{
            return mid; // it means the target value was found at mid;
        }
    }
    return -1; // if the element is not found
}
