# Philippe Lumpkin Haskell Project 470
## Main Start Date: 2/1/2020
## End Date: 2/13/20
## I want to determine what all I will need for this program in Haskell

-Define Reachable that takes graph and start as parameters

-A compare function that finds the neighbors of a given start

-A remove funciton that rids the list of nodes no longer in use

-helper functions that make code easier for the user to use, and the programmer to read.

## Programming
First Day: 2/1/2020

Gathered an assorment of functions that seem to be helpful towards my end goal. Essentially i am able to get the first connections that are connected to the start node. I need to find a way to continue on by setting those connected verticies to the next start so there connections can be found. I have gotten to the point where i can get all of the first set of connections from the start. I have begun getting the next set of connections from each of the others but have run into an issue where at the complete end of a branch the whole functions just stops there instead of goin back and looking thru the other branches.

Second Day: 2/4/2020

Got the program to instead of going to do one branch of connections from the origin, it will gather all of the first neighbors and then get the connections from all of those neighbors. I feel that most of these are still hardcoded in there but, i am hoping that this will lead me into a better funciton setup using recursion. 

Third Day: 2/8/2020 

I have finally gotten the code to not be so hardcoded. I need to play with the information so that it is written in a better fashion, and I also need to create my own remove duplicates function or find one that is built into the program. Another issue i have now is that i don't have a way to prevent an infinite loop, I am thinking one possible easy fix is to remove edges that aren't going to be referenced anymore.

Final Days including 2/13/20:

I did some prettying up to my code to make it more readable. Also, previously my code would fail if i added any sort of loops or return to previously checked nodes. I implemented a remove funciton that rids the graph of nodes that are no longer needed in order to prevent that from happening. I have tested this with both c to c and c to b / b to c. One issue i have is that while my code doesn't break it will accept any and all characters and i am not sure how to prevent this. So for instance if I type a 1 I will get a list back with the number 1. 
