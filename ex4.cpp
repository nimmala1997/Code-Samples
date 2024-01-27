#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
     if (hand.size() % groupSize != 0)
          return false;
     map<int, int> numFrequency;
     int totalCount = 0;
     for (int i = 0; i < hand.size(); i++) {
          numFrequency[hand[i]]++;
     }
     int minNumber;
     while (totalCount != hand.size()) {
          if (totalCount % groupSize == 0) {
              minNumber = numFrequency.begin()->first;
          }
          if (numFrequency[minNumber] == 0)
               return false;
          numFrequency[minNumber]--;
          if (numFrequency[minNumber] == 0)
               numFrequency.erase(minNumber);
          minNumber++;
          totalCount++;
     }
     return true;
}

int main(){
     vector<int> input = {1,2,3,6,2,3,4,7,8};
     bool answer = isNStraightHand(input, 3);
     return 0;
}