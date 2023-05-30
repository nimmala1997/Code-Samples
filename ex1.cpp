#include<iostream>
#include<string>
using namespace std;

string interpret(string command) {
        for(int i = 0 ; i < command.size() ; i++){
            if(command[i] == '('){
               if(command[i+1] == ')'){
                   command[i] = 'o';
               }
               else{
                   command.erase(i,1);
                   i--;
               }
            }
            else
             if(command[i] == ')'){
                command.erase(i,1);
                i--;
            }
        }
        return command;
}

int main(){
   string s1 = "G()(al)";
   string ans = interpret(s1);
   cout<<ans;

return 0;
}