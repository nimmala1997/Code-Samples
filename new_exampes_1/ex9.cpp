#include<iostream>
#include<cmath>
using namespace std;

int solRecursive(int A, long B){
    if (A == 1) {
        return 0;
    }
    long mid = (1LL << (A-2)) -1;
    
    if (B <= mid) {
        return solRecursive(A-1, B);
    }

    int prev = solRecursive(A-1, B-(mid+1));
    return (1-prev);
}


int main(){
    int x = 711, y = 568;
    int answer = solRecursive(x,y);
    cout << answer;
}