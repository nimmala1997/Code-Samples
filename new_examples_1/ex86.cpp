#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

vector<int> leftValues = {112, -1, 632, -1,596,-1, -1};
vector<int> rightValues = {267, -1, -1, 157, 633, -1, -1};
TreeNode* takeInputLevelWise(){
     int data = 375;

     if(data == -1)
          return NULL;
     
     queue<TreeNode*> nodeQueue;
     TreeNode* root = new TreeNode(data);
     nodeQueue.push(root);
     int i = 0, j = 0;
     while (!nodeQueue.empty())
     {
          TreeNode* firstNodeinQueue = nodeQueue.front();
          nodeQueue.pop();
          int leftData,rightData;

          leftData = leftValues[i++];
          if(leftData != -1){
          TreeNode* leftNode = new TreeNode(leftData);
          firstNodeinQueue->left = leftNode;
          nodeQueue.push(leftNode);
          }

          rightData = rightValues[j++];
          if(rightData != -1){
          TreeNode* rightNode = new TreeNode(rightData);
          firstNodeinQueue->right = rightNode;
          nodeQueue.push(rightNode);
          }
     }

     return root;    
}

int getSum(TreeNode* A){
    if(A == nullptr) return 0;
    return A->val + getSum(A->left) + getSum(A->right);
}

pair<bool, int> isPossibletoBreak(TreeNode* A, int targetSum){
    if(A == nullptr) return {false, 0};
    auto leftChild = isPossibletoBreak(A->left, targetSum);
    auto rightChild = isPossibletoBreak(A->right, targetSum);

    bool targetFound = leftChild.first || rightChild.first ;
    return {(targetFound || (A->val + leftChild.second == targetSum) || (A->val + rightChild.second == targetSum) || leftChild.second == targetSum || rightChild.second == targetSum), A->val + leftChild.second + rightChild.second};
}

int solve(TreeNode* A) {
    int totalSum = getSum(A);
    if(totalSum % 2 == 1) return false;
    int answer = isPossibletoBreak(A, totalSum/2).second;
    return answer;
}

int main(){
     auto root = takeInputLevelWise();
     int answer = solve(root);
     cout<<answer;

}