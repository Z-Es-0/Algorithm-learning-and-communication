#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
struct node {
    int data;
    struct node* next;
};

// 显示节点数据
void show_node(struct node* x) {
    printf("%d ", x->data); 
}

// 显示链表数据
void show_list(struct node* head) {
    struct node* p = head;
    while (p != NULL) {
        show_node(p);
        p = p->next;
    }
    printf("\n");
}

// 在链表尾部追加节点
void append(struct node* head, int x) {
    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    struct node* re = (struct node*)malloc(sizeof(struct node));
    re->data = x;
    re->next = NULL;
    p->next = re;
}

// 在指定位置添加节点
void add(struct node* head, int x, int index) {
    struct node* p = head;
    int k = 0;
    while (p->next != NULL && k < index - 1) {
        p = p->next;
        k++;
    }
    struct node* re = (struct node*)malloc(sizeof(struct node));
    re->data = x;
    re->next = p->next;
    p->next = re;
}

// 删除最后一个节点
void pop_last(struct node* head) {
    struct node* p = head;
    if (p->next == NULL) {
        head = NULL;
        return;
    }
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

// 删除指定位置节点
void del(struct node* head, int x, int index) {
    struct node* p = head;
    int k = 0;
    while (p->next->next != NULL && k < index - 1) {
        p = p->next;
        k++;
    }
    p->next = p->next->next;
}

// 修改指定位置节点的数据
void revise(struct node* head, int x, int index) {
    struct node* p = head;
    int k = 0;
    while (p->next != NULL && k < index) {
        p = p->next;
        k++;
    }
    p->data = x;
}

// 弹出头节点
void pop_head(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("error\n");
        return;
    }

    struct node* temp = *head_ref;  
    *head_ref = (*head_ref)->next;  
    free(temp);                   
}

// 主函数
int main() {
    // 创建头节点
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    // 向链表中添加数据
    for (int i = 1; i < 20; i++) {
        append(head, i);
    }
    show_list(head);  // 显示链表

    // 弹出头节点并显示链表
    pop_head(&head);
    show_list(head); 

    // 删除最后一个节点并显示链表
    pop_last(head);
    show_list(head); 

    // 在指定位置添加节点并显示链表
    add(head, 12, 4);
    show_list(head);  

    return 0;
}
