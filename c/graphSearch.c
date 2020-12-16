/**
 *@file graphSearch.c
 *@author Philippe Lumpkin
 *@date 23 Apr 2020
 *@brief This file takes in the adjacency matrix, gets the first neighbors, and then runs the getRest function to find the other neighbors, and finally prints the full list of the neighbors. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphSearch.h"

const int c = 26;

/**
 *This function sorts and outputs the resulting information including the start node
 *@author Philippe Lumpkin
 *@param unchecked this is the list of unchecked nodes
 *@param argv this stored the start variable
 *@data 23 Apr 2020
 */
void sort(char *unchecked, char *argv[]) {
  int x = 0;
  char temp;
  int n = strlen(unchecked);
  for(int i = 0; i < n; i++) {
    for(int j =0; j < n; j++) {
      if (unchecked[i] < unchecked [j]) {
	temp = unchecked[i];
	unchecked[i] = unchecked[j];
	unchecked[j] = temp;
      }
    }
  }
  printf("These are the neighbors connected the starting node %c: ", argv[2][0]);
  for(x = 0; unchecked[x] != '\0'; x++){
    printf("%c ", (unchecked[x] + 96));
  }
  free(unchecked);
}

/**
 *This function gets the rest of the neighbors after the first set has been gathered
 *@author Philippe Lumpkin
 *@param unchecked this is the list of unchecked nodes
 *@param edge this is the adjacency matrix
 *@param counterU this is a counter for the amount in the unchecked array
 *@data 23 Apr 2020
 */
char getRest(char *unchecked, int edge[50][50], int counterU) {
  int counterC = 0;
  int inThere = 0;
  char *checked = (char *)malloc(c * sizeof(char));

  for(int x = 0; unchecked[x] != '\0'; x++){
    for(int y=1; y<27; y++) {
      if(strstr(checked, &unchecked[x]) == NULL) {
	unsigned int search = unchecked[x];
	if(edge[search][y] == 1){
	  checked[counterC] = unchecked[x];
	  counterC++;
	  for(int j = 0; unchecked[j] != '\0'; j++){
	    if(unchecked[j] == y) {
	      inThere = 1;
	    }
	  }
	  if(inThere == 0){
	    unchecked[counterU] = y;
	    counterU++;
	  }
	  inThere = 0;
	}
      }
    }
  }
  unchecked[counterU] = '\0';
  free(checked);
  return *unchecked;
}

/**
 *This function gets the beginning nodes that are connected to the start
 *@author Philippe Lumpkin
 *@param argv this contains the arguments passed in so we can get the start
 *@param edge this is the adjacency matrix 
 *@data 23 Apr 2020                                                                  
 */
void printNeighbors(char *argv[], int edge[50][50]){
  int counterU = 0;
  char *unchecked = (char *)malloc(c * sizeof(char));
  //prints the neighbors of start
  unchecked[counterU] = argv[2][0]-96;
  counterU++;
  for(int x=1; x<27; x++) {
    if(edge[argv[2][0]-96][x] == 1){
      unchecked[counterU] = x;
      counterU++;
    }
  }
  getRest(unchecked, edge, counterU);
  sort(unchecked, argv);
}
