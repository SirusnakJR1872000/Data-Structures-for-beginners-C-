// lets write a code to implement bucket sort
// bucket sort is the most fastest sorting technique but it only works well on a limited amount of data
// the dataset should have values ranging for say 1 to 100 which is quite limited

#include <vector>

using std :: vector;

vector<int> bucketSort(vector<int>& arr) {
    // asssuming the values are from 0 to 2
    int counts[] = {0,0,0};

    for (int n: arr) {
        counts[n] ++;
    }

    int i = 0;

    for (int n = 0; n < 3; n++) {
        for (int j = 0; j < counts[n]; j++) {
            arr[i] = n;
            i++;
        }
    }
    return arr;

}

