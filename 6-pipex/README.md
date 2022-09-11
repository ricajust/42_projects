PIPEX
===

## Information
- Title:  `pipex`
- Authors:  `Ricardo Justino | rda-silv`

## The Project
Develop a Unix pipe simulate with C language.

## Use
Your program will be executed as follows:
>./pipex file1 cmd1 cmd2 file2

It must take 4 arguments:
- file1 and file2 are file names.
- cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:
>$> < file1 cmd1 | cmd2 > file2

## Examples
>./pipex infile "ls -l" "wc -l" outfile

Should behave like: < infile ls -l | wc -l > outfile

>./pipex infile "grep a1" "wc -w" outfile

Should behave like: < infile grep a1 | wc -w > outfile
### Some commands with Valgrind
>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./pipex infile "ls -la" "wc -l" outfile

>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./pipex infile "grep a1" "wc -w" outfile

>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./pipex infile "cat kafka" "grep biblioteca" outfile

>valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./pipex infile "free -m" "grep Mem" outfile
## Diagram
![Structure diagram](https://github.com/ricajust/42_projects/blob/master/5-so_long/assets/so_long.jpg)

## Directory Hierarchy
```
|—— Makefile
|—— library
|    |—— libft
|        |—— Makefile
|        |—— ft_atoi.c
|        |—— ft_bzero.c
|        |—— ft_calloc.c
|        |—— ft_filter_flags.c
|        |—— ft_get_next_line.c
|        |—— ft_get_next_line_utils.c
|        |—— ft_isalnum.c
|        |—— ft_isalpha.c
|        |—— ft_isascii.c
|        |—— ft_isdigit.c
|        |—— ft_isprint.c
|        |—— ft_itoa.c
|        |—— ft_memccpy.c
|        |—— ft_memchr.c
|        |—— ft_memcmp.c
|        |—— ft_memcpy.c
|        |—— ft_memmove.c
|        |—— ft_memset.c
|        |—— ft_print_character.c
|        |—— ft_print_decimal.c
|        |—— ft_print_hex.c
|        |—— ft_print_pointer.c
|        |—— ft_print_positive_int.c
|        |—— ft_print_string.c
|        |—— ft_printf.c
|        |—— ft_putchar_fd.c
|        |—— ft_putchar_plus.c
|        |—— ft_putendl_fd.c
|        |—— ft_putnbr_fd.c
|        |—— ft_putstr_fd.c
|        |—— ft_split.c
|        |—— ft_strchr.c
|        |—— ft_strdup.c
|        |—— ft_striteri.c
|        |—— ft_strjoin.c
|        |—— ft_strlcat.c
|        |—— ft_strlcpy.c
|        |—— ft_strlen.c
|        |—— ft_strmapi.c
|        |—— ft_strncmp.c
|        |—— ft_strnstr.c
|        |—— ft_strrchr.c
|        |—— ft_strtrim.c
|        |—— ft_substr.c
|        |—— ft_tolower.c
|        |—— ft_toupper.c
|        |—— ft_uitoa.c
|        |—— libft.a
|        |—— libft.h
|—— infile
|—— outfile *(dymanically generated)
|—— pipex (binary)
|—— source
|    |—— pipering.c
|    |—— pipex.c
|    |—— pipex.h
|    |—— validators.c
```
## Code Details
### Tested Platform
- software
  ```
  Local OS: Windows 11 with WSL (NAME="Ubuntu" VERSION="20.04.4 LTS (Focal Fossa)")
  VNC OS: NAME="Ubuntu" VERSION="20.04.3 LTS (Focal Fossa)"
  ```
- hardware
  ```
  Local computer:
  CPU: Intel i7-10750H
  GPU: Nvidia RTX2060 (6GB)
  ```
## Simplification
- If we use the example cat text.txt | wc -l, we understand that the standard output of the cat command will be the standard input of the wc command. So cat does not write to the standard output (which would be the terminal) but to the pipe. And it is this redirection behavior that we must simulate in our PIPEX.


### Let's go
1 - How do we execute a shell command in C?
First we need to understand that each command executed in the shell is actually a program. To run these programs we will use the command from the exec library (we have some exec options such as "l", "lp", "le", etc) what we will use in PIPEX is execve, which overwrites the process that invoked by another that is specified in its parameters.

  >$> int execve(cons char *pathname, char *const argv[], char *const envp[])

  - pathname: is the path of the binary file that we are going to execute
  - argv[]: are the arguments we want to pass to the program, remembering that arg[0] is the binary 
  - envp[]: is a pointer to environment variables. For example, depending on the OS, some files/commands can be stored in the "usr" directory, but on other OS's not, so we use this variable to get the result of something like "env | grep PATH" and filter it ( with the functions ft_strnstr, ft_substre ft_split from our libft !) so that we can find the commands that we will use
  - the execve function returns a value of -1 if there is a problem, if not, it does not return because a new process is created and the old one that invoked it is overwritten.

2 - To verify all the functions in the env PATH, we will use the access command, for that we will analyze it:

  >$> int access(const char *pathname, int mode);

  - pathname: is the path that we are going to search the binary file
  - mode: what do we want to know from this file (if located):
    - F_OK: was located
    - X_OK: if it can be executed
    - R_OK: if it can be read
    - W_OK: if it can be written
  - the function return is -1 if there is any problem with the location or permissions and it will return 0 if everything is ok and the file is in the indicated path


## References
- [Getting started with the minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
- [42Docs - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html)
