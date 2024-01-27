#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
         return 0;
        vector<int> dict(128,-1);
        int start = 0,i;
        int ans = INT_MIN;
        for(i = 0 ; i < s.size() ;i++){
            if(dict[s[i]] != -1){
                ans = max(ans,(i - start));
            start = dict[s[i]] + 1;
            dict.clear();
            dict[s[i]] = i;
            }
            else{
                dict[s[i]] = i; 
            }

        }
        ans = max(ans,(i - start));
        return ans;
 }

 int main(){
   string s1 = "abba";
   int ans  = lengthOfLongestSubstring(s1);
   cout<<ans;
 }