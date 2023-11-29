#include <stdio.h>
#include <stdlib.h>

typedef struct listNode_t {
    int data;
    struct listNode_t *next;
} ListNode;

typedef struct {
    ListNode *head;
    int size;
} LinkedList;

void initList(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void insertNode(LinkedList *list, int data, int index) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    
    if (index == 0) {
        node->next = list->head;
        list->head = node;
        return;
    }

    ListNode *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
    list->size++;
}

void removeNode(LinkedList *list, int index) {
    if (index == 0) {
        ListNode *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    ListNode *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    ListNode *temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
}

int main(void) {
    LinkedList list = {NULL, 0};
    initList(&list);

    insertNode(&list, 1, 0);
    insertNode(&list, 2, 1);
    insertNode(&list, 6, 2); // to be removed
    insertNode(&list, 3, 3);
    insertNode(&list, 4, 4);

    removeNode(&list, 2);

    ListNode *current = list.head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    current = list.head;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
