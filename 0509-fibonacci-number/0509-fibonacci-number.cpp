class Solution {
public:
    int fibonacci(int n)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }    

        else
        {
            return fib(n-1) + fib(n-2);
        }
    }
    int fib(int n) 
    {
        fibonacci(n);
    }
};