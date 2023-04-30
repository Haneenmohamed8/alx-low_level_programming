#include "lists.h"

/**
 * find_listint_loop - Finds the node where a loop starts in a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: If a loop is found - the address of the node where the loop starts.
 *If no loop is found - NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    if (head == NULL || head->next == NULL)
        return (NULL);

    slow = head->next;
    fast = head->next->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow);
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return (NULL);
}
