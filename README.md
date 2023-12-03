# Another tic-tac-toe 
Simple C program to play tic-tac-toe on the terminal. Nothing too fancy as it was made mostly out of boredom. Winning conditions are easily modifiable through the ``paths`` array. For example:

```C 
    struct winning paths[]  = {
        /*...*/
        {true, 0,0, 0,2, 1,2},
        /*...*/
        {false, 0,0, 0,0, 0,0},
    }
    /* Makes: O  -  O  a winning condition. 
              -  -  O
              -  -  -*/
```


# Build and play
- Clone the repository and run ``make``.
- Run ``./atct`` on the cloned directory.
- Have fun!
