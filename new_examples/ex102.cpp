#include<iostream>
#include<vector>
using namespace std;

int solve(int* A,int n) {
    int maxNum = INT_MIN;
    int totalCost = 0;
    //int n = A.size();
    //vector<int> sortArr;
    for(int i = 0 ; i < n ; i++){
       if(A[i] > maxNum)
         maxNum = A[i];
         totalCost += A[i];
      // sortArr.push_back(A[i]);
    }
    //sort(sortArr.begin(), sortArr.end());
    vector<int> solution(maxNum+1,0);
    for(int i = 0 ; i < n ; i++){
        solution.at(A[i])++;
    }
    int cost = 0;
    for(int i = maxNum; i >= 0 ; i--){
       if(solution.at(i) > 0){
        cost += totalCost;
        totalCost = totalCost-i;
        if(solution.at(i) > 1){
         solution.at(i)--;
         i++;
        }
       }
    }
    return cost;
}

int main(){
   int arr[] = {14, 312, 971, 41, 776, 926, 674, 173, 773, 466, 884, 678, 807, 473, 339, 228, 297, 717, 964, 165, 737, 240, 432, 450, 612, 377, 549, 80, 483, 557, 65, 839, 974, 246, 446, 798, 272, 246, 231, 223, 1, 286, 106, 671, 653};
   int ans = solve(arr,45);
   cout<<ans;
 return 0;
}