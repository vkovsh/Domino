/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_none.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:39:00 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 16:43:29 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			join_none(t_pfargs *pf)
{
	pf->spec.type = c;
	join_value(&(pf->output), ((t_value *)((pf->t)->content))->value, pf->spec);
}
