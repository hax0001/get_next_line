/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:50:14 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/21 11:57:08 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
    int a = open("1", O_RDONLY);
    char    *str = get_next_line(a);
    if (str == NULL)
        printf("nuul\n");
    else
        printf("%s\n",str);
    free(str);
    int b = open("2", O_RDONLY);
    char    *st = get_next_line(b);
    if (st == NULL)
        printf("nuull\n");
    else
        printf("%s\n",st);
    free(st);
    int c = open("3", O_RDONLY);
    char    *s = get_next_line(c);
    if (s == NULL)
        printf("nuull\n");
    else
        printf("%s\n",s);
    free(s);


    str = get_next_line(a);
    if (str == NULL)
        printf("null\n");
    else
        printf("%s\n",str);
    free(str);
    st = get_next_line(b);
    if (st == NULL)
        printf("nuull\n");
    else
        printf("%s\n",st);
    free(st);
    s = get_next_line(c);
    if (s == NULL)
        printf("nuull\n");
    else
        printf("%s\n",s);
    free(s);


    str = get_next_line(a);
    if (str == NULL)
        printf("nuul\n");
    else
        printf("%s\n",str);
    free(str);
    st = get_next_line(b);
    if (st == NULL)
        printf("nuull\n");
    else
        printf("%s\n",st);
    free(st);
    s = get_next_line(c);
    if (s == NULL)
        printf("nuull\n");
    else
        printf("%s\n",s);
    free(s);



    str = get_next_line(a);
    if (str == NULL)
        printf("nuull\n");
    else
        printf("%s\n",str);
    free(str);
    st = get_next_line(b);
    if (st == NULL)
        printf("nuull\n");
    else
        printf("%s\n",st);
    free(st);
    s = get_next_line(c);
    if (s == NULL)
        printf("nuull\n");
    else
        printf("%s\n",s);
    free(s);
}