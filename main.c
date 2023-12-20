/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:50:14 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/20 12:50:31 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
    int fd = open("haax", O_RDONLY);
    char    *str = get_next_line(fd);
    if (str == NULL)
        printf("11\n");
    else
        printf("%s\n",str);
    char    *st = get_next_line(fd);
    if (st == NULL)
        printf("22\n");
    else
        printf("%s\n",st);
    char    *s = get_next_line(fd);
    if (s == NULL)
        printf("33\n");
    else
        printf("%s\n",s);
    char    *tr = get_next_line(fd);
    if (tr == NULL)
        printf("44\n");
    else
        printf("%s\n",tr);
    char    *r = get_next_line(fd);
    if (r == NULL)
        printf("55\n");
    else
        printf("%s\n",r);
}