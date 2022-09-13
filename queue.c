/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:29:49 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/15 08:29:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/**
 * @brief   This function allocates memory on the heap for the queue creation.
 *          It stores the address of the allocated memory on the passed in
 *          pointer address. 
 * 
 * @param sig_queue 
 * @return int 
 */
int	ft_queue_create(unsigned char **sig_queue)
{
	*sig_queue = (unsigned char *)malloc(FIFO_SIZE);
	if (*sig_queue == NULL)
		return (-1);
	return (0);
}

/**
 * @brief 	This function checks if a queue stored with the type struct is
 * 			empty. It returns 0 if empty and -1 if not empty.
 * 
 * @param sd 
 * @return int 
 */
int	ft_queue_is_empty(t_sigdata *sd)
{
	if ((sd->front == -1) && (sd->rear == -1))
		return (0);
	else
		return (-1);
}

/**
 * @brief 	This function is used by the handler to enqueue the received bit
 * 			in the queue stored within the type struct t_sigdata.
 * 			It exits and returns -1 if the queue is full (rear == front).
 * 			If empty, it enqueues the recvd bit and update the queue indexes
 * 			(front and rear) accordingly.
 * 
 * @param sd 
 * @param nbr 
 * @return int 
 */
int	ft_queue_push(t_sigdata *sd, unsigned char nbr)
{
	if (((sd->rear + 1) % FIFO_SIZE) == sd->front)
		return (-1);
	if (ft_queue_is_empty(sd) == 0)
	{
		sd->front = 0;
		sd->rear = 0;
		sd->queue[sd->rear] = nbr;
		(sd->rear) = (sd->rear + 1) % FIFO_SIZE;
	}
	else
	{
		sd->queue[sd->rear] = nbr;
		(sd->rear) = (sd->rear + 1) % FIFO_SIZE;
	}
	return (0);
}

/**
 * @brief 	This function dequeues the queue stored in type struct t_sigdata.
 * 			It exits and returns -1 if the queue is empty.
 * 			Then it checks if the item to be dequeued is the only one left.
 * 			If so, it is dequeue and the queue state is set to empty (front 
 * 			= rear = -1).
 * 			If there are more items in the queue, then the queue is dequeued
 * 			once and the indexes updated to point to the next item
 * 
 * @param sd 
 * @param nbr 
 * @return int 
 */
int	ft_queue_pop(t_sigdata *sd)
{
	if (ft_queue_is_empty(sd) == 0)
		return (-1);
	else if (sd->front == sd->rear)
	{
		sd->recv_bit = sd->queue[sd->front];
		sd->front = -1;
		sd->rear = -1;
		return (-1);
	}
	else
	{
		sd->recv_bit = sd->queue[sd->front];
		(sd->front) = (sd->front + 1) % FIFO_SIZE;
	}
	return (0);
}
