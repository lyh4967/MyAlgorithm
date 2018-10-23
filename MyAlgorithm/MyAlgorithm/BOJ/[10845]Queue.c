#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

void init_Q(Queue* que) {
	que->front = NULL;
	que->rear = NULL;
	que->size = 0;
}
void push(Queue* que, int _value) {
	Node *nPtr = (Node*)malloc(sizeof(Node));
	nPtr->value = _value;
	if (que->front == NULL) {
		que->front = nPtr;
		que->rear = nPtr;
		nPtr->next = NULL;
	}
	else {
		que->rear->next = nPtr;
		nPtr->next = NULL;
		que->rear = nPtr;
	}
	que->size++;
}

int getFront(Queue* que) {
	if (que->front == NULL) {
		return -1;
	}
	else {
		return que->front->value;
	}
}
int getBack(Queue* que) {
	if (que->rear == NULL) {
		return -1;
	}
	else
		return que->rear->value;
}

int pop(Queue* que) {
	if (que->front == NULL) {
		return -1;
	}
	else {
		int value = que->front->value;
		Node* tmp = que->front;
		que->front = que->front->next;
		if (que->front == NULL)
			que->rear = NULL;
		free(tmp);
		que->size--;
		return value;
	}
}

int empty(Queue* que) {
	return que->front == NULL;
}
int getSize(Queue* que) { return que->size; }
int main() {

	int N; scanf("%d", &N);
	char command[10];
	Queue* que = (Queue*)malloc(sizeof(Queue));
	init_Q(que);
	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (!strcmp(command, "push")) {
			int num; scanf("%d", &num);
			push(que, num);
		}
		else if (!strcmp(command, "front")) {
			printf("%d\n", getFront(que));
		}
		else if (!strcmp(command, "back")) {
			printf("%d\n", getBack(que));
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", getSize(que));
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", pop(que));
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", empty(que));
		}
	}
	return 0;
}