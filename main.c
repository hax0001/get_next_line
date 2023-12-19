/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:50:14 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/19 21:57:03 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
    int fd = open("haax", O_RDONLY);
    char    *str = get_next_line(fd);
    printf("%s\n",str);
    free(str);
    char    *st = get_next_line(fd);
    printf("%s\n",st);
    free(st);
        char    *s = get_next_line(fd);
    printf("%s\n",s);
    free(s);
}