#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first <= p2.first;
}

int min_rooms(vector<int> start, vector<int> end){
     vector<pair<int, int> > intervals;
     for(int i = 0 ; i < start.size() ; i++){
          intervals.push_back({start[i], end[i]});
     }
     sort(intervals.begin(), intervals.end(), compare);
     set<int> endTime;

     for(int i = 0 ; i < intervals.size() ; i++){ 
          if(endTime.size() == 0) {
               endTime.insert(intervals[i].second);
               continue;
          }
          else{
               if(endTime.lower_bound(intervals[i].first) != endTime.begin()){
                    auto it = endTime.lower_bound(intervals[i].first);
                    endTime.erase(prev(it));    
               }
               endTime.insert(intervals[i].second);
          }
     }
     return endTime.size();
}

int main() {
    vector<int> arr1 = {0, 5, 6, 12, 13};
    vector<int> arr2 = {14, 9, 25, 19, 19};
    
    int size = min_rooms(arr1,arr2);
    cout<<size<<endl;
    return 0;
}