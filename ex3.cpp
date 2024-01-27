#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string> strs) {
// Your code here
     string common = strs[0];
     for(int i = 0 ; i< strs.size() ; i++){
          string current = strs[i];
          int j;
          for(j = 0 ; j < min(current.size(),common.size()); j++){
               if(current[j] != common[j]) break;
          }
          common = common.substr(0, j);
     }
     return common;
}

int main(){
     vector<string> input = {"one","two","three"};
     auto answer = longestCommonPrefix(input);
     return 0;
}