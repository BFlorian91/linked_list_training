/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:31:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/10 18:05:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"

void        push_back(t_dir **lst, int value)
{
    t_dir *new_node;
    t_dir *pos;

    if (!lst)
        return ;
    if ((new_node = (t_dir*)malloc(sizeof(t_dir))) == NULL)
        return ;
    new_node->number = value;
    new_node->next = NULL;
    if (!*lst)
        *lst = new_node;
    else
    {
        pos = *lst;
        while (pos && pos->next)
        {
            pos = pos->next;
        }
        pos->next = new_node;
    }
}

void        display(t_dir *lst)
{
    while (lst)
    {
        printf("%d, ", lst->number);
        lst = lst->next;
    }
}

void        lst_insert(t_dir **lst, t_dir *node)
{
    t_dir   *current;
    t_dir   *tmp;

    current = *lst;
    if (!current)
        *lst = node;
    else if (current->number > node->number)
    {
        *lst = node;
        node->next = current;
    }
    else
    {
        while (current->next && current->next->number <= node->number)
            current = current->next;
        tmp = current->next;
        current->next = node;
        node->next = tmp;
    }
}

void       sort(t_dir **lst)
{
    t_dir   *nlst;
    t_dir   *current;
    t_dir   *tmp;

    nlst = NULL;
    if (!lst)
        return ;
    current = *lst;
    while (current)
    {
        tmp = current->next;
        current->next = NULL;
        lst_insert(&nlst, current);
        current = tmp;
    }
    *lst = nlst;
}

int         main(void)
{
    t_dir *lst;

    push_back(&lst, 38);
    push_back(&lst, 18);
    push_back(&lst, 2);
    push_back(&lst, 34);
    push_back(&lst, 138);
    push_back(&lst, 8);
    push_back(&lst, 2);
    push_back(&lst, 0);

    display(lst);
    printf("\n");
    sort(&lst);
    printf("\n");
    display(lst);
    printf("\n");

    return (0);
}
