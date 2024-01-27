#include<iostream>
#include<vector>
using namespace std;


int main()
{
 vector <int> vector1 ;
 vector <int> vector2 ;
 vector1.push_back(10);
 vector1.push_back(20);
 
 cout<<vector1.at(0)<<vector1.at(1)<<"size is"<<vector1.size()<<endl;
 vector2.push_back(100);
 vector2.push_back(200);
 
 cout<<vector2.at(0)<<vector2.at(1)<<"size is"<<vector2.size()<<endl;

vector< vector<int> > vector_2D;

vector_2D.push_back(vector1);
cout<<vector_2D.at(0).at(1);
return 0;
}