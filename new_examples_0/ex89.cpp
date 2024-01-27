#include<iostream>
#include<vector>

using namespace std;

int maxProfit(const vector<int> &A) {
    int min = INT_MAX;
    int max = INT_MIN;
    int n = A.size();
    int count = 0;
    int ans = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(A.at(i) < min){
         min = A.at(i);
         count = 0;
         }
         else
          {
              max = A.at(i);
              count = max - min;
              if(count > ans)
               ans = count;
          }
    }
    //if(ans == INT_MIN)
     //return 0;
     //else
      return ans;
}
int main(){
   
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(2);
    int sum = maxProfit(ans);
    cout<<sum;

    return 0;
   
}