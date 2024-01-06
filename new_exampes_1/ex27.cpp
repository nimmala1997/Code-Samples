#include<iostream>
#include<vector>

using namespace std ;

int solve(vector<int> &A) {
    int size = A.size(), s = 0, e = size - 1;
    while(s <= e){
        int mid = s + (e -s)/2;
        if(mid == 0) {
            if(A.at(mid) != A.at(mid+1)) return A.at(mid);
            else s = mid+2;
            continue;
        }
        if(mid == size) {
            if(A.at(mid) != A.at(mid-1)) return A.at(mid);
            else e = mid - 2;
            continue;
        }
        if(A.at(mid) != A.at(mid-1) && A.at(mid) != A.at(mid+1))
            return A.at(mid);
        else{
            if(A.at(mid) == A.at(mid-1)){
                if((mid-1) % 2 != 0) e = mid-2;
                else s = mid+1;
                continue;
            }
            if(A.at(mid) == A.at(mid+1)){
                if((mid % 2) != 0) e = mid-1;
                else s = mid+2;
                continue;
            }
        }
    }
    return -1;
}

int main(){
   int arr[] = {1,1,2,2,3};
   vector<int>  input;
   for(int i = 0 ; i < 5 ; i++){
      input.push_back(arr[i]);
   }
   int answer = solve(input);
   return 0;
}