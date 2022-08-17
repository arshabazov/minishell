/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:42:02 by cdell             #+#    #+#             */
/*   Updated: 2022/06/14 21:42:05 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_puterror(char *msg)
{
	write(2, "\e[1;31mERROR:\e[0m\n", 19);
	perror(msg);
	exit(EXIT_FAILURE);
}

//void	ft_puterror_alt(char *msg, int error_code)
//{
//	write(2, "\e[1;31mERROR:\e[0m\n", 19);
//	perror(msg);
//	exit(EXIT_FAILURE);
//}
