#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &A, int B) {
    int i = 0, j = 0, size = A.size();
    int subArraySum = 0;
    while(i <= j && j < size){
        if(subArraySum > B){
            subArraySum -= A.at(i);
            i++;
        }
        else{
         subArraySum += A.at(j);
         j++;
        }
        if(subArraySum == B) break;
    }
    vector<int> answer;
    if(subArraySum != B){
        answer.push_back(-1);
        return answer;
    }
    while(i <= j) answer.push_back(A.at(i++));
    return answer;
}

int main(){
   int arr[] = {5,10,20,100,105};
   vector<int> input;
   for(int i = 0 ; i < 5 ; i++)
      input.push_back(arr[i]);
   vector<int> answer = solve(input, 110);
   return 0;
}