#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &A, int B) {
    int x1 = B-1;
    int i = x1;
    int n = A.size();
    int x2 = 0;
    int ans = 0;
    while(i >= x2){
        if(A.at(i) == 1){
         cout<<i<<"-";
          ans++;
          //cout<<ans;
          if((i+B-1) >= (n-1)){
              return ans;
          }
          x2 = i+1;
          x1 = i+2*B - 1;
          i = x1;
          cout<<";"<<i<<endl;
        }
        else
         i--;
         
    }
     return -1;
    
}
int main(){
    
    vector<int> a1;
    //vector<int> a2;
    int n1;
    cin>>n1;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin>>x;
        a1.push_back(x);
        /* code */
    }
   int n2;
   cin>>n2;
    int ans = solve(a1,n2);
    cout<<ans;
return 0;
}