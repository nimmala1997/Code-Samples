#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
   public:
         T val;
         vector<TreeNode<T>*> children;

         TreeNode(T val):val(val){}

};

template<typename T>
void printTree(TreeNode<T>* node){
         if(node == NULL)
            return;

         cout<<node->val<<":";

         for(int i = 0 ; i < node->children.size();i++){
            cout<<node->children.at(i)->val<<",";
         }

         cout<<endl;

         for(int i = 0 ; i < node->children.size(); i++){
            printTree(node->children.at(i));
         }
}

TreeNode<int>* takeInput(){
         int rootData;
         cout<<"enter data ";
         cin>>rootData;
         TreeNode<int>* root = new TreeNode<int>(rootData);
         cout<<"Enter no of children for "<<root->val<<endl;
         int noOfChildren;
         cin>>noOfChildren;

         for(int i = 0 ; i < noOfChildren; i++){
            cout<<"Enter "<<i+1<<" child "<<"for "<<rootData<<endl;
            root->children.push_back(takeInput());
         }

         return root;
}

TreeNode<int>* takeInputIterative(){
        int rootData;
        cout<<"Enter Root Value ";
        cin>>rootData;
        TreeNode<int>* root = new TreeNode<int>(rootData);
        queue<TreeNode<int>*> allNodes;
        allNodes.push(root);

        while(!allNodes.empty()){
            int noOfChildren;
            cout<<"Enter no of children for "<<allNodes.front()->val<<endl;
            cin>>noOfChildren;

            for(int i = 0 ; i < noOfChildren ; i++){
               int temp;
               cin>>temp;
               TreeNode<int>* childNode = new TreeNode<int>(temp);
               allNodes.front()->children.push_back(childNode);
               allNodes.push(childNode);
            }

            allNodes.pop();
        }

        return root;
}

void printLevelOrder(TreeNode<int>* root){
        if(root == NULL)
         return;
        queue<TreeNode<int>* > allNodes;
        allNodes.push(root);

        while(!allNodes.empty()){
         TreeNode<int>* firstNodeinQueue = allNodes.front();
         allNodes.pop();
         cout<<firstNodeinQueue->val<<":";

         for(int i = 0 ; i < firstNodeinQueue->children.size();i++){
            cout<<firstNodeinQueue->children.at(i)->val<<",";
            allNodes.push(firstNodeinQueue->children.at(i));
         }

         cout<<endl;
        }
}

int countNoOfNodes(TreeNode<int>* root){
        if(root == NULL)
         return 0;
        int count = 1;

        for(int i = 0 ; i < root->children.size() ; i++ ){
         count += countNoOfNodes(root->children.at(i));
        }

        return count;
}

int heightOfTheTree(TreeNode<int>* root){
        if(root == NULL)
         return 0;
        int count = 1;
        int maxHeight = 0;

        for(int i = 0 ; i < root->children.size(); i++){
          maxHeight = max(maxHeight,heightOfTheTree(root->children.at(i)));
        }

        return count+maxHeight;
}
void printAtLevelK(TreeNode<int>* root,int k ){
        if(root == NULL)
         return;
         
        if(k == 0){
         cout<<root->val;
         return;
        }

        for(int i = 0 ; i < root->children.size() ;i++){
         printAtLevelK(root->children.at(i),k-1);
        }
}

int main(){
         //TreeNode<int>* root = new TreeNode<int>(1);
         //TreeNode<int>* n1 = new TreeNode<int>(2);
         //TreeNode<int>* n2 = new TreeNode<int>(3);

         //root->children.push_back(n1);
         //root->children.push_back(n2);
         TreeNode<int>* root = takeInputIterative();
         //printLevelOrder(root);
         //int totalNodes = countNoOfNodes(root);
         //cout<<totalNodes;
         int height = heightOfTheTree(root);
         cout<<height;

         return 0;

}