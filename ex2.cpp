#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool isPossible(int target, const vector<int>& matchsticks, vector<bool> isVisited, int currentSum, int k, int startIndex){
     if(k == 1) return true;
     if(currentSum == target) return isPossible(target, matchsticks, isVisited, 0, k-1, 0);
     for(int i = startIndex ; i < matchsticks.size() ; i++){
          if(isVisited[i] || currentSum + matchsticks[i] > target) continue;
          isVisited[i] = true;
          if(isPossible(target, matchsticks, isVisited, currentSum + matchsticks[i], k, i + 1)) return true;
          isVisited[i] = false;
     }
     return false;
}

bool makesquare(vector<int>& matchsticks) {
     int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
     int target = totalSum / 4;

     if(totalSum % 4 != 0) return false;

     vector<bool> isVisited(matchsticks.size(), false);
     sort(matchsticks.begin(), matchsticks.end());
     if(isPossible(target, matchsticks, isVisited, 0, 4, 0) == false) return false;

     for(int i = 0 ; i < matchsticks.size() ; i++){
          if(isVisited[i] == false) return false;
     }
     return true;
}

int main(){
     vector<int> input = {1,1,2,2,2};
     auto answer = makesquare(input);
     return 0;
}