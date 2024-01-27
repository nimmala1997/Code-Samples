#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArrayLeft(vector<int> ans, int k ){
            vector<int> sol = ans;
            int i = 0,j = k;

            while(j != 0){
                sol.erase(sol.begin()+i);
                j--;
                }

            for(j = 0 ; j < k;j++){
                sol.push_back(ans.at(j));
                }

            return sol;
}

vector<vector<int> > solve(vector<int> &A, vector<int> &B) {
            int n = B.size();
            vector<vector<int> > ans;

            for(int i = 0 ; i < n ; i++){
                vector<int> temp;
                B[i] %= A.size();
                temp = rotate(A,B[i]);
                ans.push_back(temp);
                }
            return ans;
}

int main(){
            vector<int> ans,B;
            int arr1[] = {4,74,35,16,100,77,50,51,31,29,67,12,43,31,83,2,85,85,39,27,64,86,5};
            int B1[] = {73,70,47,19,46,25,46,4,33,33,6,31,23,19,44,53,69,30,69,89,59,25,38,82,26,8,36,3};
          
            for (int i = 0; i < 23; i++){
               ans.push_back(arr1[i]);
               }

            for (int i = 0; i < 28; i++){
               B.push_back(B1[i]);
               }
   
            vector<vector<int> > sol = solve(ans,B);
            return 0;
}