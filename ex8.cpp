#include<iostream>
#include<string>
#include<vector>

using namespace std;

int minDistance(string word1, string word2) {
     vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1));
     for(int i = 0 ; i <= word1.size(); i++){
          dp[i][0] = i;
     }
     for(int j = 0; j <= word2.size(); j++){
          dp[0][j] = j;
     }
     for(int i = 1 ; i <= word1.size(); i++){
          for(int j = 1 ; j <= word2.size(); j++){
               if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], 1+dp[i-1][j]);
               }
               else{
                    dp[i][j] = min(1 + dp[i-1][j-1], min(1 + dp[i][j-1], 1 + dp[i-1][j]));
               }
          }
     }
     return dp[word1.size()][word2.size()];
}

int main(){
     string str1 = "hor";
     string str2 = "ro";
     int answer = minDistance(str1, str2);
     return 0;
}