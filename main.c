#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "sortAndShuffle.h"



int main(void)
{
  /* Variable declaration */

  //The array containing artist names
  char artists[4][80];
  //The array containing the sorted artists
  char sortedArtists[4][80];
  //Songs for Artist 1
  char songsArtist1[3][80];
  //Songs for Artist 2
  char songsArtist2[3][80];
  //Songs for Artist 3
  char songsArtist3[3][80];
  //Songs for Artist 4
  char songsArtist4[3][80];
  //The total number of artists (Note it can be less than 4)
  int numOfArtists =0;
  //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
  int numSongsPerArtist[4] = {0};
  //The strings to copy artists name and song name from user input
  char artistName[20],songName[20];
  //parsameters to use to tell whether user wants to add more songs or more artists
  int addMoreArtists;
  //parametrs incremented each time user enters new song
   int first = 0; //for first artist
   int second = 0; //for second artist
   int third = 0; //for third artist
   int fourth = 0; //for thrid artist
   //array of unsorted songs
   char unsortedSongs[12][80];
  //counter for total songs in playlist
   int playlist = 0; //stores total number of songs
   unsigned long int length; //used to determine length of song of each artist


		//declaration of the multidimentional array where loop i denotes loop for artists and loop j for songs
        for(int i=0; i<4 ; i++) {
            for(int j=0; j<3 ; j++) {

				//the first condition for the first artist
				if(i == 0) {
					if(j == 0) {
						printf("Insert an Artist/Group name ");
						fgets(artistName, 80 , stdin); //fetching artist 1 from user
						strcpy(artists[i],artistName); //copying fetched artistName to array artists for artist 1
						 numOfArtists++; //incrementing number of artists to 1

						 //Removes carraige return character from the artists name
						 int l = strlen(artists[0]);

						 if( l>0 && artists[0][l-1] == '\n'){
							 artists[0][l-1] = '\0';
						 }



					}

                    //For the songs of artist 1
					printf("Insert song %d for %s ", j+1,artistName);
					//using
					fflush(stdin); //flushes out any buffered data and takes input from the user
					fgets(songName, 80 , stdin);  //fetching song names for artist 1
					strcpy(songsArtist1[j],songName); //copying fetched songName from user to array of songs for artist 1
                    //using string copy and string concatenate functions we are storing artists names and songs name in an array of unsorted songs
					  //using a counter called first for the first artist
					   strcpy(unsortedSongs[first], artists[0]);
					   strcat(unsortedSongs[first], " - ");
					   strcat(unsortedSongs[first], songsArtist1[j]);


					   //condition when user presses enter, it goes to next artists
					   if( songsArtist1[j][0] == '\n'){

						 //Remove the carriage return from the songs
						length = strlen(songsArtist1[j]);
						 songsArtist1[j][length -1] = '\0';

						 break; //breaks when user presses enter

					    }

					    first++; //increments counter first every time  new song is entered for artist 1
						playlist++; //increment total number of songs in the playlist
						second = first; //hence we declare second counter as the first to continue with playlist
						numSongsPerArtist[i]++; //incrementing array of number of songs per artist every time new songs entered





				} else if(i == 1) {  //Condition for the second artist
					if(j == 0) {
						printf("Insert an Artist/Group name ");
						fflush(stdin); //flushes out any buffered data and takes input from the user
						fgets(artistName, 80 , stdin); //fetching artist 2 from user
						strcpy(artists[i],artistName); //copying fetched artistName to array artists for artist 2
						numOfArtists++; //incrementing number of artists to 2

						 //Remove the carriage return from the artist
						 int l = strlen( artists[1]);

						 if( l>0 && artists[1][l-1] == '\n'){
							 artists[1][l-1] = '\0';
						 }

					}
                        //For the songs of artist 2
						printf( "Insert song %d for %s ", j+1, artistName);
						fflush(stdin);
						fgets(songName, 80 , stdin); //fetching song names for artist 2
						strcpy(songsArtist2[j],songName); //copying fetched songName from user to array of songs for artist 2

						//using string copy and string concatenate functions we are storing artists names and songs name in an array of unsorted songs
					    //using a counter called second for the second artist
						  strcpy(unsortedSongs[second], artists[1]);
						  strcat(unsortedSongs[second], " - ");
						  strcat(unsortedSongs[second], songsArtist2[j]);

						   //condition when user presses enter
						   if( songsArtist2[j][0] == '\n'){

							//Removes the carraige return character from the songs
							int length = strlen(songsArtist2[j]);
							songsArtist2[j][length -1] = '\0';

							break; //goes to next artist when enter is pressed

					    }


					      second++;  //increments second after each new song is entered for artist 2
						  playlist++; //increments playlist containing total number of songs
						  third = second; //declares third as second
						  numSongsPerArtist[i]++;  //incrementing array of number of songs per artist every time new songs entered




				}  else if(i == 2) {  //Condition for the third artist
					if(j == 0) {
						printf( "Insert an Artist/Group name ");
						fflush(stdin); //flushes out any buffered data and takes input from the user
						fgets(artistName, 80 , stdin); //fetching artist 3 from user
						strcpy(artists[i],artistName); //copying fetched artistName to array artists for artist 3
						numOfArtists++; //incrementing number of artists to 3

						 //Removes carraige return character from the third artist name
						 int l = strlen( artists[2]);

						 if( l>0 && artists[2][l-1] == '\n'){
							 artists[2][l-1] = '\0';
						 }

					}
                    //For the songs of artist 3
						printf("Insert song %d for %s ", j+1, artistName);
						fflush(stdin);
						fgets(songName, 80 , stdin); //fetching song names for artist 3
						strcpy(songsArtist3[j],songName); //copying fetched songName from user to array of songs for artist 3

					  //using string copy and string concatenate functions we are storing artists names and songs name in an array of unsorted songs
					  //using a counter called third for the third artist
					  strcpy(unsortedSongs[third], artists[2]);
					  strcat(unsortedSongs[third], " - ");
					  strcat(unsortedSongs[third], songsArtist3[j]);

					   if( songsArtist3[j][0] == '\n'){

						 //Remove the carriage return from the song
						int length = strlen(songsArtist3[j]);
						songsArtist3[j][length -1] = '\0';

						break;

					 }

					    third++; //increments third after each song is entered for artist 3
						playlist++; //increments playlist containing total number of songs
						fourth = third; //declares fourth as third
						numSongsPerArtist[i]++;  //incrementing array of number of songs per artist every time new songs entered



				}  else if(i == 3) {  //Condition for the fourth artist
					if(j == 0) {
						printf("%s","Insert an Artist/Group name ");
						fflush(stdin); //flushes out any buffered data and takes input from the user
						fgets(artistName, 80 , stdin); //fetching artist 4 from user
						strcpy(artists[i],artistName); //copying fetched artistName to array artists for artist 4
						numOfArtists++; //increments number of artists to 4

						//Remove the carraige return character from the fourth artist name
						int l = strlen( artists[3]);

						 if( l>0 && artists[3][l-1] == '\n'){
							 artists[3][l-1] = '\0';
						 }

					}
                    //For the songs of artist 4
					printf("Insert song %d for %s ", j+1, artistName);
					fflush(stdin);
					fgets(songName, 80 , stdin); //fetching song names for artist 4
					strcpy(songsArtist4[j],songName); //copying fetched songName from user to array of songs for artist 4


					  //using string copy and string concatenate functions we are storing artists names and songs name in an array of unsorted songs
					  //using a counter called third for the third artist

						strcpy(unsortedSongs[fourth], artists[3]);
						strcat(unsortedSongs[fourth], " - ");
						strcat(unsortedSongs[fourth], songsArtist4[j]);

					   if( songsArtist4[j][0] == '\n'){

						 //Remove the carriage return from the song
						int length = strlen(songsArtist4[j]);
						songsArtist4[j][length -1] = '\0';
						break; //breaks when user presses enter

					 }



					    fourth++; //increments fourth  for each new song entered for artist 4
						playlist++; //increments playlist

						numSongsPerArtist[i]++;  //incrementing array of number of songs per artist every time new songs entered




				}



            }

			        //asks the user whether they want to enter more artists or not

			        printf("Do you wish to enter more artists (1 for yes and 0 for no) : ");

                    scanf("%d", &addMoreArtists);

                    if( addMoreArtists == 0)
					{
                       break;
                    }




		}

					 /* To invoke sort songs function */

					       //invokes the function sortArtists to sort the artists
						   sortArtists(artists,sortedArtists, numOfArtists);

					  //loop to call the sortSongs functions by passing arguments as below
					 for(int j=0; j<numOfArtists; j++){ //loop iterates till number of artists entered by the user
						 if(j == 0){
							   sortSongs(songsArtist1, numSongsPerArtist[0]); //for songs of first artist
						 } else if(j == 1){
							   sortSongs(songsArtist2, numSongsPerArtist[1]); //for songs of second artist
						 } else if(j == 2){
							   sortSongs(songsArtist3, numSongsPerArtist[2]); //for songs of third artist
						 } else if(j == 3){
							   sortSongs(songsArtist4, numSongsPerArtist[3]); //for songs of fourth artist
						 }
					 }


					  /* To print the sorted songs with their respective artists in sorted order */
					 printf("Sorted list of songs:");



					 //This loop is to print artists in sorted order
					 for(int counter = 0; counter< numOfArtists; counter++){


						 printf("\n%s\n", sortedArtists[counter]); //prints the artists name

						 //The outer loop checks for the equality between songs stored in sortedArtists and those in artists.
                         //loop iterates till number of artists entered by the user.
						 for(int compare =0; compare< numOfArtists; compare++){

							 //comparing strings sortedArtists and artists and intitialzing it to artists_compare
							 int artists_compare = strcmp(sortedArtists[counter], artists[compare]);

							 /* condition for equality i.e if the artist entered by the user matches the sorted artist, it prints the
							    respective songs for the artist */

							 if(artists_compare == 0){
								 if(compare == 0){
									    //prints the songs for the first sorted artist
										printSongs(songsArtist1, numSongsPerArtist[0]);

									  break;

								 } else if(compare == 1){

									  //prints the songs for the first sorted artist
									  printSongs(songsArtist2, numSongsPerArtist[1]);
									  break;

								 } else if(compare == 2){

									  //prints the songs for the first sorted artist
									  printSongs(songsArtist3, numSongsPerArtist[2]);
									  break;

								 }  else if(compare == 3){

									  //prints the songs for the first sorted artist
									  printSongs(songsArtist4, numSongsPerArtist[3]);
									  break;


								 }
							 }
						 }
					 }



					  //calling the function shuffle songs to shuffle all the songs in the playlist

					  shuffleSongs( unsortedSongs, playlist);





		           return 0;


}
