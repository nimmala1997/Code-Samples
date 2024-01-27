#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
    int sr = 0, sc = 0, er = A-1, ec = A-1;
    int count = 1;
    int n = pow(A,2);
    vector<int> temp(A,0);
    vector<vector<int> > ans(A,temp);
    int k = 1;
    while(sr <= er && sc <= ec){

        for(int i = sc; i <= ec;i++){
            ans.at(sr).at(i) = count;
            if(count == n)
             return ans;
             count++;
        }
        sr++;
        if(count == n)
         return ans;

        for(int i = sr; i <= er;i++){
            ans.at(i).at(ec) = count;
            if(count == n)
             return ans;
             count++;
        }
        ec--;
        if(count == n)
         return ans;

        for(int i = ec; i >= sc;i--){
            ans.at(er).at(i) = count;
            if(count == n)
             return ans;
             count++;
        }
        er--;
         if(count == n)
         return ans;

        for(int i = er; i >= sr ;i--){
            ans.at(i).at(sc) = count;
            if(count == n)
             return ans;
             count++;
        }
        sc++;
        if(count == n)
        return ans;

    }
    return ans;
}

vector<int> spiral(int A){
   int sr = 0, sc = 0, er = A-1, ec = A-1;
    int count = 0;
    int n = pow(A,2);
    vector<int> ans;

    while(sr <= er && sc <= ec){
        for(int i = sc; i <= ec;i++){
            ans.push_back(A*sr + i +1);
            count++;
            if(count == n)
             return ans;
        }
        sr++;
        for(int i = sr; i <= er;i++){
            ans.push_back(i*A + ec +1);
            count++;
            if(count == n)
             return ans;
        }
        ec--;
        for(int i = ec; i >= sc;i--){
            ans.push_back(A*er + i +1);
            count++;
            if(count == n)
             return ans;
        }
        er--;
        for(int i = er; i >= sr ;i--){
            ans.push_back(i*A + sc +1);
            count++;
            if(count == n)
             return ans;
        }
        sc++;

    }
    return ans;
}

int main(){
   int n = 5; 
  // cin>>n;
   vector<vector<int> > ans = generateMatrix(n);
   for(int i = 0 ; i < ans.size() ; i++)
    for(int j = 0; j < ans.at(0).size();j++)
     cout<< ans.at(i).at(j);

return 0;
}

