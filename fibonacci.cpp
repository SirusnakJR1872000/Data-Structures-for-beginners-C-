int fibonacci(int n){
    if (n <= 1){
        return n;// base condition
    }
    // recursive call
    return fibonacci(n-1) + fibonacci(n-2);
}