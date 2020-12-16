# Java Flood Programm 
# Class: Comparison of Programming Languages
## Date Started: 4/3/2020
## Date Completed: 4/12/2020
 
### How to run the program?
In order to run this program you'll first need to make sure that you have all of the files given downloaded on to a shell terminal.  You will also want to make sure that you have the latest version of java installed on the terminal as well. Once that is done you should note that one of the files is name flood.graph. This is the graph file and any graph file can be substituted as long as it is the same format like this.

> a b

> c d

> b e

Where any of the of the letters in the given examples can be replaced with strings. In order to get the program to execute you will first type the following command: 

> javac Flood.java 

This will create the executeable. Then you will run the command:

> java Flood nameOfGraph startNode 

where nameOfGraph will be the name of the graph file you created with the extension. If you want to do the given example you will type flood.graph for that part. And where startNode is a starting node that you want to search from, and a given example for the included example would be a or k. without any quotes. This will give you the output for the given start node in the form of a list. With all of the nodes in the list being all of the reachables.

### Process of coding
After watching the video showing how Maps worked I figured that this would be a great tool to use that would make my coding convient and easy to conveptualize. It did take some additional research and time to figure out how exactly i needed to code and how i wanted it to funciton. I decided to use a HashMap that uses strings as keys and lists as values. This while it took awhile for me to complete made doing my parsing and return really easy. Whenever I wanted every connection from a certain node i would just simply call the get function on that node and it would immediately give me all of those connections. So while it did take me several ours to understand and code the map it took me less than an hour to code the parse function. 

#### Some Changes I made
Originally i had made a dedicated mapping function that recieved the two arrays from the main and then added all the values to the map. I figured though that this would be really unnecessary. So I decided to create the map in the main and have the data go from the file and directly into the map from there cutting out the middle man and any unnecessary use of memory. It also made my code overall smaller and to me cleaner. 
