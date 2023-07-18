#include<iostream>
#include<vector>

using namespace std;

vector<int> solve(vector<int> &A, int B) {
    int zerosCount = 0;
    vector<int> zerosIndex;
    zerosIndex.push_back(-1);
    int i = 0 , j =  0 , zeroIndex = 0;
    int answer = INT_MIN;
    int startIndex, endIndex;
    while(j < A.size()){
        if(A.at(j) == 0) {
            zerosCount++;
            zerosIndex.push_back(j);
        }
        if(zerosCount > B){
            i = zerosIndex.at(zeroIndex++) + 1;
            if((j - i) > answer){
                startIndex = i;
                endIndex = j - 1;
                answer = (j - i);
            }
            zerosCount--;
        }
        j++;
    }
    i = zerosIndex.at(zeroIndex++) + 1;
    if((j - i) > answer){
         startIndex = i;
         endIndex = j - 1;
    }
    vector<int> output;
    for(i =  startIndex ; i <= endIndex ;i++){
        output.push_back(i);
    }
    return output;
}

int main() {
   int arr[] = {1,1,0,1,1,0,0,1,1,1};
   vector<int> input;
   for(int i = 0 ; i < 10 ; i++) input.push_back(arr[i]);
   vector<int> output = solve(input, 1);
   return 0;
}