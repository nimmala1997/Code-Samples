#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}     
};

 ListNode* oddEvenList(ListNode* head) {
     if(head == NULL || head->next == NULL) return head;
     ListNode* even = head->next;
     ListNode *headCopy, *evenCopy, *temp;
     headCopy = head;
     evenCopy = even;
     temp = head;
     int count = 3;
     head = head->next->next;
     while(head != NULL){
          if(count % 2 != 0){
               temp->next = head;
               temp = head;
          }
          else{
               even->next = head;
          }
          head = head->next;
          count++;
     }
     temp->next = evenCopy;
     return headCopy;
}

int main(){
     
}