#include<iostream>
#include<vector>

using namespace std;

 int dfs(vector<vector<int>>& dp, int i , int j, const vector<vector<int>>& matrix){
        if(i < 0 || j < 0 || i >= dp.size() || j >= dp[0].size()) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int answer = 0;
        if(i > 0 && matrix[i-1][j] < matrix[i][j]) {
            answer = dfs(dp, i-1 , j, matrix);
        } 
        if(j > 0 && matrix[i][j-1] < matrix[i][j]){
            answer = max(answer, dfs(dp, i, j-1, matrix));
        }
        if(i + 1 < dp.size() && matrix[i+1][j] < matrix[i][j]){
            answer = max(answer, dfs(dp, i+1, j, matrix));
        }
        if(j + 1 < dp[0].size() && matrix[i][j+1] < matrix[i][j]){
            answer = max(answer, dfs(dp, i, j + 1, matrix));
        }
        return 1 + answer;
    }

int longestIncreasingPath(vector<vector<int> >& matrix) {
     vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));
     //memset(dp, 0, sizeof(matrix));
     int answer = 1;
     for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size(); j++){
               dp[i][j] = dp[i][j] == 0 ? dfs(dp, i, j, matrix) : dp[i][j];
               answer = max(answer, dp[i][j]);
          }
     }
     return answer;
}

int main(){
     vector<vector<int> > input = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
     int answer = longestIncreasingPath(input);
     return 0;
}