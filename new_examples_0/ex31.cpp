#include<iostream>

using namespace std;

int lengtharr(char *ans){
    if(ans[0] == '\0'){
        return 0;
    }
    return 1+lengtharr(ans+1);
}
int convertchar(char *c,int n){
   if(n == 0)
    return 0;
   int smallans = convertchar(c,n-1);
   int last = c[n-1] - '0';
   return smallans*10 + last;
}

int main(){
    char ans[100];
    cin>>ans;
    int n = lengtharr(ans);
    int fin = convertchar(ans,n);
    cout<<fin;
}