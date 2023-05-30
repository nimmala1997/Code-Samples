#include<iostream>
#include<vector>

using namespace std;

int count(vector<int> x,vector <int> y){
    int ans = 0;
    for(int a = 0; a < x.size() ; a++){
        for(int b = 0;b < y.size();b++){
            if (x.at(a) == y.at(b))
              ans++;
        }
    }
    cout<<ans;
    for(int a = 0; a < y.size() ; a++){
        for(int b = 0;b < x.size();b++){
            if (y.at(a) == x.at(b))
              ans++;
        }
    }
    cout<<ans;
    int f = x.size() + y.size() - ans;
    return f;
}
int main(){
    int i;
    cin>>i;
    vector<int>x; 
    int temp;
    for(int a = 0;a < i;a++){
        cin>>temp;
        x.push_back(temp);
    }   
    int y;
    cin>>y;
    vector<int>c;
    for(int a = 0;a < y;a++){
        cin>>temp;
        c.push_back(temp);
    }  
    int ans = count(x,c);
    cout<<ans;

return 0;
}