#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000000007;
int gcd(int A, int B){
    if(A < B) swap(A,B);
    if(B == 0) return A;
    return gcd(A%B,B);              
}

int solve(int A, int B, int C) {
    int gcdOfB_C = gcd(B, C);
    long long s = min(C, B) ;
    long long e = (long long)A*s;
    
    long long answer = 0;
    long long commonFactors = (long long) B * C ;
    while(s <= e){
        long long mid = s + (e - s)/2 ;
        int factorNumber = mid/B + mid / C - (mid * gcdOfB_C/commonFactors) ;
        if(factorNumber == A) {
            answer = mid;
            answer = answer%MOD;
            e = mid -1;
            continue;
        }
        if(factorNumber > A) (e = mid-1);
        else s = mid + 1;
    }
    return answer % MOD;
}

int main(){
   int A = 807414236, B = 3788, C = 38141 ;
   int answer = solve (A, B, C);
   cout<<answer;
   return 0;
}