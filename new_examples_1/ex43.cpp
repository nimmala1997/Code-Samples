#include<iostream>
#include<vector>

using namespace std;

vector<int> subUnsort(vector<int> &A) {
    int startingPoint = -1, endPoint = -1;
    int compareValue = 0 , flag = 1;
    int i , minValue;
    for(i = 0 ; i < A.size() - 1 ; i++){
        if(A.at(i) > A.at(i+1)){
            if(startingPoint == -1){
                startingPoint = i;
                compareValue = A.at(i);
                flag = 0;
                minValue = A.at(i+1);
            }
            else{
                compareValue = max(A.at(i), compareValue);
                flag = 0;
            }
        }
        else if(compareValue && A.at(i) >= compareValue && !flag){
            endPoint = i - 1;
            flag = 1;
        }
    }
    if(!flag){
        if(compareValue && A.at(i) >= compareValue){
            endPoint = i - 1;
            flag = 1;
        }
        else
            endPoint = i;
    }
    vector<int> answer;
    if(startingPoint == -1){
        answer.push_back(-1);
        return answer;
    }
    for(i = 0 ; i < A.size() ; i++){
        if(A.at(i) > minValue && i < startingPoint){
            startingPoint = i;
            break;
        }
    }
    answer.push_back(startingPoint);
    answer.push_back(endPoint);
    return answer;
}

int main(){
   int arr[] = {1,2,3,5,6,13,15,16,17,13,13,15,17,17,17,17,17,19,19};
   vector<int> input,output;
   for(int i = 0 ; i < 19 ; i++) input.push_back(arr[i]) ;
   output = subUnsort(input);
   return 0;
}