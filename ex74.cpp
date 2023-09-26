#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     stack<int> nextGreaterElements;
     vector<int> allElements, answer;
     for(int i = nums2.size() - 1 ; i >= 0 ; i--){
          while(!nextGreaterElements.empty() && nums2[i] > nextGreaterElements.top()){
               nextGreaterElements.pop();
          }
          if(!nextGreaterElements.empty()) allElements.push_back(nextGreaterElements.top());
          else allElements.push_back(-1);
          nextGreaterElements.push(nums2[i]);
     }
     unordered_map<int,int> myMap;
     for(int i = 0 ; i < nums2.size() ; i++){
          myMap[nums2[i]] = allElements[i];
     }
     for(int i = 0 ; i < nums1.size() ; i++){
          answer.push_back(myMap[nums1[i]]);
     }
     return answer;
}

int main(){
     vector<int> nums1 = {4, 1, 2};
     vector<int> nums2 = {1, 3, 4, 2};
     auto answer = nextGreaterElement(nums1, nums2);
     return 0;
}