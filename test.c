/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:31:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/09 19:58:24 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


static t_dir       *push_back(t_dir *lst, int value)
{
    t_dir *new_node;
    t_dir *pos;

    if ((new_node = (t_dir*)malloc(sizeof(t_dir))) == NULL)
        return (NULL);
    new_node->number = value;
    new_node->next = NULL;
    pos = lst;
    while (pos && pos->next)
    {
        pos = pos->next;
    }
    pos->next = new_node;
    return (lst);
}

static int    swap(t_dir *prev, t_dir *current, t_dir *next)
{
    t_dir   *tmp;

    tmp = next;
    if (current->number > next->number)
    {
        current->next = next->next;
        next->next = current;
        prev->next = tmp;
        return (1);
    }
    return (0);
}

void        display(t_dir *lst)
{
    while (lst)
    {
        printf("%d, ", lst->number);
        lst = lst->next;
    }
}

t_dir       *sort(t_dir *lst)
{
    t_dir   *prev;
    t_dir   *current;
    t_dir   *next;
    t_dir   *start;
    int     sorted;

    sorted = 1;
    start = lst->next;
    prev = lst;
    current = start;
    next = current->next;
    lst = lst->next;
    int i = 0;
    int j = 0;
    while (sorted)
    {
        sorted = 0;
        while (next)
        {
            printf("current->number: %d > next->number: %d ? \n", current->number, next->number);
            ++i;
            if (swap(prev, current, next))
            {
                sorted = 1;
                prev = next;
                next = next->next;
            }
            else
            {
                printf("Le else\n");                /*    <----- DEBUG -------|    */
                prev = prev->next;
                current = current->next;
                next = next->next;
            }
        }
        ++j;
        printf("%d passage pour %d iterrations\n", j, i);
    }
    return (start);
}

int         main(void)
{
    t_dir *lst;

    if ((lst = (t_dir *)malloc(sizeof(t_dir))) == NULL)
        return (0);
    lst->next = NULL; 
    lst = push_back(lst, 38);
    lst = push_back(lst, 18);
    lst = push_back(lst, 2);
    lst = push_back(lst, 34);

    display(lst->next);
    printf("\n");
    sort(lst);
    printf("\n");
    display(lst->next);
    printf("\n");

    return (0);
}
