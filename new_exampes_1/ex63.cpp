#include<iostream>
#include<string>

using namespace std;

bool checkAllCharacters(unordered_map<char, int> &myMap, unordered_map<char, int> &subStringCount){
     for(auto it = myMap.begin() ; it != myMap.end() ; it++){
          if(subStringCount[it->first] < it->second) return false;
     }
     return true;
}

string minWindow(string s, string t) {
     unordered_map<char, int> myMap;
     for(int i = 0 ; i < t.size() ; i++){
          myMap[t[i]]++;
     }
     int i = 0, j = 0;
     unordered_map<char, int> subStringCount;
     subStringCount[s[j]]++;
     int answer = INT_MAX, startingIndex = -1;
     while(j < s.size()){
          if(checkAllCharacters(myMap, subStringCount)){
               if(j - i + 1 <  answer){
               answer = (j-i+1);
               startingIndex = i;
               }
               subStringCount[s[i]]--;
               i++;
          }
          else{
               j++;
               if(j == s.size()) break;
               subStringCount[s[j]]++;
          }
     }
     return startingIndex != -1 ? s.substr(startingIndex, answer) : "";
} 

int main(){
     string s  = "ADOBECODEBANC";
     string t = "ABC";
     string output = minWindow(s, t);
     cout<<output;
     return 0;
}