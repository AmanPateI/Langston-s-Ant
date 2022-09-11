# Langston-s-Ant
Langton's ant is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. 

An ant moves on a regular grid of squares that are colored either black or white.  The 
ant is always oriented in one of the cardinal directions (left, right, up or down) and moves from square to 
adjacent square according to the following rules:

  1. If it is on a black square, it flips the color of the square to white, rotates 90 degrees counterclockwise 
      and moves forward one square. 
  2. If it is on a white square, it flips the color of the square to black, rotates 90 degrees clockwise and 
     moves forward one square. 
     
Starting with a grid that is entirely white, we will need to determine how many squares are black after some 
number of moves of the ant. Takes one command-line argument variable of type unsigned long that indicates the 
number of moves the ant makes to output text file 'output.txt'
