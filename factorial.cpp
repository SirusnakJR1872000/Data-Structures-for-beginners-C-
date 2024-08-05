// lets write a code for factorial
// n! = n * (n-1) * (n-2) * (n-3) * (n-4) ..........

int factorial(int n) {
    // now if the number is 1 or 0 we will return 1
    if (n <= 1) {
        return 1; //base condition
    }

    // recursive condition
    return n * factorial (n-1);
}