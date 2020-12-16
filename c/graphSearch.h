/**
 *@file graphSearch.h
 *@author Philippe Lumpkin
 *@date 23 Apr 2020
 *@brief This is the header file for graphSearch.c
 */
void rmDups(char *unchecked);
char getRest(char *unchecked, int edge[50][50], int counterU);
void printNeighbors(char *argv[], int edge[50][50]);
