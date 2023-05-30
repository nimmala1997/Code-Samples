#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int ans = A[n-1]+1;
    int rem = 0;
    if(ans == 10){
        ans = 0;
        rem = 1;
    }
    vector<int> an;
    an.push_back(ans);
    int k;
    if(A[0] == 0)
     k = 1;
    else
     k = 0;
    for(int i = n-2; i >= k;i--){
        //cout<<A[i];
        ans = A[i]+rem;
        cout<<ans;
        if(ans == 10){
            ans = 0;
            rem = 1;
        }
        else
         rem = 0;
       an.push_back(ans);
    }
    if(rem == 1)
    an.push_back(rem); 
    return an;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i = 0; i < n ;i++){
        int x;
        cin>>x;
        ans.push_back(x);
    }
    vector<int> fin = plusOne(ans);
    for(int i = 0; i < fin.size();i++){
        cout<<fin[i];
    }

}
