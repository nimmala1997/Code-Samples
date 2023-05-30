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
int singleNumber(const vector<int> &A) {
                    int n = A.size();
                    int answer = 0;
                    for(int i = 31 ; i > 0 ; i--){
                        int positionCount = 1<<i;
                        int count = 0;
                        for(int x = 0 ; x < A.size() ; x++){
                            if((positionCount&A.at(x)) != 0) count++;
                        }
                        if(count % 3 != 0) answer = answer|positionCount;
                    }
                    return answer;
}
int main(){
   vector<int> input(3,1);
   input.push_back(2);
   int ans = singleNumber(input);
   cout<<ans;
}