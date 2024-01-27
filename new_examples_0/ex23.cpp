#include<iostream>
#include<vector>

using namespace std;
void savecount(int *a,int n,int x,int i,vector<int> &count){
    if( i == n)
     return;
    if(a[i] == x)
     count.push_back(i);
     return savecount(a,n,x,i+1,count);
    
}
int main(){
    int n ;
    cin>>n;
    int a[n];
    for(int x = 0; x < n;x++){
        cin>>a[x];
    }
    int x;
    cout<<"enter number";
    cin>>x;
    vector <int> count ;
    savecount(a,n,x,0,count);
    for(int x = 0; x < count.size();x++){
        cout<<count.at(x)<<" ";
    }
}