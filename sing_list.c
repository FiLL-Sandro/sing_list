#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define take_errno_str(_cause) \
	if ((_cause) != NULL) *(_cause) = strerror(errno);

typedef struct item
{
	char c;
	struct item *next;
} item_t;

inline static bool is_empty(item_t *head)
{
	return head == NULL;
}

inline static item_t* create_item(const char **cause)
{
	item_t *i = (item_t*)malloc(sizeof(item_t));

	if (i == NULL)
		take_errno_str(cause)
	else
		i->next = NULL;

	return i;
}

inline static item_t* go_to_end(item_t *head)
{
	while (head->next != NULL) head = head->next;

	return head;
}

int push_back(item_t **head, char c, const char **cause);
void print_list(item_t *head);

int main(void)
{
	item_t *head = NULL;
	const char *cause;

	push_back(&head, 'q', &cause);
	push_back(&head, 'w', &cause);
	push_back(&head, 'e', &cause);
	push_back(&head, 'r', &cause);
	push_back(&head, 't', &cause);
	push_back(&head, 'y', &cause);

	print_list(head);

	exit(EXIT_SUCCESS);
}

int push_back(item_t **head, char c, const char **cause)
{
	int ret_f = 0;

	if (head != NULL)
	{
		item_t *tmp_item = NULL;

		if (is_empty(*head) == true)
		{
			*head = create_item(cause);
			if (*head == NULL)
				ret_f = -1;
			else
				tmp_item = *head;
		}
		else
		{
			tmp_item = go_to_end(*head);
			tmp_item->next = create_item(cause);
			if (tmp_item->next == NULL)
				ret_f = -1;
			else
				tmp_item = tmp_item->next;
		}

		if (ret_f != -1)
		{
			tmp_item->c = c;
			tmp_item->next = NULL;
		}
	}

	return ret_f;
}

void print_list(item_t *head)
{
	printf("Printing list:\n");

	while (is_empty(head) == false)
	{
		printf("%c ", head->c);
		head = head->next;
	}

	printf("\n--------------\n");
}

