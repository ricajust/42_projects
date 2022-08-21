SO LONG
===

## Information
- Title:  `So Long`
- Authors:  `Ricardo Justino | rda-silv`

## The Game
Game built in C using the [MiniLibX](https://github.com/42Paris/minilibx-linux) library.
The objective of the game is to collect all the keys and only then go to the chest to get the treasure. 

## Use
For that you must move your samurai with the following keys:
- (W) up
- (A) to the left
- (S) down
- (D) to the right

## Diagram
![Structure diagram](https://github.com/ricajust/42_projects/blob/develop/so_long.jpg)

## Directory Hierarchy
```
|—— Makefile
|—— image
|    |—— collectible.xpm
|    |—— down.xpm
|    |—— ground.xpm
|    |—— heart_empty.xpm
|    |—— heart_full.xpm
|    |—— left.xpm
|    |—— right.xpm
|    |—— tree.xpm
|    |—— up.xpm
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
|—— map.ber
|—— map2.ber
|—— map_2E.ber
|—— map_2P.ber
|—— map_R.ber
|—— map_T.ber
|—— map_W.ber
|—— map_noC.ber
|—— map_noE.ber
|—— map_noP.ber
|—— readme.md
|—— so_long
|—— source
|    |—— check_error.c
|    |—— check_map.c
|    |—— collectible.c
|    |—— getting_map.c
|    |—— getting_position.c
|    |—— hooks.c
|    |—— so_long.c
|    |—— so_long.h
|    |—— validate.c
|    |—— walk.c
|    |—— walk_aux.c
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

  TightVNC:
  CPU: Intel(R) Xeon(R) Gold 6132 CPU @ 2.60GHz
  RAM: 16 GB
  ```
## Simplification
- Created an GNL to bring the map in txt to the 'map' variable
- Created a tracker, an algorithm that scans and counts the size of a two-dimensional matrix
- Created a handle_check that will have the following functions:

  + (a) check that all lines are the same length (has a rectangular shape - check_shape)

  + (b) check if it is a rectangle, horizontally or vertically (check_rectangle)

  + (c) check that all lines are starting and ending with '1', both vertically and horizontally (it is surrounded by walls - check_walls). Ex:

    ### Horizontal check

    1--------1

    1--------1

    1--------1

    ### Vertical check

    1111111111

    | | | | | | | | | | |

    1111111111

  + (d) check in the map items if we have (check_items):

    + (d.1) at least one 'C'

    + (d.2) only one 'P'

    + (d.3) only one 'E'

    + (d.4) check if it has '0', it may not have any '0'


      > Example of the smallest map that does not have '0':
      >
      > 11111
      >
      > 1pce1
      >
      > 11111

    + (d.5) exception if it has any characters other than the 4 mentioned above

- We create a handle_errors, where we will handle all error messages for functions:
  - check_shape -> error_shape
  - check_rectangle -> error_rectangle
  - check_walls -> error_walls
  - check_items -> error_items
- We create a handle_game, where we will:
  - create the game window (create_window)
  - close the game window (close_window)
    + (a) closing the window by some exception or clicking close or ESC
    + (b) closing the window at the end of the game (game_over)
  - Render
    + (a) assigning images to the corresponding variables
    + (b) replacing characters with images
  - Hooks
    + (a) window: interface (btn close and minimize)
    + (b) window: expose (to be covered by another window)
    + (c) keyboard: keyboard capture
      + (c.1) walk up, down, left or right (WSAD)
        * destroy the current player image
        
        * replacing with the corresponding image
        
        * move the 'P' on the textmap:
          > - Check if the chosen direction is a wall '1', if yes, do nothing;
          >
          > - Check if the chosen direction is a collectible item 'C', if yes, (a) swap the 'P' of position with the 'C', (b) decrement the total of 'C' on the map, (c) on the instead of 'P' put a '0' and (d) account for the movement
          >
          >- Check if the chosen direction is exit 'E', if yes, (a) check if the amount of collectibles is equal to zero, if yes, (b) account for the movement and (c) close the game close_window.game_over (); otherwise, do nothing, in this case the output is seen as a wall.
          >
          >- Check if the direction chosen is the ground '0', if so, (a) change the 'P' in the text map to '0' and (b) account for the movement

## References
- [MiniLibX](https://github.com/42Paris/minilibx-linux)
- [Getting started with the minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
- [42Docs - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html)
