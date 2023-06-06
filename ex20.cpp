#include<iostream>
using namespace std;
int gcdHelper(int A, int B){
                if(A < B) swap(A,B);
                if(B == 0) return A;
                return gcdHelper(A%B, B);
}
int cpFact(int A, int B) {
                int answer = 0;
                for(int i = 1 ; i <= sqrt(A) ; i++){
                    if(A%i == 0){
                        cout<<i<<"-";
                        if(gcdHelper(i,B) == 1) answer = max(i,answer);
                        if(gcdHelper(A/i,B) == 1) answer = max(A/i,answer);
                    }
                }
                return answer;
}
int main(){
               int A = 2 , B = 2;
               int answer = cpFact(A,B);
               cout<<answer;
               return 0;
}
