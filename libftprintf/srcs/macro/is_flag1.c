/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:39:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 14:42:00 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_flag1(char c)
{
	if (c == SHARP || c == ZERO ||
		c == MINUS || c == PLUS ||
		c == SPACE)
		return (TRUE);
	return (FALSE);
}
