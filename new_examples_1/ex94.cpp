#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubsequence(string s) {
     vector<pair<int, int> > characters(26, {0,0});
     int answer = 0;
     for(int i = 0; i < s.size() ; i++){
          if(i >= 2 && characters[s[i]-'a'].first > 0){
               answer += (characters[s[i]-'a'].first -1) * i - characters[s[i]-'a'].second;

          }
          characters[s[i]-'a'].first++;
          characters[s[i]-'a'].second += i;
     }
     return answer;
}

int main(){
     string s1 = "aabcacgdhfhqabgh";
     int answer = countPalindromicSubsequence(s1);
     return 0;
}