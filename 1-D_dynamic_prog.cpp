# include <unordered_map>

using std :: unordered_map;

// lets understand 1-D programming 
// lets consider an expample of fibonacci sequence
// f(n) = f(n-1) + f(n-2) + ....................
// lets first try the brute force approach/recursion

int bruteforce(int n) {
    // lets check for the base cases
    if (n <= 1) {
        // if the value is less than 2 then we return that number
        return n;
    }
    // now we will recursively call the bruteforce()
    return bruteforce(n - 1) + bruteforce(n - 2);
}

// now one thing we need to understand here is that if the number is small then it doesnt matter if we are recursively 
// checking for the same value
// but if the number is too big then we would perform the operation on same number multiple times
// so lets try another approach of memoization

int memoization(int n, unordered_map<int, int> *cache) {
    // lets handle the base case
    if (n <= 1) {
        // return the value if the value is less than 2
        return n;
    }
    // if it is in cache
    // now we will store the operation performed number in the cache 
    // and if that number is already in cache we return that number
    if (cache -> count(n)) {
        return (*cache)[n];
    }
    return memoization(n - 1, cache) + memoization(n - 2, cache);
}

// the process of memoization is considered as a Top - Down approach
// because we start from the value and then go till the base

// another approach is a bottom - up approach
// which is a true dynamic programming approach

int dp(int n) {
    // handling the edge case where if the input is less than 2 that is 0 or 1 
    // we just return that number itself
    if (n < 2) {
        return n;
    }

    // lets define an array with 2 elements 
    int dp[] = {0, 1};
    // we start from 2 because we know the fibonacci value of 0 and 1
    int i = 2;
    // we iterate till n
    while (i <= n) {
        // we swap with element at index 1
        int temp = dp[1];
        // swap the value with new value
        dp[1] = dp[0] + dp[1];
        // put the value in temp
        dp[0] = temp;
        // increment the value
        i++;

    }
    // return the value at first element
    return dp[1];
}

