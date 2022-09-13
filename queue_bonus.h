/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:21:53 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 10:21:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_BONUS_H
# define QUEUE_BONUS_H
# include "data_type_const_bonus.h"
# include "libft/libft.h"
# include <stdlib.h>

int		ft_queue_create(unsigned char **sig_queue);
int		ft_queue_pop(t_sigdata *sd);
int		ft_queue_push(t_sigdata *sd, unsigned char nbr);
int		ft_queue_is_empty(t_sigdata *sd);
#endif
