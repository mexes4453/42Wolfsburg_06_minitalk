/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type_const_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:20:43 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/19 12:31:21 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_CONST_BONUS_H
# define DATA_TYPE_CONST_BONUS_H
# define BIT_SIZE_CHAR (8)
# define FIFO_SIZE (200)
# define DELAY_US_SEND_BIT (300)
# include <signal.h>
// -- DATA TYPE ---
typedef struct s_sigdata
{
	unsigned char	*queue;
	sig_atomic_t	front;
	sig_atomic_t	rear;
	unsigned char	recv_chr;
	unsigned char	recv_bit;
	int				sig_cnt;
	size_t			pid;
	sigset_t		uc_sigmask;
}					t_sigdata;
#endif // DATA_TYPE_CONST_H
