#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
   int squares = 0;
   for(int i = 0 ; i < A.size(); i++){
      if((float)A.at(i) < (float)B/A.at(i)) squares++;
      else break;
   }
   int answer = 0;
   for(int i = A.size() - 1 ; i >= 0; i--) {
      float valueIndex = (float)B/A.at(i);
      auto iterator = lower_bound(A.begin(), A.end(), valueIndex);
      int index = distance(A.begin(),iterator) - 1; 
      if(index <= i && index >= 0){
         if(index < i) answer += 2;
         if(valueIndex != A.at(i)) answer += 2;
      }
        
    }
    return answer+ squares;
}

int main(){
   int arr[] = {1,2,3,4,5};
   vector<int> input;
   for(int i = 0 ; i < 5 ; i++) input.push_back(arr[i]);
   int answer = solve(input, 5);
   return 0;
}