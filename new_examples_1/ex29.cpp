#include<iostream>
using namespace std;

int solve(const vector<int> &A, int B) {
    int size = A.size();
    int s = 0, e = size -1 ;
    while(s <= e){
        int mid = s + (e -s)/2 ;
        if(A.at(mid) == B) return mid ;
        if(A.at(mid) > A.at(s) && A.at(mid) > A.at(e)){
            if(B < A.at(mid) && B > A.at(s)) e = mid - 1;
            else s = mid+1;
        }
        else{
            if(B > A.at(mid) && B < A.at(e)) s = mid + 1;
            else e = mid-1;
        }
    }
    return 0
    ;
}
int main(){
   int arr[] = {101,103,106,109,158,164,182,187,202,205,2,3,32,57,69,74,81,99,100} ;
   vector<int> input ;
   for(int i = 0 ; i < 19 ; i++) {
      input.push_back(arr[i]);
   }
   int answer = solve(input,202);
   return 0;
}