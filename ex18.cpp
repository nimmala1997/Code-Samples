#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
                int size = A.size();
                int countLessNumbers = 0;
                for(int i = 0 ; i < size ; i++){
                    if(A.at(i) <= B) countLessNumbers++;
                }
                int start = 0;
                int minSwaps = 0, count = INT_MAX;
                for(int end = 0 ; end < size ; end++){
                    if(end < countLessNumbers && A.at(end) > B) minSwaps++;
                    else{
                        if(A.at(start) > B) minSwaps--;
                        if(A.at(end) > B) minSwaps++;
                        count = min(minSwaps, count);
                        start++;
                    }
                }
                return count;
}

int main() {
                vector<int> answer;
                int arr[] = {1,12,10,3,14,10,5};
                for(int i = 0 ; i < 7 ; i++)
                    answer.push_back(arr[i]);
                int count = solve(answer,8);
                return 0;
}