#include<iostream>
#include<vector>
using namespace std ;

int findLeftIndex(vector<int> A, int B){
    int size = A.size() , s = 0 , e = size - 1;
    int answer;
    while(s <= e){
        int mid = s + (e - s)/2 ; 
        if(A.at(mid) == B) {
            answer = mid;
            e = mid -1;
            continue;
        }
        if(A.at(mid) > B) e = mid -1 ;
        else s = mid + 1;
    }
    return answer;
}

int findRightIndex(vector<int> A, int B){
    int size = A.size() , s = 0 , e = size - 1;
    int answer;
    while(s <= e){
        int mid = s + (e - s)/2 ; 
        if(A.at(mid) == B) {
            answer = mid;
            s = mid+1;
            continue;
        }
        if(A.at(mid) > B) e = mid -1 ;
        else s = mid + 1;
    }
   return answer;
}
vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> answer;
    int leftIndex = findLeftIndex(A,B);
    answer.push_back(leftIndex);
    int rightIndex = findRightIndex(A,B);
    answer.push_back(rightIndex);
    return answer;
}

int main() {
   vector<int> A(1,10);
   vector<int> answer = searchRange(A,10);
   return 0;
}