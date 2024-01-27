#include<iostream>
#include<vector>

using namespace std;

void bfs(const vector<int>& nums,const int target, int currentSum, int startIndex, int& answer){
     if(currentSum == target && startIndex == nums.size()){
          answer++;
          return;
     }
     if(startIndex == nums.size()) return;
     bfs(nums, target, currentSum+nums[startIndex], startIndex+1, answer);
     bfs(nums, target, currentSum-nums[startIndex], startIndex+1, answer);
}

int findTargetSumWays(vector<int>& nums, int target) {
     int answer = 0;
     bfs(nums, target, 0, 0, answer);
     return answer;
}

int main(){
     vector<int> input = {1,1,1};
     int answer = 0;
     bfs(input, 1, 0, 0, answer);
     return 0;
}