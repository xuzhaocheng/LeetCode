#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if (n == 0)	return head;

        ListNode *p = head;
        ListNode *n_pre_pre = head;

        int i = 0;
        while(p && i < n) {
        	p = p->next;
        	i++;
        }

        if (!p && i == n) {
        	return head->next;
        } else if (!p) return head;
      
        while(p) {
        	p = p->next;
        	if (p) n_pre_pre = n_pre_pre->next;
        }

        n_pre_pre->next = n_pre_pre->next->next;

        return head;
    }
};

void addNode(ListNode *p, int v) {
	ListNode *newNode = (ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = v;
	newNode->next = NULL;
	ListNode *node = p;
	while(node->next != NULL)	node = node->next;
	
	node->next = newNode;
}

int main(void) {
	ListNode h1(1);
	addNode(&h1, 2);
	addNode(&h1, 3);
	addNode(&h1, 4);
	addNode(&h1, 5);
	
	Solution s;
	ListNode *head = s.removeNthFromEnd(&h1, 6);

	while(head) {
		cout << head->val << " ";
		head = head->next;
	} 
	cout << endl;
	return 0;
}