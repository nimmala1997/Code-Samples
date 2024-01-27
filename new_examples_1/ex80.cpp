#include<iostream>
#include<vector>

using namespace std;

bool compare(vector<int> interval1, vector<int> interval2){
        if(interval1[0] != interval2[0]){
            return interval1[0] < interval2[0];
        }
        return interval1[1] < interval2[1];
    }

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     sort(intervals.begin(), intervals.end(), compare);
     auto previousInterval = intervals[0];
     int answer = 0;
     for(int i = 1 ; i < intervals.size() ; i++){
          if(intervals[i][0] < previousInterval[1]){
               answer++;
               if(intervals[i][1] < previousInterval[1]){
                    previousInterval = intervals[i];
                }
          }
          else{
               previousInterval = intervals[i];
          }
     }
     return answer;
}

int main(){
     vector<vector<int>> input = {
        {-52, 31},
        {-73, -26},
        {82, 97},
        {-65, -11},
        {-62, -49},
        {95, 99},
        {58, 95},
        {-31, 49},
        {66, 98},
        {-63, 2},
        {30, 47},
        {-40, -26}
    };
    int answer = eraseOverlapIntervals(input);
    return 0;
}

