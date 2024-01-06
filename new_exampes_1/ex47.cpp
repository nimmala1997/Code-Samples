#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> answer;
    stack<int> myStack;
    for(int i = 0 ; i < A.size() ; i++){
        while(!myStack.empty() && myStack.top() != -1 && A.at(myStack.top()) >= A.at(i)){
            myStack.pop();
        }
        if(!myStack.empty()) answer.push_back(myStack.top());
        else answer.push_back(-1);
        myStack.push(i);
    }
    return answer;
}

vector<int> nextSmaller(vector<int> &A) {
    vector<int> answer;
    stack<int> myStack;
    for(int i = A.size() -1 ; i >= 0 ; i--){
        while(!myStack.empty() && myStack.top() != -1 && A.at(myStack.top()) >= A.at(i)){
            myStack.pop();
        }
        if(!myStack.empty()) answer.push_back(myStack.top());
        else answer.push_back(-1);
        myStack.push(i);
    }
    return answer;
}

int largestRectangleArea(vector<int> &A) {
    vector<int> previousSmaller = prevSmaller(A);
    vector<int> afterSmaller = nextSmaller(A);
    int answer = INT_MIN , size = A.size() - 1;
    for(int i = 0 ; i < A.size() ; i++){
        int lastIndex = previousSmaller[i];
        int nextIndex = afterSmaller[i];
        lastIndex = lastIndex != -1 ? lastIndex : 0;
        nextIndex = nextIndex != -1 ? nextIndex : size;
        answer = max(answer, A.at(i) * (nextIndex - lastIndex));
    }
    return answer;
}

int main() {
   int arr[] = {2,1,5,6,2,3};
   vector<int> input;
   for(int i = 0 ; i < 6 ; i++) input.push_back(arr[i]);
   int answer = largestRectangleArea(input);
   return 0;
}