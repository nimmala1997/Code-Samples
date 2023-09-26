#include<iostream>
#include<string>
#include<vector>

using namespace std;

string reverseWords(string s) {
     vector<string> allWords;
     int begin = -1;
     for(int i = 0 ; i < s.size() ; i++){
          if(begin == -1 && s[i] != ' ') begin = i;
          char S = s[i];
          if(s[i] == ' ' && begin >= 0 && i - begin > 0){
               allWords.push_back(s.substr(begin, i - begin));
               begin = i+1;
          }
     }
     string answer = "";
     for(int i = allWords.size()-1; i >= 0 ; i++){
          if(i != 0){
               answer += allWords[i] + " ";
          }
          else{
               answer += allWords[i];
          }
     }
     return answer;
}

int main(){
     string s1 = "the sky is blue";
     auto answer = reverseWords(s1);
     return 0;
}