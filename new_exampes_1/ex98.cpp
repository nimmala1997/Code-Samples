#include<iostream>
#include<string>
#include<vector>

using namespace std;

string reorganizeString(string s) {
     vector<int> count(26, 0);
     int mostFreqIndex = 0, i = 0;
     for(char ch : s){
          mostFreqIndex = ++count[ch-'a'] > count[mostFreqIndex] ? ch - 'a' : mostFreqIndex;
     }
     if(count[mostFreqIndex] - 1 > s.size() - count[mostFreqIndex]) return "";
     
     while(count[mostFreqIndex] > 0){
          s[i] = 'a'+ mostFreqIndex;
          i += 2;
          count[mostFreqIndex]--;
     }

     for(int j = 0 ; j < 26 ; j++){
          while(count[j] > 0){
               if(i >= s.size()) i = 1;
               s[i] = 'a' + j;
               i += 2;
               count[j]--;
          }
     }
     return s;
}

int main(){
     string input = "bfrbs";
     auto answer = reorganizeString(input);
     return 0;
}