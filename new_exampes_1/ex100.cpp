#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> getleftMin(const vector<int>& nums){
     stack<int> minStack;
     vector<int> response;
     for(int i = 0; i < nums.size() ; i++){
          while(!minStack.empty() && nums[minStack.top()] >= nums[i]){
               minStack.pop();
          }
          if(minStack.empty()) response.push_back(-1);
          else response.push_back(minStack.top());
          minStack.push(i);
     }
     return response;
}

vector<int> getrightMin(const vector<int> &nums){
     stack<int> minStack;
     vector<int> response;
     for(int i = nums.size() - 1; i >= 0; i--){
          while(!minStack.empty() && nums[minStack.top()] >= nums[i]){
               minStack.pop();
          }
          if(minStack.empty()) response.push_back(nums.size());
          else response.push_back(minStack.top());
          minStack.push(i);
     }
     reverse(response.begin(), response.end());
     return response;
}

int maxSumMinProduct(vector<int>& nums) {
     vector<int> leftMin = getleftMin(nums);
     vector<int> rightMin = getrightMin(nums);
     vector<long long> prefixSum(nums.size(), 0);
     for(int i = 0 ; i < nums.size(); i++){
          prefixSum[i] = i != 0 ? prefixSum[i-1] + nums[i] : nums[i];
     }
     int answer = INT_MIN;
     for(int i = 0; i < nums.size(); i++){
          int leftMinIndex = leftMin[i];
          int rightMinIndex = rightMin[i];
          int subArraySum = leftMinIndex != -1 ? prefixSum[rightMinIndex - 1] - prefixSum[leftMinIndex] : prefixSum[rightMinIndex-1]; 
          answer = max(answer, nums[i] * subArraySum);
     }
     return answer;
}
    
int main(){
     vector<int> input = {1, 2, 3, 2};
     auto answer = maxSumMinProduct(input);
     return 0;
}