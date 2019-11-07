#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    struct Node *next;
    char value;
} Node;

static Node *head = NULL;

Node* getLast(void)
{
    Node *i = head;

    if (head == NULL) return NULL;

    while (i->next != NULL) i = i->next;

    return i;
}


void pushBack(const char value) // передаю адрес первого элемента в списке и добавляю значение в конец
{
    Node *last = getLast(); // получаю адес последнего элемента

    if (last == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->value = value;
        head->next = NULL;
    }
    else
    {
        Node *tmp = (Node*) malloc(sizeof(Node)); // создаю временную ноду которую хочу добавить

        tmp->value = value; // кидаю в неё значение
        tmp->next = NULL; // делю так чтобы она ссылалась в ноль (индикация конца списка)
        last->next = tmp;
    }
}


void printLinkedList(void)
{
    Node *i = head;

    while (i) {
        printf("%c ", i->value);
        i = i->next;
    }
    printf("\n");
}


int main(void)
{
    char value = 'a';
    pushBack(value);
    pushBack(value);
    pushBack(value);
    pushBack(value);
    pushBack(value);
    pushBack(value);

    printLinkedList();
    return 0;
}
