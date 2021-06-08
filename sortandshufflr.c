#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"



						/*
				* This method sorts the songs of a specific artist alphabetically. It takes as input:
				* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
				* - numOfArtists: the number of artists provided from the standard input
				*/



			      void sortSongs(char songsOfAnArtist[][80], int numOfSongs){
					//Declaring some variables
				    int i =0;
				    int j=0;
				    int minIndex = 0;
				    char swap [80];

					/* i initially points to the first element of the array, it iterates all the elements accept the last
					   and minIndex is set to i */
					for(i=0; i< (numOfSongs-1); i++){
						minIndex = i; //minIndex assigned as i
						for(j=i+1; j<numOfSongs; j++){ //now j will be incremented

					//finds the smallest string(alphabetically) in the array songsOfAnArtist[i,numOfsongs]
							if(strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0) //using strcmp we compare the strings
								minIndex = j; //minIndex is now assigned to j
						}
				  memset(swap, '$', 80-2);  //swap is initialised using function memset to avoid runtime errors
				  swap[80-1]='\0';
				  //using strcpy function strings at position i and minIndex are swapped
				  strcpy(swap,songsOfAnArtist[i]);
				 strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
				  strcpy(songsOfAnArtist[minIndex], swap);
				 }
			   }

			    //Function to print sorted songs for each artist
					void printSongs(char songsOfAnArtist[][80] , int numOfSongs){
				    int i ;
				    for(i=0; i< numOfSongs; i++){ //loop runs till total number of songs
				 	printf("  - %s", songsOfAnArtist[i]); //prints the song name
				     }

			        }

					  /*
				* This method sorts the artists alphabetically. It takes as input:
				* - sortedArtists: the array of artists that that should be sorted
				* - numOfArtists: the total number of artists
				* - artists: the array of original artists entered by user
				*
				*/



			       void sortArtists(char artists[][80], char sortedArtists[][80] , int numOfArtists){
					//Declaring some variables
				    int i =0;
				    int j=0;
				    int minIndex = 0;
				    char swap [80];

					for(i=0; i<numOfArtists; i++){
						strcpy(sortedArtists[i], artists[i]);
					}


					/* i initially points to the first element of the array, it iterates all the elements accept the last
					   and minIndex is set to i */
					for(i=0; i< (numOfArtists-1); i++){
						minIndex = i;  //minIndex assigned as i
						for(j=i+1; j<numOfArtists; j++){
						   //finds the smallest string(alphabetically) in the array sortedArtists[j,numOfArtists]
							if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0) //compares using strcmp function
								minIndex = j; //minIndex is now assigned to j
						}
				  memset(swap, '$', 80-2);  //swap is initialised using function memset to avoid runtime errors
				  swap[80-1]='\0';
				  //using strcpy function strings at position i and minIndex are swapped
				  strcpy(swap,sortedArtists[i]);
				 strcpy(sortedArtists[i], sortedArtists[minIndex]);
				  strcpy(sortedArtists[minIndex], swap);
				}

		   }



						   /*
				* This method shuffles a set of songs. It takes as input:
				* - songsToBeShuffled: the array of the songs that should be shuffled
				* - numOfSongs: the number of songs to be shuffled
				*/

              void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs){
                //declaring some variables
				 int  i, j;
				 srand(time(NULL)); //called once to initialise random number generation
				 char swap[80];


				 for(i=1;i<numOfSongs;i++){

					 j = rand()%(i+1); //generated random number comprised between 0 and i

					 if(j!=i){
						 //if i is not equal to j then strings at positions i and j are swapped
						strcpy(swap, songsToBeShuffled[j]);
						strcpy(songsToBeShuffled[j],songsToBeShuffled[i]);
						 strcpy( songsToBeShuffled[i], swap);


					 }
				 }

				 printf("\nShuffled Playlist : \n");


				 for(int j=0 ; j<2 ; j++){
				 for(i=0; i<numOfSongs; i++){
					 printf(" %s",  songsToBeShuffled[i]); //prints shuffled songs


				   }
				 }

            }

