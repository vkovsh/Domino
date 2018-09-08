/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 15:55:42 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/10 15:56:06 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <vector>
# include <sstream>

std::vector<std::string>			explode(const std::string & str, char delimit);
bool								str_isdigit(std::string token);

#endif