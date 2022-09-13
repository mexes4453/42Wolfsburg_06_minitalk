/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:33:56 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/07 09:33:56 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "queue.h"

/**
 * @brief  This is sends one character bit by bit by transmission using signals
 *         each bit of the character is transmitted with the help of
 *         two signals. One signal sends zero (0) and the other sends
 *         one (1).
 * 
 * @param chr 
 * @param proc_id 
 * @return int 
 */
int	ft_send_byte(char chr, int proc_id)
{
	int	idx;

	idx = 0;
	while (idx < BIT_SIZE_CHAR)
	{
		if ((chr & (1 << idx)) == 0)
		{
			if (kill(proc_id, SIGUSR1) < 0)
				return (-1);
		}
		else
		{
			if (kill(proc_id, SIGUSR2) < 0)
				return (-1);
		}
		usleep(DELAY_US);
		idx++;
	}
	return (0);
}

/**
 * @brief   This function sends each character in a string to another process
 *          with the provided process id. This is achieved by calling the 
 *          ft_send_byte which sends the binary bits of each character to a
 *          given process id using the signals (SIGUSR1 [0] & SIGUSR2 [1]).
 *          Each string sent is terminated with a newline character
 * todo     pre-requisite function: ft_send_byte
 * 
 * @param str 
 * @param proc_id 
 * @return int 
 */
int	ft_send_string(char *str, int proc_id)
{
	int	idx;
	int	str_len;

	idx = 0;
	str_len = ft_strlen(str);
	while (idx < str_len)
	{
		if (ft_send_byte(str[idx], proc_id) < 0)
			return (-1);
		idx++;
	}
	ft_send_byte('\n', proc_id);
	return (1);
}

/**
 * @brief 		This function prints the process id of the a process when
 * 				called within the process.
 * 				It return 0 on success and returns -1 on error.
 * 
 * @return int 
 */
int	ft_print_pid(void)
{
	char	*pid_server;

	pid_server = ft_itoa(getpid());
	if (pid_server == NULL)
		return (-1);
	ft_printf("%s\n", pid_server);
	free(pid_server);
	return (0);
}

/**
 * @brief 	This function initialises the global variable where the main
 * 			function is defined.
 * 			It return 0 on success and returns -1 on error.
 * 
 * @param sd 
 * @return int 
 */
int	ft_g_var_init(t_sigdata *sd)
{
	if (ft_queue_create(&(sd->queue)) < 0)
		return (-1);
	sd->front = 0;
	sd->rear = 0;
	sd->sig_cnt = 0;
	sd->recv_chr = 0;
	sd->recv_bit = 0;
	sd->pid = 0;
	return (0);
}
