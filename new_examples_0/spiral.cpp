#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
 vector <int> Solution(vector<vector<int> > &matrix){
   vector <int> sol;
   int r = matrix.size();
   int c = matrix[0].size();
   int sr  = 0,er = r-1,sc = 0,ec = c-1;
   int count = 0;
   while(sr<=er && sc <=ec){
   for(int x = sc;x<=ec;x++){
     sol.push_back(matrix[sr][x]);
     count++;
   }
   sr++;
   if(sol.size() == r*c)
    return sol;
    for(int y = sr;y <= er;y++){
      sol.push_back(matrix[y][ec]);
      count++;
    }
    ec--;
     if(sol.size() == r*c)
    return sol;
    for(int a = ec;a>=sc;a--){
      sol.push_back(matrix[er][a]);
      count++;
    }
    er--;
    if(sol.size() == r*c)
    return sol;
    for(int b = er;b >= sr ;b--){
      sol.push_back(matrix[er][sc]);
      count++;
    }
    sc++;
    if(sol.size() == r*c)
    return sol;
   }
}
};

int main(){
int rows;
int col;
cout<<"enter cols";
cin>>col;
cout<<"enter rows";
cin>>rows;
vector<int> colu(col);
vector<vector<int> > matri(rows,colu);
for(int x =0 ; x < rows ; x++){
    for(int y = 0 ; y < col;y++)
      cin>>matri.at(x).at(y);
}
solution s1;
vector<int> ans = s1.Solution(matri);
for(int a = 0 ;a < ans.size();a++){
  cout<<ans.at(a)<<" ";
}

return 0;

} 