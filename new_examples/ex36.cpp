#include<iostream>
#include<vector>

using namespace std;

int majority(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int ans = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == ans)
                count++;
            else
                count --;
            if(count == 0){
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }

int main(){
    vector<int> v1;
    int n;
    cin>>n;
    int temp;
    for(int i = 0 ;i < n;i++){
        cin>>temp;
        v1.push_back(temp);
    }
    int ans = majority(v1);
    cout<<ans;

return 0;
}