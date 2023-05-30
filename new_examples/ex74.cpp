#include<iostream>
using namespace std;

int minimumSum(int num) {
        int b = INT_MAX;
        int a = INT_MAX;
        int num1 = num;
        int rem; 
        int c,d;
        for(int i = 0; i < 4; i++){
            rem = num%10;
            num = num/10;
          if(rem < a && rem < b){
            //c = b;
            b = a;
            a = rem;
          }
          else
          if(rem < b){
           b = rem;
          }
          
        }
        //cout<<a<<" "<<b;
        int sum = a*10 + b*10 ;
        for(int i = 0; i < 4; i ++ ){
            rem = num1%10;
            num1 = num1/10;
            if(rem == a)
             a = INT_MAX;
            else
            if(rem == b)
              b = INT_MAX;
            else
                sum+= rem;
            }
        return sum;
    }

    int main(){
        int n;
        cin>>n;
        int ans = minimumSum(n);
        cout<<ans;
    }