#include<iostream>
#include<vector>
using namespace std ;

int solve(vector<int> &A, int B) {
   unordered_map<int,int> myMap;
   int count = 0;
   for(int i = 0 ; i < A.size() ; i++){
       int diffValue = myMap[A.at(i) - B];
       int sumValue = myMap[A.at(i) + B];
       if(A.at(i) -  B != A.at(i) + B){
            if(diffValue > 0){
                count++;
                myMap[A.at(i)-B]--;
            }
            else {
                myMap[A.at(i)]++;
            }
            if(sumValue > 0 ){
                count++;
                myMap[A.at(i)+B]--;
            }
            else {
                myMap[A.at(i)]++;
            }
        }
       else{
            if(diffValue > 0){
                count++;
                myMap[A.at(i)]--;
           }
            else{
                myMap[A.at(i)]++;
            }
       }
   }
   return count;
}

int main(){
   int arr[] = {1,1,1,2,2};
   vector<int> answer ;
   for(int i = 0 ; i < 5 ;i++)
      answer.push_back(arr[i]);
   int x = solve(answer,0);
   return 0;
   }
