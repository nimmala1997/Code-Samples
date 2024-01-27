#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTNode{
   public:
         T data;
         BTNode<T> * left;
         BTNode<T> * right;
         
         BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
         }
         
         ~BTNode(){
            delete left;
            delete right;
         }

};

void printTree(BTNode<int>* root){
        if(root == NULL)
          return;

         cout<<root->data<<" ";

         if(root->left != NULL)
            cout<<"L"<<root->left->data;
         if(root->right != NULL)
            cout<<"R"<<root->right->data;
         
         cout<<endl;
         printTree(root->left);
         printTree(root->right);
}

BTNode<int>* takeInput(){
         int data;
         cout<<"Enter root Value";
         cin>>data;
         
         if(data == -1)
           return NULL;
         
         BTNode<int>* root = new BTNode<int>(data);
         root->left = takeInput();
         root->right = takeInput();

         return root;

}

BTNode<int>* takeInputLevelWise(){
         int data;
         cin>>data;
         cout<<endl;

         if(data == -1)
           return NULL;
         
         queue<BTNode<int>*> nodeQueue;
         BTNode<int>* root = new BTNode<int>(data);
         nodeQueue.push(root);

         while (!nodeQueue.empty())
         {
            BTNode<int>* firstNodeinQueue = nodeQueue.front();
            nodeQueue.pop();
            int leftData,rightData;

            cin>>leftData;
            if(leftData != -1){
               BTNode<int>* leftNode = new BTNode<int>(leftData);
               firstNodeinQueue->left = leftNode;
               nodeQueue.push(leftNode);
            }

            cin>>rightData;
            if(rightData != -1){
               BTNode<int>* rightNode = new BTNode<int>(rightData);
               firstNodeinQueue->right = rightNode;
               nodeQueue.push(rightNode);
            }
         }

         return root;
         
}

int countNoOfNodes(BTNode<int>* root){
            int count = 0;

            if(root == NULL)
              return count;

            int leftNodes = countNoOfNodes(root->left);
            int rightNodes = countNoOfNodes(root->right);

            return 1+leftNodes+rightNodes;
}

void minValueofTree(BTNode<int>* root, int &ans){
            if(root == NULL)
               return;

            ans = min(root->data,ans);
            minValueofTree(root->left,ans);
            minValueofTree(root->right,ans);

}

void maxValueofTree(BTNode<int>* root, int &ans){
            if(root == NULL)
               return;

            ans = max(root->data,ans);
            maxValueofTree(root->left,ans);
            maxValueofTree(root->right,ans);

}

int leftLeafNodesCount(BTNode<int>* root){
            if(root == NULL)
               return 0;
            
            int count = 0;
            if(root->left != NULL){
               if(root->left->left == NULL && root->left->right == NULL){
                  count++;
               }
               else{
                  count = leftLeafNodesCount(root->left);
               }
            }
            count += leftLeafNodesCount(root->right);
            return count;

}

int rightLeafNodesCount(BTNode<int>* root){
            if(root == NULL)
               return 0;

            int count = 0;
            if(root->right != NULL){
               if(root->right->left == NULL && root->right->right == NULL)
                count++;
               else 
                 count = rightLeafNodesCount(root->right);
            }
            count += rightLeafNodesCount(root->left);
            
            return count;
}

int main(){
         //BTNode<int>* root = new BTNode<int>(1);
         //BTNode<int>* leftchild = new BTNode<int>(2);
         //BTNode<int>* rightchild = new BTNode<int>(3);
         
         //root->left = leftchild;
         //root->right = rightchild;
         BTNode<int>* root = takeInputLevelWise();
         //printTree(root);
         //int noOfNodes = countNoOfNodes(root);
         //cout<<noOfNodes;
         int ans = INT_MIN;
         //maxValueofTree(root,ans);
         //cout<<ans;
         int leftLeafNodes = leftLeafNodesCount(root);
         int rightLeafNodes = rightLeafNodesCount(root);
         cout<<leftLeafNodes<<" "<<rightLeafNodes;
         delete root;
         return 0;
}