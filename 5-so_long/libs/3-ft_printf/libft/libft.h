/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0021/07/29 22:48:50 by da-silv           #+#    #+#             */
/*   Updated: 2021/09/01 19:14:09 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

/* PART 1 */
//STRING OPERATIONS: STRING.H
//Copy
/**
 * @brief The ft_memcpy() function copies n characters from memory area src to 
 * memory area dest.
 * @param dest This is pointer to the destination array where the content is 
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is pointer to the source of data to be copied, type-casted
 *  to a pointer of type void*.
 * @param n This is the number of bytes to be copied.
 * @return This function returns a destination pointer (dest).
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief The ft_memccpy() function copies 0 or more characters of src to dest,
 *  halting when the character c has been copied or when count characters have 
 * been copied, whichever comes first.
 * @param dest Pointer to the destination.
 * @param src Pointer to the source.
 * @param c Last character to copy.
 * @param n Number of characters.
 * @return If the character c is copied, ft_memccpy() returns a pointer to the 
 * char in dest that immediately follows the character. If c is not copied, it 
 * returns NULL.
 */
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
/**
 * @brief The ft_memmove() function copies n characters from src to dest, but 
 * for overlapping memory blocks, ft_memmove() is a safer approach than 
 * ft_memcpy().
 * @param dest This is a pointer to the destination array where the content is 
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is a pointer to the source of data to be copied, 
 * type-casted to a pointer of type void*.
 * @param n This is the number of bytes to be copied.
 * @return This function returns a destination pointer (dest).
 */
void		*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief The ft_strlcpy() function copies the null-terminated string from src 
 * to dest (up to character size). The function ensures that the destination 
 * string is null-terminated for all non-zero length buffers. 
 * @param dest This is a pointer to the destination array where the content is 
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is a pointer to the source of data to be copied, 
 * type-casted to a pointer of type void*.
 * @return The strlcpy() function returns the total length of the string you 
 * tried to create. This is simply the length of the Origin (src). 
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
//Concatenation
/**
 * @brief The ft_strlcat() function appends the null-terminated string src to 
 * the end of dest (but no more than characters of length will be in the 
 * destination). 
 * @param dest string destination
 * @param src string source
 * @param size buffer size
 * @return The strlcpy() function returns the total length of the string you 
 * tried to create. This is simply the length of the destination (before 
 * concatenation) plus the length of the source. 
 */
size_t		ft_strlcat(char *dest, const char *src, size_t size);
//Comparison
/**
 * @brief The ft_memcmp() function compares the first n bytes of memory area 
 * str1 and memory area str2.
 * @param str1 This is the pointer to a block of memory.
 * @param str2 This is the pointer to a block of memory.
 * @param n This is the number of bytes to be compared.
 * @return if Return value < 0 then it indicates str1 is less than str2.
 * if Return value > 0 then it indicates str2 is less than str1.
 * if Return value = 0 then it indicates str1 is equal to str2.
 */
int			ft_memcmp(const void *str1, const void *str2, size_t n);
/**
 * @brief The ft_strncmp() function compares at most the first n bytes of str1
 *  and str2.
 * @param str1 This is the first string to be compared.
 * @param str2 This is the second string to be compared.
 * @param n The maximum number of characters to be compared.
 * @return if Return value < 0 then it indicates str1 is less than str2.
 * if Return value > 0 then it indicates str2 is less than str1.
 * if Return value = 0 then it indicates str1 is equal to str2.
 */
int			ft_strncmp(const char *str1, const char *str2, size_t n);
//Search
/**
 * @brief The ft_memchr() function searches for the first occurrence of the 
 * character c (an unsigned char) in the first n bytes of the string pointed to
 * , by the argument str.
 * @param str This is the pointer to the block of memory where the search is 
 * performed.
 * @param c This is the value to be passed as an int, but the function performs
 *  a byte per byte search using the unsigned char conversion of this value.
 * @param n This is the number of bytes to be analyzed.
 * @return This function returns a pointer to the matching byte or NULL if the 
 * character does not occur in the given memory area.
 */
