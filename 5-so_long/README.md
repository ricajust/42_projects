SO LONG

- We created an LNG to bring the map in txt to the 'map' variable
- We created a tracker, an algorithm that scans and counts the size of a two-dimensional matrix
- We created a handle_check that will have the following functions:
(a) check that all lines are the same length (has a rectangular shape - check_shape)
(b) check if it is a rectangle, horizontally or vertically (check_rectangle)
(c) check that all lines are starting and ending with '1', both vertically and horizontally (it is surrounded by walls - check_walls). Ex:
Horizontal check
1--------1
1--------1
1--------1
vertical check
1111111111
|||||||||||
1111111111
(d) check in the map items if we have (check_items):
(c.1) at least one 'C'
(c.2) only one 'P'
(c.3) only one 'E'
(c.4) check if it has '0', it may not have any '0'
Example of the smallest map that does not have '0' *OLHAR PDF:
11111
1pce1
11111
(c.5) exception if it has any characters other than the 4 mentioned above
- We create a handle_errors, where we will handle all error messages for functions:
- check_shape -> error_shape
- check_rectangle -> error_rectangle
- check_walls -> error_walls
- check_items -> error_items
- We create a handle_game, where we will:
1 - create the game window (create_window)
2 - close the game window (close_window)
(a) closing the window by some exception or clicking close or ESC
(b) closing the window at the end of the game (game_over)
3 - Render
(a) assigning images to the corresponding variables
(b) replacing characters with images
4 - Hooks
(a) window: interface (btn close and minimize)
(b) window: expose (to be covered by another window)
(c) keyboard: keyboard capture
(c.1) walk up, down, left or right (WSAD)
> destroy the current player image
> replacing with the corresponding image
> move the 'P' on the textmap:
- Check if the chosen direction is a wall '1', if yes, do nothing;
- Check if the chosen direction is a collectible item 'C', if yes, (a) swap the 'P' of position with the 'C', (b) decrement the total of 'C' on the map, (c) on the instead of 'P' put a '0' and (d) account for the movement
- Check if the chosen direction is exit 'E', if yes, (a) check if the amount of collectibles is equal to zero, if yes, (b) account for the movement and (c) close the game close_window.game_over (); otherwise, do nothing, in this case the output is seen as a wall.
- Check if the direction chosen is the ground '0', if so, (a) change the 'P' in the text map to '0' and (b) account for the movement
Mais sobre o texto original
É necessário fornecer o texto original para ver mais informações sobre a tradução
Enviar feedback
Painéis laterais
