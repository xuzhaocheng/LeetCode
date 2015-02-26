// 2 Add Two Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

// 注意将{9, 9} + {9}这种情况，
// 不光把多余的位连接起来，还要检查是否进位。
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *h1 = l1;
		ListNode *pre1;
		while(true) {
			l1->val += l2->val;
			if (l1->val >= 10) {
				l1->val -= 10;
				if (l1->next != NULL) {
					l1->next->val += 1;
				} else {
					ListNode *node = (ListNode *)malloc(sizeof(struct ListNode));
					node->val = 1;
					node->next = NULL;
					l1->next = node;
				}
			}
			pre1 = l1;
			l1 = l1->next;
			l2 = l2->next;

			if (l1 == NULL || l2 == NULL) break;
		}

		if (l2) {
			pre1->next = l2;
		}

		pre1 = pre1->next;
		while(pre1 && pre1->val >= 10) {
			
				pre1->val -= 10;
				if (pre1->next != NULL) {
					pre1->next->val += 1;
				} else {
					ListNode *node = (ListNode *)malloc(sizeof(struct ListNode));
					node->val = 1;
					node->next = NULL;
					pre1->next = node;
				}
			

			pre1 = pre1->next;
		}

		return h1;

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

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	
	ListNode h1(9);
	addNode(&h1, 9);
/*	addNode(&h1, 3);
	addNode(&h1, 6);
	addNode(&h1, 7);
	addNode(&h1, 3);
	addNode(&h1, 2);
	addNode(&h1, 1);
	addNode(&h1, 5); */



	ListNode h2(9);
/*	addNode(&h2, 2);
	addNode(&h2, 5);
	addNode(&h2, 5);
	addNode(&h2, 6);
	addNode(&h2, 1);
	addNode(&h2, 2);
	addNode(&h2, 2);
	addNode(&h2, 4);*/

	
	ListNode *p = solution.addTwoNumbers(&h1, &h2);
	
	while(p) {
		cout << p->val << " -> ";
		p = p->next;
	}

	return 0;
}

