#include<iostream>
#include<vector>
using namespace std;

class MinStack {
    int min;
    vector<int> arr;
    int size;
    vector<int> minArr;
public:
    MinStack() {
        min = INT_MAX;
        size = 0;
    }
    
    void push(int val) {
        arr.push_back(val);
        size++;
        if(val <= min){
         minArr.push_back(val);
         min = val;
        }
    }
    
    void pop() {
       if(size != 0){
        if(minArr.back() == arr.back()){
            minArr.pop_back();
            min = minArr.back();
        }
        arr.pop_back();
        size--;
        }
        else
         return;
        if(size == 0)
         min = INT_MAX;
    }
    
    int top() {
       return arr.back();
    }
    
    int getMin() {
        return minArr.back();
    }
};

int main(){

     MinStack* obj = new MinStack();
     obj->push(395);
     obj->push(276);
     obj->push(29);
     cout<<obj->top()<<"/";
     //obj->pop();
     cout<<obj->getMin()<<"/";
     //obj->pop();
     cout<<obj->getMin()<<"/";
     //obj->pop();
     obj->push(-482);
     cout<<obj->top()<<"/";
     cout<<obj->getMin()<<"/";
     obj->pop();
     obj->push(-108);
     obj->push(-259);
     cout<<obj->top()<<"/";
     cout<<obj->getMin()<<"/";
     obj->pop();
     cout<<obj->getMin()<<"/";
 
 return 0;
}