void		*ft_memchr(const void *str, int c, size_t n);
/**
 * @brief The ft_strchr() function searches for the first occurrence of the 
 * character c (an unsigned char) in the string pointed to by the argument str.
 * @param str This is the C string to be scanned
 * @param c  This is the character to be searched in str.
 * @return This returns a pointer to the first occurrence of the character c 
 * in the string str, or NULL if the character is not found.
 */
char		*ft_strchr(const char *str, int c);
/**
 * @brief The ft_strrchr() function searches for the last occurrence of the 
 * character c (an unsigned char) in the string pointed to, by the argument 
 * str.
 * @param str This is the C string.
 * @param c This is the character to be located. It is passed as its int 
 * promotion, but it is internally converted back to char.
 * @return This function returns a pointer to the last occurrence of character 
 * in str. If the value is not found, the function returns a null pointer.
 */
char		*ft_strrchr(const char *str, int c);
/**
 * @brief The ft_strnstr() function finds the first occurrence of the 
 * null-terminated string little in the large string, where the number of 
 * characters to be searched for is determined in len. Characters that appear 
 * after a '\\ 0' character are not searched.
 * @param big pointer char constant of string
 * @param little pointer char constant of string
 * @param len size_t of characters are searched
 * @return If little is an empty string, big is returned; if little occurs 
 * nowhere in big, NULL is returned; otherwise a pointer to the first character
 *  of the first occurrence of little is returned.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);
//Others
/**
 * @brief The ft_memset() function copies the character c (an unsigned char) to
 *  the first n characters of the string pointed to, by the argument str.
 * @param str This is a pointer to the block of memory to fill.
 * @param c This is the value to be set. The value is passed as an int, but 
 * the function fills the block of memory using the unsigned char conversion of
 *  this value.
 * @param n This is the number of bytes to be set to the value.
 * @return This function returns a pointer to the memory area str.
 */
void		*ft_memset(void *str, int c, size_t n);
/**
 * @brief The ft_strlen() function computes the length of the string str up to,
 *  but not including the terminating null character.
 * @param str This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t		ft_strlen(const char *str);
/**
 * @brief The ft_strdup() function is used to duplicate a string. It returns a 
 * pointer to null-terminated byte string.
 * @param str pointer to the null-terminated byte string to duplicate
 * @return A pointer to the newly allocated string, or a null pointer if an 
 * error occurred. 
 */
char		*ft_strdup(const char *str);
/**
 * @brief The ft_bzero() function erases the data in the n bytes of the memory
 * starting at the location pointed to by s, by writing zeros (bytes
 * containing '\0') to that area.
 * @param s void pointer s
 * @param n size_t n numbers
 * @return None
 */
void		ft_bzero(void *s, size_t n);
//CHARACTER TYPE TESTS: CTYPE.H
/**
 * @brief The ft_isalnum() function checks if the passed character is 
 * alphanumeric.
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is a digit or a letter, 
 * else it returns 0.
 */
int			ft_isalnum(int c);
/**
 * @brief The ft_isalpha() function checks if the passed character is 
 * alphabetic.
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is an alphabet, else it 
 * returns 0.
 */
int			ft_isalpha(int c);
/** 
 * @brief The ft_isdigit() function checks if the passed character is
 *  a decimal digit character. Decimal digits are (numbers) − 0 1 2 3 4 5 6 7
 *  8 9.
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is a digit, else it 
 * returns 0.
 */
int			ft_isdigit(int c);
/**
 * @brief The ft_isprint() function checks whether the passed character is 
 * printable. A printable character is a character that is not a control 
 * character.
 * @param c This is the character to be checked.
 * @return This function returns a non-zero value(true) if c is a printable 
 * character else, zero (false).
 */
int			ft_isprint(int c);
/**
 * @brief The ft_isascii() function tests if a given character, in the current 
 * locale, can be represented as a valid 7–bit US-ASCII character
 * @param c This is the character to be checked.
 * @return The ft_isascii() function returns nonzero if c, in the current 
 * locale, can be represented as a character in the 7–bit US-ASCII character 
 * set. Otherwise, it returns 0.
 */
