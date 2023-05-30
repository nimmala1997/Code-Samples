#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void removeDuplicates(vector<int>& ans){
   unordered_map<int,int> sol;
   int i = 0;
   while(i < ans.size()){
      if(sol.count(ans.at(i)) > 0){
         ans.erase(ans.begin() +i);
      }
      else{
         sol[ans.at(i)] = 1;
         i++;
      }
   }
}

int main(){
   vector<int> ans;
   ans.push_back(1);
   ans.push_back(2);
   ans.push_back(3);
   ans.push_back(2);
   ans.push_back(1);
   ans.push_back(5);
   ans.push_back(4);
   ans.push_back(1);
   ans.push_back(3);

    removeDuplicates(ans);

     for(int i = 0 ; i < ans.size() ; i++){
      cout<<ans.at(i);
     }

return 0;
}