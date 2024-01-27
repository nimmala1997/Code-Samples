#include <iostream>
#include <vector>


using namespace std;
vector<int> altersort(vector<int> a){
    int m;
    int temp;

	for (int i = 0; i < a.size(); i++)
	{
		m = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] < a[m]) //Change was here!
			{
				m = j;
			}
		}

		temp = a[m];
		a[m] = a[i];
		a[i] = temp;
	}
    vector<int> b;
    int ans;
    for(int x = 0 ; x < a.size();x = x+2){
        ans = a[x];
        b.push_back(x);
    }
    return b;
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
    vector<int> result = altersort(x);
    for(int b = 0;b < result.size();b++)
     cout<<result.at(b);

return 0;
}