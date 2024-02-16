#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* t;
	t = head;
	int count = 0;

	while (t != NULL)
	{
		count++;
		t = t->next;
	}
		
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* t = head;
	int size = length(head);
	char* s = (char*)malloc(size*sizeof(char) + 1);
	int i = 0;
    while (t != NULL) {
		s[i] = t->letter;
		i++;
        t = t->next;
    }
	return s;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *t;
	node *temp;

	temp = (node*)malloc(sizeof(node));
	temp->letter = c;
	temp->next = NULL;
	if(*pHead == NULL)
		*pHead = temp;
	else
	{
		t = *pHead;
    	while(t->next!=NULL)
        	t = t->next;

    	t->next = temp;
	}
  return;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* t;
	t = *pHead;

	while(t->next != NULL)
	{
		t = t->next;
		t->next = t->next->next;
		free(t);
	}
	return;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}