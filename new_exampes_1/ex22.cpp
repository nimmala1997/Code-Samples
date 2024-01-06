#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size(),count = 0;
    for(int i = 0 ; i < n; i++){
        if(A.at(i) <= B ) count++;
    }
    if(count == n) return 0;
    int ans = INT_MAX;
    count = 0;
    int startWindow = 0 , endWindow = 0;
    while(endWindow < n){
        if(endWindow < count){
            if(A.at(endWindow) > B) count++;
            endWindow++;
        }
        else{
            ans = min(ans, count);
            if(A.at(startWindow) > B) count--;
            if(A.at(endWindow) > B) count++;
            startWindow++;
            endWindow++;
        }
    }
    return min(ans, count);
}
int main(){
   int A[] = {1, 12, 10, 3, 14, 10, 5};
   vector<int> input;
   for(int i = 0 ; i < 7 ; i++){
      input.push_back(A[i]);
   }
   int answer  = solve(input, 8);
   return 0;
}