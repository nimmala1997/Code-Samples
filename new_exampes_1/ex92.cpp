#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<string> copyInput(strs);
     for(auto& value : copyInput){
          sort(value.begin(), value.end());
     }
     unordered_map<string, vector<string> > sameValues;
     for(int i = 0 ; i < copyInput.size() ; i++){
          sameValues[copyInput[i]].push_back(strs[i]);
     }
     vector< vector<string> > answer;
     for(auto each : sameValues){
          answer.push_back(each.second);
     }
     return answer;
}

int main(){
     vector<string> input = {"eat","tea","tan","ate","nat","bat"};
     auto answer = groupAnagrams(input);
     return 0;
}