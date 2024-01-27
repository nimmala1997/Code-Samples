#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<double> > dp(B.size() + 1, vector<double> (C+1,0.0));
    for(int i = 1 ; i <= B.size() + 1; i++){
        for(int j = 0 ; j <= C ; j++){
            dp[i][j] = dp[i-1][j];
            for(int partialQuantity = 1 ; partialQuantity <= min(j, B[i-1]) ; partialQuantity++){
                double value = partialQuantity * 1.0 / B[i-1] * A[i-1];
                dp[i][j] = max(value + dp[i-1][j-partialQuantity] , dp[i][j]);
            }
        }
    }
    return dp[B.size()][C] * 100;
}

int main(){
     vector<int> A = {16,3,3,6,7,8,17,13,7};
     vector<int> B = {3,10,9,18,17,17,6,16,13};
     int C = 11;
     int answer = solve(A, B , C);
     return 0;
}