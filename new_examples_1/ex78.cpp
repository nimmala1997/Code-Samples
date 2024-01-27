#include<iostream>
#include<vector>
#include<stack>

using namespace std;

    vector<int> prevSmaller(vector<int> & maxHeights){
        stack<int> minStack;
        vector<int> resultIndex;
        for(int i = 0 ; i < maxHeights.size(); i++){
            while(!minStack.empty() && maxHeights[i] <= maxHeights[minStack.top()]){
                minStack.pop();
            }
            if(!minStack.empty()) resultIndex.push_back(minStack.top());
            else resultIndex.push_back(-1);
            minStack.push(i);
        }
        return resultIndex;
    }
    
    vector<int> nextSmaller(vector<int> & maxHeights){
        stack<int> minStack;
        vector<int> resultIndex;
        for(int i = maxHeights.size() - 1 ; i >= 0 ; i--){
            while(!minStack.empty() && maxHeights[i] <= maxHeights[minStack.top()]){
                minStack.pop();
            }
            if(!minStack.empty()) resultIndex.push_back(minStack.top());
            else resultIndex.push_back(-1);
            minStack.push(i);
        }
        reverse(resultIndex.begin(), resultIndex.end());
        return resultIndex;
    }

    vector<int> prefixSum(vector<int>& maxHeights){
        vector<int> minPrev = prevSmaller(maxHeights);
        vector<int> prefixSum(maxHeights.size(), 0);
        for(int i = 0 ; i < maxHeights.size() ; i++){
            if(minPrev[i] != -1){
                int prevSmallIndex = minPrev[i];
                prefixSum[i] = prefixSum[prevSmallIndex] + (i - prevSmallIndex) * maxHeights[i];
            }
            else{
                prefixSum[i] = (i+1) * maxHeights[i];
            }
        }
        return prefixSum;
    }

    vector<int> suffixSum(vector<int> &maxHeights){
        vector<int> nextSmall = nextSmaller(maxHeights);
        vector<int> suffixSum(maxHeights.size(), 0);
        for(int i = maxHeights.size() - 1; i >= 0 ; i--){
            if(nextSmall[i] != -1){
                int nextSmallIndex = nextSmall[i];
                suffixSum[i] = suffixSum[nextSmallIndex] + (nextSmallIndex - i) * maxHeights[i];
            }
            else{
                suffixSum[i] = (maxHeights.size() - i) * maxHeights[i];
            }
        }
        return suffixSum;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<int> prefix = prefixSum(maxHeights);
        vector<int> suffix = suffixSum(maxHeights);
        return 0;
    }

int main(){
     vector<int> input = {5,3,4,1,1};
     auto answer = maximumSumOfHeights(input);
     return 0;
}