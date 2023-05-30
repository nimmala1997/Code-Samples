#include<iostream>
#include<unordered_set>
#include<string>
#include<iterator>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
         return 0;
        unordered_map<char,int> map1;
        int ans = INT_MIN,temp = 0;
        int i= 0;//j = 0;
        while(i < s.size()){
           // int temp = 0;
            if(map1.count(s[i]) > 0){
                temp = map1.size();
                ans = max(temp,ans);
                unordered_map<char,int>::iterator it = map1.begin();
                unordered_map<char,int>::iterator j = map1.find(s[i]);
                if(j != map1.begin())
                 map1.erase(map1.begin(), j);
                 else
                  map1.erase(j);
                map1[s[i]] = i;
            }
            else{
                map1[s[i]] = i;
            }
            i++;
        }
        temp = map1.size();
        ans = max(temp,ans);
        return ans;
    }

int main(){
   string s1 = "pwwkew";
   int ans = lengthOfLongestSubstring(s1);
   cout<<ans;

return 0;
}