#include<iostream>
#include<vector>
#include<string>

using namespace std;

void add_strings(vector <string> &x)
{   
    x.clear();
}
int main(){
    
    vector<string> name  = {"pavan","kalyan","nimmala"};
    add_strings(name);
    cout<<name.at(0)<<endl;

return 0;
}