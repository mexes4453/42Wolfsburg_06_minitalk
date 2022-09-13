/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:44:10 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/06 13:44:10 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <stdint.h>
#include "libft/libft.h"
#include "comm.h"

int	main(int argc, char *argv[])
{
	int	pid_server;

	pid_server = 0;
	if (argc != 3)
	{
		ft_printf("Error: argument missing\n");
		return (-1);
	}
	else
	{
		pid_server = ft_atoi(argv[1]);
		if (kill(pid_server, 0) < 0)
		{
			ft_printf("Error: Process does not exist\n");
			return (-1);
		}
		if (ft_send_string(argv[2], pid_server) < 0)
			ft_printf("\nError: ft_send_string\n");
	}
	return (0);
}
