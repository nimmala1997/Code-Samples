#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

void subsets(const vector<int> &nums, long long currentSum, int size, const long long totalSum, int currentIndex, long long &answer){
     answer = size == (nums.size() / 2) ? min(answer, abs(2LL * currentSum - totalSum)) : answer ;
     for(int i = currentIndex; i < nums.size() ; i++){
          if(i != currentIndex && nums[i] == nums[i-1]) continue;
          currentSum += nums[i];
          subsets(nums, currentSum, size+1, totalSum, i+1, answer);
          currentSum -= nums[i];
     }
}

int minimumDifference(vector<int>& nums) {
     long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
     sort(nums.begin(), nums.end());
     long long answer = LONG_MAX;
     subsets(nums, 0, 0, totalSum, 0, answer);
     return answer;
}

int main(){
     vector<int> input = {-36, 36};
     int answer = minimumDifference(input);
     return 0;
}