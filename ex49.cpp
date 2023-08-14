#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class TreeNode{
public:
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode* root){
   queue<TreeNode* >myQueue;
   myQueue.push(root);
   myQueue.push(nullptr);
   while(!myQueue.empty()){
      auto front = myQueue.front();
      myQueue.pop();
      if(front){
         cout<<front->val<<":";
         if(front->left) {
            myQueue.push(front->left);
            cout<<"l"<<front->left->val;
         }
         if(front->right) {
            myQueue.push(front->right);
            cout<<"r"<<front->right->val;
         }
         cout<<endl;
      }
      else{
         if(!myQueue.empty()) myQueue.push(nullptr);
      }
   }
}

void kthSmallest(TreeNode* A, int &K, int &answer){
    if(K == 0 || A == NULL) return;
    kthSmallest(A->left, K, answer);
    K--;
    if(K == 0) {
        answer = A->val;
        return;
    }
    kthSmallest(A->right, K, answer);

}
int kthsmallest(TreeNode* A, int B) {
    int answer;
    kthSmallest(A, B, answer);
    return answer;
}

void rootToNodePath(TreeNode* root, int nodeValue, bool &isFound, vector<int> &answer){
   if(root == NULL || isFound) return;
   answer.push_back(root->val);
   if(root -> val == nodeValue){
      isFound = true;
      return;
   }
   rootToNodePath(root->left, nodeValue, isFound, answer);
   rootToNodePath(root->right, nodeValue, isFound, answer);
   if(!isFound) answer.pop_back();

}


int main(){
   TreeNode* rootNode = new TreeNode(1);
   TreeNode* leftNode = new TreeNode(2);
   TreeNode* rightNode = new TreeNode(3);
   //rootNode->left = leftNode;
   //rootNode->right = rightNode;
   //printTree(rootNode);
   int answer = kthsmallest(rootNode, 1);
   cout<<answer;
   return 0;
}