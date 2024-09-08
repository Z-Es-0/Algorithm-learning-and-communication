#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

// 初始化栈
void initStack(Stack* stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(sizeof(int) * capacity);
}

// 检查栈是否为空
bool is_empty(Stack* stack) {
    return stack->top == -1;
}

// 检查栈是否已满
bool is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// 压入元素到栈
void push(Stack* stack, int item) {
    if (is_full(stack)) {
        printf("Stack is full, cannot push.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// 弹出栈顶元素
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty, cannot pop.\n");
        exit(EXIT_FAILURE); // 或者返回一个特殊值，表示错误
    }
    return stack->items[stack->top--];
}

// 返回栈的当前长度
int howlong(Stack* stack) {
    return stack->top + 1;
}

// 销毁栈
void freeStack(Stack* stack) {
    free(stack->items);
}

// 示例使用
int main() {
    Stack stack;
    initStack(&stack, 10); // 初始化栈，容量为10

    push(&stack, 1);
    push(&stack, 2);
    printf("Popped: %d\n", pop(&stack));
    printf("Stack length: %d\n", howlong(&stack));

    freeStack(&stack); // 释放栈占用的内存
    return 0;
}