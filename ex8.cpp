#include<iostream>
#include<string>
using namespace std;

int toBinary(int a){
         long ans = 0, mul = 1;
    
         while(a > 0){
            ans += (a%2)*mul;
            mul *= 10;
            a = a/2;
         }

         return ans; 
}
string addBinary(string A, string B) {
         long a = 0,b = 0;
         int n = A.size(),mul = 1;
       
         for(int i = n-1 ; i >= 0 ;i--){
            int x = A.at(i);
            a += (x - 48)*mul;
            mul *= 2;
         }

         n = B.size(),mul = 1;
     
         for(int i = n-1 ; i >= 0 ;i--){
            int x = B.at(i);
            b += (x-48)*mul;
            mul *= 2;
         }

         int ans = toBinary(a+b);
         return to_string(ans);
}


int main(){
         string s1 = "1010110111001101101000";
         string s2 = "1000011011000000111100110";

         string ans = addBinary(s1,s2);
         
         cout<<ans;

}