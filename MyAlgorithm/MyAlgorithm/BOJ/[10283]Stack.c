#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct Stack {
	int length;
	Node* top;
} Stack;

void init(Stack* sta) {
	sta->length = 0;
	sta->top = NULL;
}
void push(Stack* sta, int _value) {
	Node* nPtr = (Node*)malloc(sizeof(Node));

	nPtr->value = _value;
	nPtr->next = sta->top;
	sta->top = nPtr;
	sta->length++;
}
int pop(Stack* sta) {
	if (sta->length > 0) {
		Node* temp = sta->top;
		sta->top = temp->next;
		int num = temp->value;
		free(temp);
		sta->length--;
		return num;
	}
	else {
		return -1;
	}
}
int top(Stack* sta) {
	if (sta->length == 0) {
		return -1;
	}
	else {
		return sta->top->value;
	}
}
int empty(Stack* sta) { return sta->length == 0; }
int size(Stack* sta) { return sta->length; }
void clear(Stack* sta) {
	while (!empty(sta)) pop(sta);
}

int main() {

	int N; scanf("%d", &N);
	char command[10];
	Stack* sta = (Stack*)malloc(sizeof(Stack));
	init(sta);
	for (int i = 0; i < N; i++) {
		scanf("%s", command);
		//printf("log1: %s\n", command);
		if (!strcmp(command, "push")) {
			int num; scanf("%d", &num);
			//printf("log: %d\n", num);
			push(sta, num);
		}
		else if (!strcmp(command, "top")) {
			printf("%d\n", top(sta));
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", size(sta));
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", pop(sta));
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", empty(sta));
		}
	}




	return 0;
}