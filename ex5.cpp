#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkValidString(string s) {
     vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));

     for (int i = s.size() - 1; i >= 0; i--) {
          for (int j = i; j < s.size(); j++) {
               if (s[i] == ')' || s[j] == '(') continue;
               if (i == j) {
                    dp[i][j] = (s[j] == '*') ? true : false;
                    continue;
               }
               if (j == i + 1) {
                    dp[i][j] = (s[i] == '*' || s[i] == '(') ? true : false;
                    continue;
               }
               switch (s[j]) {
                    case '*':
                    switch (s[i]) {
                         case '*':
                              dp[i][j] = dp[i + 1][j] || dp[i][j - 1] || dp[i + 1][j - 1];
                              continue;
                         case '(':
                              dp[i][j] = dp[i + 1][j - 1] || dp[i][j - 1];
                              continue;
                         default:
                              continue;
                    }
                    case ')':
                    switch (s[i]) {
                         case '*':
                              dp[i][j] = dp[i + 1][j] || dp[i + 1][j - 1];
                              continue;
                         case '(':
                              dp[i][j] = dp[i + 1][j - 1];
                              continue;
                         default:
                              continue;
                    }
                    default:
                    continue;
               }
          }
     }
return dp[0][s.size() - 1];
}

int main(){
     string input = "(((((())*)))()))(()((*()*(*)))(*)()";
     bool answer = checkValidString(input);
     return 0;
}