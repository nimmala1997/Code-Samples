#include<iostream>
#include<vector>
#include<priority_queue>

using namespace std;

class MatrixElementData{
public:
    pair<int, int> row_column;
    int value;
    MatrixElementData(pair<int, int> p1, int value){
        row_column = p1;
        this->value = value;
    }
};

class CustomComparator{
public:
    bool operator()(MatrixElementData* &data1 , MatrixElementData* &data2){
        return data1->value > data2->value;
    }
};

int solve(vector<vector<int> > &A, int B) {
    priority_queue<MatrixElementData* , vector<MatrixElementData*>, CustomComparator> rowfirstElementQueue;
    int rowSize = A.size();
    int columnSize = A[0].size();
    for(int i = 0 ; i < rowSize ; i++){
        MatrixElementData data(make_pair(i,0), A[i][0]);
        rowfirstElementQueue.push(&data);
    }
    while(B > 1){
        auto value = rowfirstElementQueue.top();
        MatrixElementData* nextElement = nullptr;
        if(value->row_column.second < columnSize-1){
            int x = value->row_column.first;
            int y = value->row_column.second;
            nextElement = new MatrixElementData(make_pair(x, y+1) , A[x][y+1]);
        }
        rowfirstElementQueue.pop();
        if(nextElement) rowfirstElementQueue.push(nextElement);
    }
    auto answer = rowfirstElementQueue.top();
    return answer->value;
}

int main(){
     vector<vector<int> > input = {
        {9, 11, 15},
        {10, 15, 17}
     };
     int answer = solve(input, 6)
      
}