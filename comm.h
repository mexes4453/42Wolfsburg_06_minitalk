/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:31:06 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/07 09:31:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMM_H
# define COMM_H
# include "data_type_const.h"
# include "libft/libft.h"
# include "queue.h"
# include <signal.h>

// -- FUNCTION DECLARATION --
int		ft_send_byte(char chr, int proc_id);
int		ft_send_string(char *str, int proc_id);
int		ft_print_pid(void);
int		ft_g_var_init(t_sigdata *sd);
#endif  // COMM_H
