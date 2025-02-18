/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:04:31 by sboukiou          #+#    #+#             */
/*   Updated: 2024/11/01 23:02:52 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*Includes - unistd + stdlib for malloc , read & write*/
# include <unistd.h>
# include <stdlib.h>

/*Structures*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*Functions prototypes*/
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
#endif
