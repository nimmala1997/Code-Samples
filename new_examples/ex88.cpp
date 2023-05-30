#include<iostream>
#include<vector>

using namespace std;

vector<int> subarraySum(vector<int>arr, long long s){
        int n = arr.size();
        int i = 0;
        long long count = 0;
        vector<int> ans;
        for(int k = 0; k < n ; k++){
            count += arr.at(k);
            if(count > s){
                count = count - arr.at(i);
                i++;
            }
            if(count == s){
                ans.push_back(i);
                ans.push_back(k);
                return ans;
            }
        }
        return ans;
}

int main(){
   vector<int> ans ;
   ans.push_back(1);
   ans.push_back(2);
   ans.push_back(3);
   ans.push_back(7);
   ans.push_back(5);
    
     vector<int> ans1 = subarraySum(ans,12);
     for(int i = 0 ; i < ans1.size() ;i++ ){
           cout<<ans1.at(i);
     }

   return 0;
}


