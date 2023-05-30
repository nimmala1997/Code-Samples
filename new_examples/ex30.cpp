#include<iostream>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

void storesubstr(string input,string output,vector<string> &ans){
     if(input.length() == 0){
      ans.push_back(output);
      return;
     }
    storesubstr(input.substr(1),output,ans);
    storesubstr(input.substr(1),input[0]+output,ans);
      
}

int main(){
string str;
cin>>str;
string output = "";
vector<string> ans;
storesubstr(str,output,ans);
//cout<<ans.at(0);
for(int x = 0;x < ans.size();x++){
    cout<<ans.at(x)<<endl;
}
return 0;
}