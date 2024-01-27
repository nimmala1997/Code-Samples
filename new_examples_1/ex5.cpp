#include<iostream>
#include<string>
using namespace std;

int solve(string A) {
        int maxOnes = 0;

        for(int i = 0 ;i < A.size() ; i++){
            if(A[i] == '1')
            maxOnes++;
        }
         
        if(maxOnes == 0)
           return 0;
        if(maxOnes == 1)
            return 1;
            
        int prev = 0 , curr = 0, total = INT_MIN;

        for(int i  = 0 ; i < A.size() ; i++ ){
             if(A.at(i) == '0'){
               if(total <= (prev+curr)){
                  total = prev + curr;
                   if(total < maxOnes)
                     total++;
                 }
                 prev = curr;
                 curr = 0;
             }

             else
                 curr++;
         }

  return total;
}

int main(){
    string s1 = "1011";
    int ans = solve(s1);
    cout<<ans;
}