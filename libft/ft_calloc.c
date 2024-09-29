/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:22:00 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/18 16:38:53 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*i;

	i = malloc(nitems * size);
	if (i)
		ft_memset(i, 0, nitems * size);
	return (i);
}

/*#include <stdlib.h>
#include <stdio.h>
int main() 
{
    int *arr;
    
    // Allocate memory for an array of -5 elements, each of size 1 byte
    arr = (int *)ft_calloc(-5, 1);
    
    if (arr == NULL) 
	{
        printf("Memory allocation failed.\n");
        return (1);
    }
    
    // Printing the allocated array (should be all zeros)
    printf("Allocated array:\n");
    for (int i = 0; i < -5; i++)
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(arr);
    
    return (0);
}
*/
/*
Description:
	Calloc allocates memory and sets the allocated memory to zero.
Return Value:
	A pointer to the allocated memory, or NULL if the request fails.

memset byte size is "number of members"
memset sets BYTES and since calloc requires full size
*/