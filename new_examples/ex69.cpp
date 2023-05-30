#include<iostream>
#include<vector>
using namespace std;
int coverPoints(vector<int> &A, vector<int> &B) {
   int a = A.size();
   int b = 0,c = 0,ans = 0,n;
   //int b = B.size();
   for(int i = 1;i < a;i++){
       b = A[i]-A[i-1];
       c = B[i] - B[i-1];
       if(b<0)
        b = -b;
       if (c<0)
        c = -c;
       if(b>c)
        n = b;
       else
        n = c;
       ans = ans+n;
   }  
   return ans;
}

int main(){
    
    vector<int> a1;
    vector<int> a2;
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
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin>>x;
        a2.push_back(x);
        /* code */
    }
    int ans = 
return 0;
}