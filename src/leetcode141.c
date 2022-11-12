#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
//#双指针，#差分器，#链表
bool hasCycle(struct ListNode *head) {
	if (head==NULL || head->next==NULL)
	{
		return false;
	}
	
    struct ListNode *fast=head->next,*slow=head;
	while (fast!=slow)
	{
		if (fast==NULL||slow==NULL)
		{
			return false;
		}
		
		fast=fast->next->next;
		slow=slow->next;

	}
	return true;
}