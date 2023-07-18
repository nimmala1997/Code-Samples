#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000000007;
int solve(vector<int> &A, int B) {
   unordered_map<int,int> myMap;
   int count = 0;
   for(int i = 0 ; i < A.size() ; i++){
       int diffValue = myMap.count(B - A.at(i));
       if(A.at(i) == 7) cout<<diffValue;
       count += diffValue > 0 ? diffValue : 0;
       myMap[A.at(i)]++;
   }
   return count;
}

int main(){
   vector<int> input;
   int arr[] = {1, 2, 6, 6 , 7 , 8};
   for(int i = 0 ; i  <  6 ; i++)
      input.push_back(arr[i]);
   int answer = solve(input, 13);
   return 0;

}