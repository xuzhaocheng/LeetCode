#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
     	if (!head) return head;

     	ListNode *p = head->next;
     	ListNode *pre = head;

     	if (!p) return head;
     	ListNode *h = p;
		ListNode *next = p->next;
     	
     	pre->next = next;
     	p->next = pre;
     	pre = p;
     	p = pre->next;

     	int cnt = 0;

     	while (next) {
     		if (cnt & 1) {
     			pre->next = next;
     			p->next = next->next;
     			next->next = p;

     			next = p;
     			p = pre->next;
     		}

     		pre = p;
     		p = next;
     		next = next->next;
     		cnt++;
     	}
     	return h;
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
	addNode(&h1, 2);
	addNode(&h1, 3);
	addNode(&h1, 4);
	addNode(&h1, 5);
	addNode(&h1, 6);
	addNode(&h1, 7);
	addNode(&h1, 8);
	addNode(&h1, 9); 

	ListNode *p = s.swapPairs(&h1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}

