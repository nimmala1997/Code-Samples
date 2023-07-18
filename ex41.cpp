#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int> input, int size, int maxValue){
    int i = 0, j = 0;
    int sum = 0;
    while(j < input.size()){
        if(j < size) {
            sum += input.at(j);
            j++;
        }
        else{
            if(sum > maxValue) return false;
            sum -= input.at(i);
            sum += input.at(j);
            i++;
            j++;
        } 
    }
    return sum < maxValue;
}

int solve(vector<int> &A, int B) {
    int s = 1, e = A.size(), answer;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(isPossible(A, mid, B)){
            answer = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return answer;
}


int main(){
   int arr[] = {1,2,3,4,5};
   vector<int> input;
   for(int i = 0; i < 5 ; i++) input.push_back(arr[i]);
   int answer = solve(input , 10);
   return 0;
}