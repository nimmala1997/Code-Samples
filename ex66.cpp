#include<iostream>
#include<vector>

using namespace std;

void findAllBST(int A, vector<int> &dp){
    if(dp[A] != 0) return;
    if(A == 0 || A == 1){
        dp[A] = 1;
        return;
    }
    for(int i = 0; i < A ; i++){
        int leftBST = i;
        if(dp[leftBST] == 0){
            findAllBST(leftBST, dp);
        }
        int rightBST = A-i-1;
        if(dp[rightBST] == 0){
            findAllBST(rightBST, dp);
        }
        dp[A] += dp[leftBST]*dp[rightBST];
    }
}

int numTrees(int A) {
    vector<int> dp(A+1, 0);
    findAllBST(A, dp);
    return dp[A];
}

int main(){
     int A = 6;
     int answer = numTrees(A);
     return 0;
}