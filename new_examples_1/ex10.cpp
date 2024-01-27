#include<iostream>
#include<set>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
                    int sum,diff = INT_MAX;
                    long totalSum = 0,ans,temp;
                    set<int> mySet;

                    for(int i = 0 ; i < nums1.size() ;i++){
                        sum = abs(nums1.at(i) - nums2.at(i));
                        totalSum += sum;
                        mySet.insert(nums1.at(i));
                    }

                    ans = totalSum;

                    for(int i = 0 ; i < nums2.size() ;i++){
                        set<int> ::iterator iter;
                        iter = mySet.lower_bound(nums2.at(i));
                        sum = abs(nums1.at(i) - nums2.at(i));

                        if(iter != mySet.begin()){
                          temp = totalSum -sum;
                          set<int>::iterator prev_iter = prev(iter);
                          int prev_val = *prev_iter;
                          diff = abs(prev_val - nums2.at(i));
                          diff = min(abs(*iter - nums2.at(i)),diff);
                          temp += diff;
                        }
                        else{
                          temp = totalSum -sum;
                          diff = abs(*iter - nums2.at(i));
                          temp += diff;
                        }
                         if(ans > temp){
                             ans = temp;
                         }
                    }

                    return ans%1000000007;

}

int main(){
                   vector<int> arr1;
                   arr1.push_back(1);
                   arr1.push_back(7);
                   arr1.push_back(5);

                   vector<int> arr2;
                   arr2.push_back(2);
                   arr2.push_back(3);
                   arr2.push_back(5);

                   int ans = minAbsoluteSumDiff(arr1,arr2);

                   cout<<ans;


}