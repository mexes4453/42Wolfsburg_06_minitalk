/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:21:10 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 10:21:10 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMM_BONUS_H
# define COMM_BONUS_H
# include "data_type_const_bonus.h"
# include "libft/libft.h"
# include "queue_bonus.h"
# include <signal.h>

// -- FUNCTION DECLARATION --
int		ft_send_byte(char chr, int proc_id);
int		ft_send_string(char *str, int proc_id);
int		ft_print_pid(void);
int		ft_g_var_init(t_sigdata *sd);
int		ft_check_usr_inp(int arg_cnt, char **argv_str);
#endif  // COMM_H
