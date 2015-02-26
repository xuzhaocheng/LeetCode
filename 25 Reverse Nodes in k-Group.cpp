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
	/**
	* 注意赋值hh时将hh->next置为NULL
	**/
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if (!head) return NULL;
    	if (k == 0 || k == 1)	return head;

        ListNode node(0);
        node.next = head;

        ListNode *h = &node;

        ListNode *hh = h;
        ListNode *p = hh->next;
        ListNode *tail = p;
        int cnt = 0;

        hh->next = NULL;
        while (p) {
        	ListNode *tmp = p->next;
        	p->next = hh->next;
        	hh->next = p;
        	
        	p = tmp;
        	cnt++;

        	if (cnt % k == 0) {
        		hh = tail;
        		hh->next = NULL;
        		tail = tmp;
        	}
        }
        
        if (cnt % k != 0) {
        	p = hh->next;
        	hh->next = NULL;
        	while (p) {
        		ListNode *tmp = p->next;
        		p->next = hh->next;
        		hh->next = p;
        		p = tmp;
        	}
        }

        return h->next;
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
/*	addNode(&h1, 2);
	addNode(&h1, 3);
	addNode(&h1, 4);
	addNode(&h1, 5);
	addNode(&h1, 6);
	addNode(&h1, 7);
	addNode(&h1, 8);
	addNode(&h1, 9); 
*/
	ListNode *p = s.reverseKGroup(NULL, 1);

	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;

	return 0;
}