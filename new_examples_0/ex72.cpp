#include<iostream>
#include<vector>
using namespace std;

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n1 = arrive.size();
    int n2 = depart.size();
    vector<int> ans;
    int j;
    for(int i = 1; i < n1; i++){
        if(K == 0){
            //cout<<"ent";
         return false;
        }
        int s = ans.size();
        int key = 0;
        if(arrive[i] < depart[i-1]){
            ans.push_back(depart[i-1]);
            for(j = 0 ; j < s; j++ ){
              if(arrive[i] >= ans[j]){
                  ans[j] = INT_MAX;
                  key = 1;
                  break;
              }
            }
            if(key == 0)
             K--;
         } 
    }
    if(K==1)
    return true;
    else
    return false;
}
int main(){
    int n1;
    vector<int> A1;
    vector<int> A2;
    cin>>n1;
    for (int i = 0; i < n1; i++)
    {  int x;
       cin>>x;
       A1.push_back(x);
        /* code */
    }
    cin>>n1;
    for (int i = 0; i < n1; i++)
    {  int x;
       cin>>x;
       A2.push_back(x);
        /* code */
    }
    int ans = hotel(A1,A2,k);
    return 0;
}