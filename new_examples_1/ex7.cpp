#include<iostream>
#include<string>
using namespace std;

string maxSubPalindrome(string s1){
         int n = s1.size();
         int x,y,z,count = 1,sum = 0;
         string ans;

         for(int i = 1; i < n ; i++){
            int x = i-1,y = i+1,sum = 0;

            while(x != 0 && y != n){
               if(s1[x] != s1[y] )
                  break;
               
               sum++;
               x--;
               y++;
            }

            sum = 2*sum+1;

            if(sum > count){
                count = sum;
                ans = s1.substr(x+1,count);
            }

            sum = 0, x = i-1,y = i;

            while(x != 0 && y != n){
               if(s1[x] != s1[y])
                  break;

               sum++;
               x--;
               y++;
            }

            sum = 2*sum;
            if(sum > count){
                count = sum;
                ans = s1.substr(x+1,count);
            }

         }
         return ans;
}

int main(){
         string s1 = "aaaabaaa";
         string ans = maxSubPalindrome(s1);
         cout<<ans;
         return 0;
}