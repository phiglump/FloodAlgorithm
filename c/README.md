# README for Flood Program written in C

## Author: Philippe Lumpkin

## Date Started: 4/20/2020

## Date Finished: 4/23/2020


### How To Run the Code?
You will want to make sure that you have all of the given files downloaded to your terminal in order to properly run this. To begin, once you have moved into the first directory with all of the .h and .c files, you will want to type and run the command  
> make

This will compile the neccessary files together. From this point you will have the executeable flood. In order to use the executeable you will need to run the following command: 
> ./flood nameOfGraph.graph startNode

Where nameOfGraph is replaced with the name of the graph file you want to run the code by and startNode is replaced with the starting character you want to check by. For my particular testing and code i would suggest you type you graph as follows:
>a b

>b c

>c d

### How Was This Project Done?
This project utilized what is called a Adjacency list, which is a 2d array that has 0s and 1s in every position. If there is a 0 in the position that would indicate that at the corresponding row and column there is not an edge, while if there is a 1 there is an edge there. This particular graph was to utilize characters so in order for this to work for alpha characters, particularly lower case i had to offset the values so that they would start at the 1 position of the matrix. I decided to offset to the 1 position because i had early stops when i had been checking by the 0 position since for some reason 0 is read the same as \0. So every char on input is subtracted by 96 instead of 97. 97 is the a ascii value.

So then when i wanted to check all of the connected nodes i would go to that particular row and find all the 1s printing the corresponding columns. I would also add to an array that i was checking by that way it would only stop when no new things are in the list to get checked by. I also prevented infinite loops by not allowing the program to recheck a node thats already been checked. 

### Bugs?
I haven't been able to figure out what causes this but in the given graph about halfway down i have an edge from c to p, which used to be set as c to c. When it is c to c i have no issues what so ever getting the output i desire. But when it is on c to p when i run the a start node the output is missing the L. It is the only one that i checked that had been missing a character. I couldn't find the source of the issue since i could only have it print once. I know it isn't a size error since i could print longer graphs. What i am thinking is that check is ending sooner than it should but I couldn't fix it. 

I also didn't find a way to not accept the absent of a start node so whenever the startnode is left empty you will get a segmentation fault. I am sure this is a simple fix but i couldn't find it. I also did have the issue that would cause any non alpha characters ran as the start node to seg fault as well. This i did fix by just throwing an error for any non alpha character. 


