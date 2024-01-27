#include<iostream>
using namespace std ;

int solve(vector<int> &A) {
    unordered_map<int , int> myMap;
    int answer = 0 ; 
    for(int i = 0 ; i < A.size() ; i++){
        if(myMap.count(A.at(i)) == 0) myMap[A.at(i)]++;
        else{
          while(myMap.count(A.at(i)) != 0){
                A.at(i)++;
                answer++;
          }
          myMap[A.at(i)]++;
        }
    }
    return answer ;
}


int main(){
      int arr[] = {1,1000000,1000000,100000000,10000,10000,10000} ; 
      vector<int> answer ;
      for(int i = 0 ; i < 7 ; i ++)
         answer.push_back(arr[i]);
      int output = solve(answer);
      cout<<output;
      return 0;
}