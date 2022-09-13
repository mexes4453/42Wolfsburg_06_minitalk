/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:16:20 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 10:16:20 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "comm_bonus.h"

static t_sigdata	g_sd;

/**
 * @brief   This function is the handler function which is executed
 *          when the process receives the signal registered for handling.
 *          The handler stores signal bits received in a queue stored in
 *          a global variable of type t_sigdata by calling ft_queue_push.
 *          
 * @param sig 
 */
void	handler_sigusr(int sig, siginfo_t *sig_info, void *ucontext)
{
	if (sig == SIGUSR1)
		ft_queue_push(&g_sd, 0);
	else if (sig == SIGUSR2)
		ft_queue_push(&g_sd, 1);
	else if (sig == SIGINT)
	{
		free(g_sd.queue);
		ft_printf("\nShutting down Server!\n");
		kill(getpid(), SIGTERM);
	}
	g_sd.pid = sig_info->si_pid;
	g_sd.uc_sigmask = ((ucontext_t *)ucontext)->uc_sigmask;
}

int	ft_sig_handler_init(struct sigaction *sa)
{	
	sa->sa_sigaction = handler_sigusr;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_printf("\nError: sigaction SIGUSR1");
		return (-1);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_printf("\nError: sigaction SIGUSR2");
		return (-1);
	}
	if (sigaction(SIGINT, sa, NULL) < 0)
	{
		ft_printf("\nError: sigaction SIGUSR2");
		return (-1);
	}
	return (0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_g_var_init(&g_sd);
	ft_print_pid();
	ft_sig_handler_init(&sa);
	while (1)
	{
		pause();
		if (ft_queue_pop(&g_sd) == -1)
			pause();
		else
		{
			g_sd.recv_chr |= (g_sd.recv_bit << g_sd.sig_cnt);
			if (g_sd.sig_cnt == (BIT_SIZE_CHAR - 1))
			{
				write(1, &(g_sd.recv_chr), 1);
				if (g_sd.recv_chr == '\n')
					ft_send_string("Acknowledged", g_sd.pid);
				g_sd.recv_chr = 0;
			}
			g_sd.sig_cnt = (g_sd.sig_cnt + 1) % BIT_SIZE_CHAR;
		}
	}
	return (0);
}
