#include<iostream>
using namespace std;

bool isPossible(vector<int> &A, int checkSum, int totalStudents){
    int count = totalStudents, totalSum = 0;
    for(int i = 0 ; i < A.size() ; i++){
        if(count > 0) totalSum += A.at(i);
        if(totalSum > checkSum){
            totalSum = A.at(i);
            count--;
        }
    }
    return (totalSum <= checkSum && count >= 1) ;
}

int books(vector<int> &A, int B) {
    if(A.size() < B) return -1;
    int minValue = INT_MIN;
    int maxValue = 0;
    for(int i = 0 ; i < A.size() ; i++){
        maxValue += A.at(i);
        minValue = max(A.at(i), minValue);
    }
    int answer = INT_MAX;
    while(minValue <= maxValue){
        int mid = minValue + (maxValue - minValue) / 2;
        if(isPossible(A, mid , B)){
            answer = mid;
            maxValue = mid - 1;
        }
        else{
            minValue = maxValue + 1;
        }
    }
    return answer;
}

int main(){
   int arr[] = {73,58,30,72,44,78,23,9} ;
   vector<int> input;
   for(int i = 0 ; i < 8 ; i++) input.push_back(arr[i]);
   int answer = books (input, 5);
   return 0;
}