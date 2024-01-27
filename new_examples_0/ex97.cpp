#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;

int main(){
   unordered_map<string, int> myMap ;
   myMap["abc"] = 1;
   myMap["bcd"] = 2;

   for(unordered_map<string, int>::iterator it1 = myMap.begin(); it1 != myMap.end() ; it1++)
    cout<<"Key :" << it1->first<<" Value :"<<it1->second<<endl;
   
   for (unordered_map<string, int>::iterator it1 = myMap.find("abc"); it1 != myMap.end(); it1++)
      cout<<"Key :" << it1->first<<" Value :"<<it1->second<<endl;
   
   
 return 0;
}