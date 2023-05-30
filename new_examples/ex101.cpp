#include<iostream>
#include<vector>
using namespace std;

int solve(int A, int B, int C) {
   int minNum = INT_MAX, midNum, maxNum = INT_MIN;
   vector<int> ans;
   ans.push_back(A);
   ans.push_back(B);
   ans.push_back(C);
   int i = 0;
   while(i < 3){
     if(ans.at(i) <= minNum)
       minNum = ans.at(i);
      if(ans.at(i) >= maxNum)
       maxNum = ans.at(i);
       i++;
   }
   midNum = A+B+C-minNum-maxNum;
   int temp = (minNum*pow(10,4) + midNum*pow(10,2) + maxNum);
   
   return temp;
}

int main(){
 int ans = solve(33,44,55);
 cout<<ans;
}