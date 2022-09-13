/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:27:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 08:27:21 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "data_type_const.h"
# include <stdlib.h>

int		ft_queue_create(unsigned char **sig_queue);
int		ft_queue_pop(t_sigdata *sd);
int		ft_queue_push(t_sigdata *sd, unsigned char nbr);
int		ft_queue_is_empty(t_sigdata *sd);
#endif
