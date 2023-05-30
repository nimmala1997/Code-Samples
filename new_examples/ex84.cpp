#include<iostream>
#include<vector>

using namespace std;

int josephus(int n, int k)
    {
       //Your code here
       vector<int> arr;
       for(int i = 0 ; i < n ; i++){
           arr.push_back(i);
       }
       int i = 0; 
       //n = n-1;
       while(n != 1){
           i = i + k;
           if(i == n){
               arr.erase(i-1);
               i = 0;
               n--;
           }
           else
            if(i < n ){
                arr.erase(--i);
                n--;
            }
            else{
                i = i%n; 
                arr.erase(--i);
                n--;
            }
       }
       return arr.at(0);
    }

    int main(){
      int ans = josephus(5,3);
      cout<<ans;

    return 0;
    }