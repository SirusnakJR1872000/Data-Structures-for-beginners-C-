// now we will write another code for binary search algorithm but here we do not have a target value 
// we have a range and we will imply some condition to find the value from the range

# include <vector>

using std :: vector;

// lets write a helper function for this

int isCorrect(int n){
    // check if the value is less than condition
    if(n < 10) {
        return 1;
    }
    // checking if the value is greater than condition
    else if(n > 10) {
        return -1;
    }
    // if it does not exist
    else {
        return 0;
    }
}

    int binarySearch(int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;

            if (isCorrect(mid) > 0) {
                high = mid - 1;
            }

            else if (isCorrect(mid) < 0) {
                low = mid + 1;
            }

            else {
                return mid;
            }
        }
        return -1;
    }