int			ft_isascii(int c);
/**
 * @brief The ft_tolower() function converts a given letter to lowercase.
 * @param c This is the letter to be converted to lowercase.
 * @return This function returns lowercase equivalent to c, if such value 
 * exists, else c remains unchanged. The value is returned as an int value that
 *  can be implicitly casted to char.
 */
int			ft_tolower(int c);
/**
 * @brief The ft_toupper() function converts lowercase letter to uppercase.
 * @param c This is the letter to be converted to uppercase.
 * @return This function returns uppercase equivalent to c, if such value 
 * exists, else c remains unchanged. The value is returned as an int value that
 *  can be implicitly casted to char.
 */
int			ft_toupper(int c);
//STANDARD UTILITY FUNCTIONS : CTYPE.H
//Strings convertion
/**
 * @brief The function int atoi(const char *str) in the C library changes the 
 * string argument str to an integer. Generally, the function converts a string
 * argument to an integer. The atoi() function skips all the white space 
 * characters at the starting of the string. It also converts the characters as
 * the number part and stops when it finds the first non-number character.
 * @param str void pointer s
 * @return On success, the function returns the converted integral number as 
 * an int value. If the converted value would be out of the range of 
 * representable values by an int, it causes undefined behavior.
 */
int			ft_atoi(const char *str);
//Dynamic memory management 
/**
 * @brief The ft_calloc() function allocates the requested memory and returns a
 *  pointer to it. The difference in malloc and calloc is that malloc does not 
 * set the memory to zero where as calloc sets allocated memory to zero.
 * @param nitems This is the number of elements to be allocated.
 * @param size This is the size of elements.
 * @return This function returns a pointer to the allocated memory, or NULL if 
 * the request fails.
 */
void		*ft_calloc(size_t nitems, size_t size);
/* PART 2 */
// CUSTOM FUNCTIONS: LIBFT.H
/**
 * @brief The ft_substr() function creates a substring from the main string.For
 *  this it allocates the memory and delimits the substring starting at the 
 * value of start up to the informed length 
 * @param s const char pointer - The string from which to create the substring.
 * @param start unsigned int - The start index of the substring in the string
’s’.
 * @param len size_t - The maximum length of the substring.
 * @return The ft_substr() function returns the substring when its content is 
 * different from null, otherwise the return is NULL if the allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief ft_strjoin() concatenates two strings 's1' and 's2' with memory 
 * allocation resulting from the sum of the length of the two strings 
 * @param s1 const char - The prefix string.
 * @param s2 const char - The suffix string.
 * @return The function returns a new string result of str1 with str2 plus 1 
 * for the null character. 
 */
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief The ft_strtrim() make a copy of 's1' with the characters specified in
 *  'set' removed from the beginning and the end of the string.
 * @param s1 a const char - The string to be trimmed.
 * @param set a const char - The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char		*ft_strtrim(char const *s1, char const *set);
/**
 * @brief The ft_split() function splits the source string using a delimiter. 
 * The function also validates whether the delimiter is at the beginning or end
 *  of the string, in order not to include these in the string division. 
 * @param s a const char pointer - this variable represent a string
 * @param c a char - this variable represent a delimiter character
 * @return The array of new strings resulting from the split.NULL if the 
 * allocation fails.
 */
char		**ft_split(char const *s, char c);
/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * @param c char - this variable represent the character to output.
 * @param fd int - this variable represent the file descriptor on which to 
 * write.
 * @return None
 */
void		ft_putchar_fd(char c, int fd);
/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * @param s char pointer - this variable represent the string to output.
 * @param fd int - this variable represent the file descriptor on which to 
 * write.
 * @return None
 */
void		ft_putstr_fd(char const *s, int fd);
/**
 * 
 */
char		*ft_itoa(int n);
/**
 * 
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * 
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * 
 */
void		ft_putendl_fd(char *s, int fd);
/**
 * 
 */
void		ft_putnbr_fd(int n, int fd);
#endif
