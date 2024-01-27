#include<iostream>
using namespace std;

long power(int a, int b, int p) {
    if(b == 1) return a;
    long sa = power(a, b/2, p);
    if(b%2 == 0){
        long temp = (sa * sa) % p;
        return temp % p;
    }
    else{
        long temp = ((sa* sa) % p * (a%p))% p ; 
        return temp % p; 
    }
}

long factorial(int n , int p) {
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % p ;
    }
    return fact;
}

int nCrModP(int n, int r, int p) {
    if(r == 1) return n % p;
    if(p > 1 && r > 1){
        long numerator = factorial(n , p);
        long denominator1 = factorial(r , p);
        long inverseDenominator1 = power(denominator1 , p-2 , p);
        long denominator2 = factorial(n-r, p);
        long inverseDenominator2 = power(denominator2, p -2 , p);
        return (numerator % p * inverseDenominator1 % p * inverseDenominator2 % p) % p;
    }
    else{
         long numerator = factorial(n , p);
         long denominator1 = factorial(r, p);
         long denominator2 = factorial(n-r , p);
         return (numerator * denominator1 * denominator2);
        }
}

int solve(int A, int B, int C) {
    return nCrModP(A, B, C);
}

int main() {
            int answer = solve(1000000 , 1 , 100000007);
            cout<<answer;
            return 0;
}