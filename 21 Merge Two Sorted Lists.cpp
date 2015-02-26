#include <iostream>
#include "stdlib.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	if (!l1)	return l2;
    	if (!l2)	return l1;

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = NULL;
        
        if (p1->val > p2->val) {
        	head = p2;
        	p2 = p2->next;
        } else {
        	head = p1;
        	p1 = p1->next;
        }

        ListNode *p = head;
        
        while (p1 && p2) {
        	if (p1->val < p2->val) {
        		p->next = p1;
        		p1 = p1->next; 
        	} else {
        		p->next = p2;
        		p2 = p2->next;
        	}
        	p = p->next;
        }

        if (p1) p->next = p1;
        if (p2) p->next = p2;

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
	Solution s;
	ListNode h1(1);
	addNode(&h1, 3);
	addNode(&h1, 5);
	addNode(&h1, 6);
	addNode(&h1, 7);
	addNode(&h1, 10);
	addNode(&h1, 18);
	addNode(&h1, 22);
	addNode(&h1, 80);

	ListNode h2(2);
/*	addNode(&h2, 4);
	addNode(&h2, 8);
	addNode(&h2, 9);
	addNode(&h2, 11);
	addNode(&h2, 12);
	addNode(&h2, 13);
	addNode(&h2, 18);
	addNode(&h2, 30);*/

	ListNode *head = s.mergeTwoLists(&h1, NULL);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

	return 0;
}