#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> input){
   int ans = input.at(0)^input.at(0)^input.at(0);
   cout<<ans;
   for(int i = 1 ; i < input.size() ;i++){
       ans ^= input.at(i)^input.at(i)^input.at(i);
   }
   return ans;
}

int main(){
   vector<int> input(3,1);
   input.push_back(2);
   int ans = solve(input);
   cout<<ans;
}