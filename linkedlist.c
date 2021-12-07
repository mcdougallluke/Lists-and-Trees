/* ***********************************************/
/* Luke McDougall                                             */
/* 11/10/2021                                                    */
/* CS-241 Section 1                                            */
/*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


struct ListNode* createNode(char data)
{
  struct ListNode* node = malloc(sizeof(struct ListNode));
  node -> data = data;
  node -> next = NULL;
  return node;
}

/* Insert data at appropriate place in a sorted list, return new list head. */
struct ListNode* insertSorted(struct ListNode* head, char data)
{
  struct ListNode* newNode;
  struct ListNode* currentNode;
  struct ListNode* previousNode;

  if (head == NULL)
  {
    return createNode(data);
  }
  newNode = createNode(data);

  if (head->next == NULL || data < head->data)
  {
    newNode->next = head;
    return newNode;
  }

  currentNode = head;
  previousNode = NULL;

  while (currentNode != NULL && data >= currentNode->data)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
  previousNode-> next = newNode;
  newNode->next = currentNode;

  return head;
}

/* Remove data from list pointed to by headRef, changing head if necessary.
 * Make no assumptions as to whether the list is sorted.
 * Memory for removed node should be freed.
 * Return 1 if data was present, 0 if not found. */
int removeItem(struct ListNode** headRef, char data)
{
  struct ListNode* currentNode;
  struct ListNode* previousNode;
  struct ListNode* oldHead;

  if (headRef == NULL || *headRef == NULL)
  {
    return 0;
  }

  currentNode = *headRef;
  previousNode = NULL;

  if ((*headRef)->data == data)
  {
    oldHead = *headRef;
    *headRef = (*headRef)->next;
    free(oldHead);
    return 1;
  }

  while (currentNode != NULL && currentNode->data != data)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  if (currentNode == NULL)
  {
    return 0;
  }

  previousNode->next = currentNode->next;
  free(currentNode);
  return 1;
}

/* Treat list as a stack. (LIFO - last in, first out)
 * Insert data at head of list, return new list head. */
struct ListNode* pushStack(struct ListNode* head, char data)
{
  struct ListNode* newHead = createNode(data);

  newHead->next = head;
  return newHead;
}

/* Treat list as a stack. (LIFO - last in, first out)
 * Remove and return data from head of non-empty list, changing head.
 * Memory for removed node should be freed. */
char popStack(struct ListNode** headRef)
{
  struct ListNode* poppedNode = *headRef;
  char data = poppedNode->data;

  *headRef = poppedNode->next;
  free(poppedNode);

  return data;
}

/* Return length of the list. */
int listLength(struct ListNode* head)
{
  struct ListNode* current = head;
   int count = 0;
  while (current != NULL)
  {
    count++;
    current = current -> next;
  }
  return count;
}

/* Print list data on single line, separating values with a comma and
 * a space and ending with newline. */
void printList(struct ListNode* head)
{
  if (head == NULL)
  {
    printf("\n");
  }
  else
  {
    if (head->next == NULL)
    {
      printf("%c", head->data);
    }
    else
    {
      printf("%c, ", head->data);
    }
    printList(head->next);
    }
}

/* Free memory used by the list. */
void freeList(struct ListNode* head)
{
  if (head != NULL)
  {
    free(head);
    freeList(head->next);
  }
}

/* Reverse order of elements in the list */
void reverseList(struct ListNode** headRef)
{
  struct ListNode* previousNode = NULL;
  struct ListNode* currentNode = *headRef;
  struct ListNode* nextNode = NULL;

  while (currentNode != NULL)
  {
    nextNode = currentNode->next;
    currentNode->next = previousNode;

    previousNode = currentNode;
    currentNode = nextNode;
    }
  *headRef = previousNode;
}