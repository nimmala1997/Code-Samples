#include<iostream>
#include<priority_queue>
#include<vector>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int> , greater<int> > maxQueue;
    int k;
public:
     KthLargest(int k, vector<int>& nums) {
          this->k = k;
          for(int i = 0 ; i < nums.size() ; i++){
               if(i <= k) maxQueue.push(nums[i]);
               else{
                    maxQueue.pop();
                    maxQueue.push(nums[i]);
               }
          }
    }
    
    int add(int val) {
        if(maxQueue.size() > k) maxQueue.pop();
        maxQueue.push(val);
        if(maxQueue.size() > k) maxQueue.pop();
        return maxQueue.top();
    }
};

int main(){

}