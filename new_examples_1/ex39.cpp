#include<iostream>
#include<vector>

using namespace std;

int maxValue(int value, vector<int> input){
    int answer = INT;
    int s = 0 , e = input.size() - 1;
    while(s <= e){
        int mid = s + (e - s)/2 ;
        if(input[mid] < value){
            answer = input[mid];
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return answer;
}

int solve(int A, int B, vector<vector<int> > &C) {
    int answer = INT_MAX;
    for(int i = 0 ; i < A - 1 ; i++){
        sort(C.at(i+1).begin(), C.at(i+1).end());
        for(int j = 0 ; j < B ; j++){
            auto lowerBound = lower_bound(C.at(i+1).begin() , C.at(i+1).end(),C.at(i).at(j));
            //lowerBound = findLowerValue(C.at(i).at(j), C.at(i+1));
            int maxLessValue = maxValue(C.at(i).at(j), C.at(i+1));
            answer = min(answer,min(abs(*lowerBound-C[i][j]),C[i][j] - maxLessValue));
        }
    }
    return answer;
}

int main(){
   int arr[][10] = {
        {95171, 64925, 51398, 40114, 693, 2377, 73808, 80091, 76151, 79440},
        {67162, 89457, 65239, 89157, 31092, 37848, 22896, 30167, 37883, 36897},
        {5988, 77161, 72711, 64765, 26452, 77921, 9225, 96615, 24939, 45282},
        {22835, 8357, 10207, 74133, 36619, 98949, 64658, 10426, 79039, 29057},
        {89767, 34448, 18513, 43253, 23604, 37753, 81001, 34649, 67820, 7132},
        {59694, 73708, 84193, 32404, 26720, 98793, 98473, 35846, 83656, 11659},
        {69276, 6490, 19916, 67631, 68771, 56435, 66579, 33428, 66762, 45617},
        {50633, 44776, 68213, 69046, 87929, 79966, 6799, 68930, 2862, 62767},
        {75962, 62456, 24723, 48402, 83008, 51343, 35443, 69728, 87089, 19098},
        {81288, 44613, 13736, 1203, 12243, 70655, 45787, 78723, 92231, 12548}
    };
   vector<vector<int> > input ;
   for (const auto& row : arr) {
      input.push_back(vector<int>(begin(row), end(row)));
   } 
   int answer = solve(10,10,input);
   return 0;
}