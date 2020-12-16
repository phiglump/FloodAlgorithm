/**
 *@file main.c
 *@author Philippe Lumpkin
 *date 23 Apr 2020
 *@brief This is the entry point into the program where the file information is added to the matrix.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graphSearch.h"

int edge[50][50];

/**
 * This function will take in the name of the graph
 * add the contents of that information to the adjacency matrix
 * and then send that information to the printNegihbors function
 *@author Philippe Lumpkin
 *@param argc argument count
 *@param argv argruments in an array
 *@data 23 Apr 2020
 */
int main(int argc, char *argv[]) {
  //file declaration of variables
  FILE *infile;
  char *rMode = "r";
  
  infile = fopen(argv[1], rMode);
  if(infile == NULL) {
    fprintf(stderr, "Can't open input file %s!\n", argv[1]);
    exit(1);
  }

  if(isalpha(argv[2][0]) == 0) {
    printf("The entered starting node is not a valid starting node, alpha only.\n");
    return 0;
  }
  //variables for bringing in the data
  char temp[10];
  int n = 100;
  char *allNodes = (char *)malloc(n * sizeof(char));
  for(int i =0; fscanf(infile, "%s", temp) != EOF; i++)  {
    allNodes[i] = temp[0];
  }

  //adds the data to the matrix
  for(int x = 0; x < strlen(allNodes); x++) {
    int temp1 = allNodes[x];
    x++;
    int temp2 = allNodes[x];
    edge[temp1-96][temp2-96] = 1;
  }

  printNeighbors(argv, edge);
  
  printf("\n");
  fclose(infile);
  
  return 0;
}
