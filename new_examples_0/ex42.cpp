#include<iostream>

using namespace std;

int countoperations(int num1, int num2) {
        int count = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 < num2){
                num2 = num2-num1;
                count++;
            }
            else{
                num1 = num1 - num2;
                count++;
            }
        }
        return count;
    }

    int main(){
        int a,b ;
        cin>>a>>b;
        int ans = countoperations(a,b);
        cout<<ans;

    return 0;
    }