#include <iostream>
#include <vector>
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

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        while (lists.size() > 1) {
			int i = 0, j = lists.size() - 1;
			while (i < j) {
				lists[i] = mergeTwoLists(lists[i], lists[j]);
				i++, j--;
				lists.pop_back();
			}
        }
        return lists[0];
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
	addNode(&h1, 5);
	addNode(&h1, 9);
	addNode(&h1, 11);
	addNode(&h1, 13);
	addNode(&h1, 14);
	addNode(&h1, 19);
	addNode(&h1, 20);
	addNode(&h1, 50); 

	ListNode h2(2);
	addNode(&h2, 20);
	addNode(&h2, 50);
	addNode(&h2, 51);
	addNode(&h2, 61);
	addNode(&h2, 100);
	addNode(&h2, 220);
	addNode(&h2, 230);
	addNode(&h2, 400);

	ListNode h3(1);
	addNode(&h3, 3);
	addNode(&h3, 5);
	addNode(&h3, 6);
	addNode(&h3, 7);
	addNode(&h3, 8);
	addNode(&h3, 21);
	addNode(&h3, 90);
	addNode(&h3, 500);

	vector<ListNode *> vec;
	ListNode *ph1 = NULL, *ph2 = NULL;
	vec.push_back(&h1);
	vec.push_back(&h2);
	vec.push_back(&h3);

	ListNode *p = s.mergeKLists(vec);

	while(p) {
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;

	return 0;
}