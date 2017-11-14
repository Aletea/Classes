/* Aletea vanVeldhuisen
   Period 2
   11-14-17
   This program will take user input to add, search, and delete media files
*/

#include <iostream>
#include "media.h"
#include "music.h"
#include "movies.h"
#include "videogames.h"
#include <vector>
#include <cstring>


int main() {
  //variables to keep track of media files
  bool running = true;
  vector<media*> mediaFiles;
  while(running = true) {
    cout << "Welcome! type ADD to add media, SEARCH to search media, DELETE to delete media, and QUIT to quit" << endl;
    char input[80];
    cin.get(input, 80);
    cin.get();
    //be sure of valid input
    while (!(strcmp(input, "ADD") || strcmp(input, "SEARCH") || strcmp(input, "DELETE") || strcmp(input, "QUIT"))) {
      cout << "Invalid Input. Key commands are 'ADD', 'SEARCH', 'QUIT', or 'DELETE'" << endl;
      cin.get(input, 80);
      cin.get();
    }
    //add media
    if (strcmp(input, "ADD") == 0) {
      cout << "Media Type: \n1. Music\n2:Movie\n3:Video Game" << endl;
      int mediaType;
      cin >> mediaType;
      cin.ignore();
      while (!(mediaType == 1 || mediaType == 2 || mediaType == 3)) {
	cout << "Invalid Input. Must enter a 1, 2, or 3" << endl;
	mediaType = 1;
	cin >> mediaType;
	cin.ignore();
      }
      //input basic members of media
	cout << "Title: ";
	char mediaTitle[80];
	cin.get(mediaTitle, 80);
	cin.get();
	cout << "Year: ";
	int mediaYear;
	cin >> mediaYear;
	cin.ignore();
     //input other members based on type (music, movie, or videogame)
     if (mediaType == 1) {
	cout << "Artist: ";
	char mediaArtist[80];
	cin.get(mediaArtist, 80);
	cin.get();
	cout << "Duration: ";
	int mediaDuration;
	cin >> mediaDuration;
	cin.ignore();
	cout << "Publisher: ";
	char mediaPublisher[80];
	cin.get(mediaPublisher, 80);
	cin.get();
	music* newMusic = new music(mediaTitle, mediaYear, mediaArtist, mediaDuration, mediaPublisher);
	mediaFiles.push_back(newMusic);
      }
      else if (mediaType == 2) {
	cout << "Director: ";
	char mediaDirector[80];
	cin.get(mediaDirector, 80);
	cin.get();
	cout << "Duration: ";
	int mediaDuration;
	cin >> mediaDuration;
	cin.ignore();
	cout << "Rating: ";
	int mediaRating;
	cin >> mediaRating;
	cin.ignore();
	movies* newMovie = new movies(mediaTitle, mediaYear, mediaDirector, mediaDuration, mediaRating);
	mediaFiles.push_back(newMovie);
      }
      else {
	cout << "Publisher: ";
	char mediaPublisher[80];
	cin.get(mediaPublisher, 80);
	cin.get();
	cout << "Rating: ";
	int mediaRating;
	cin >> mediaRating;
	cin.ignore();
	videogames* newVideoGame = new videogames(mediaTitle, mediaYear, mediaPublisher, mediaRating);
	mediaFiles.push_back(newVideoGame);
      }
    }
    //if you are searching or deleting
    else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "DELETE") == 0) {
      //note if you're deleting
      bool rid = false;
      if (strcmp(input, "DELETE") == 0) {
	rid = true;
      }
      cout << "would you like to use the title or year?" << endl;
      char input[80];
      cin.get(input, 80);
      cin.get();
      //be sure valid input
      while(!(strcmp(input, "title") == 0 || strcmp(input, "year") == 0)) {
	cout << "Invalid input. Please type keywords 'title' or 'year' to define your search" << endl;
	cin.get(input, 80);
	cin.get();
      }
      //if search by title
      if (strcmp(input, "title") == 0) {
	cout << "Title: ";
	char Title[80];
	cin.get(Title, 80);
	cin.get();
	bool found = false;
	vector<media*>::iterator mediaFind;
	int number = 0;
	//run through all media files
	for (mediaFind = mediaFiles.begin(); mediaFind != mediaFiles.end(); mediaFind++) {
	  //print media file if titles match
	  if ((*mediaFind)->isTitle(Title) == true) {
	    number++;
	    cout << "\nFound:" << endl;
	      cout << "\tTitle: ";
	      (*mediaFind)->getTitle();
	      cout << endl;
	      cout << "\tYear: " << (*mediaFind)->getYear() << endl;
	      //print out members by media type
	      if ((*mediaFind)->getType() == 1) {
		music* Music = (music*)(*mediaFind);
		cout << "\tArtist: ";
		Music->getArtist();
		cout << endl;
		cout << "\tDuration: " << Music->getDuration() << endl;
		cout << "\tPublisher: ";
		Music->getPublisher();
		cout << endl;
		cout << "\tType: Music" << endl;
	      }
	      else if ((*mediaFind)->getType() == 2) {
		movies* Movies = (movies*)(*mediaFind);
		cout << "\tDirector: ";
		Movies->getDirector();
		cout << endl;
		cout << "\tDuration: " << Movies->getDuration() << endl;
		cout << "\tRating: " <<  Movies->getRating() << endl;
		cout << "\tType: Movie" << endl;
	      }
	      else {
		videogames* VideoGames = (videogames*)(*mediaFind);
		cout << "\tPublisher: ";
		VideoGames->getPublisher();
		cout << endl;
		cout << "\tRating: " << VideoGames->getRating() << endl;
		cout << "\tType: Video Game" << endl;
	      }
	      found = true;
	    }
	}
	  if (found == false) {
	    cout << "Title not found" << endl;
	  }
	  cout << endl;
	  //if you're deleting, first double check
	  if (rid == true) {
	    cout << "Would you like to delete these files?\n1. Yes\n2. No" << endl;
	    int answer;
	    cin >> answer;
	    cin.ignore();
	    if (answer == 1) {
	      //run through all media files for however many media files you are deleting
	      for (int i = 0; i < number; i++) {
		vector<media*>::iterator mediaFinder;
	      for (mediaFinder = mediaFiles.begin(); mediaFinder != mediaFiles.end(); mediaFinder++) {
		//delete this media file if the titles match 
		if ((*mediaFinder)->isTitle(Title) == true) {
		  delete *mediaFinder;
		  mediaFiles.erase(mediaFinder);
		  break;
		}
	      }
	      }
	      cout << "Files deleted." << endl;
	    }
	    else {
	      cout << "You said 'No'" << endl;
	    }
	  }
      }
      //repeat the above process except by year
	else {
	  cout << "Year: ";
	  int Year;
	  cin >> Year;
	  cin.ignore();
	  bool found = false;
	  int counter = 0;
	  vector<media*>::iterator mediaFind;
	  for (mediaFind = mediaFiles.begin(); mediaFind != mediaFiles.end(); mediaFind++) {
	    if((*mediaFind)->getYear() == Year) {
	      counter++;
	      cout << "Found: \n" << endl;
	      cout << "\tTitle: ";
	      (*mediaFind)->getTitle();
	      cout << endl << "\tYear: " << (*mediaFind)->getYear() << endl;
	      if ((*mediaFind)->getType() == 1) {
		music* Music = (music*)(*mediaFind);
		cout << "\tArtist: ";
		(*Music).getArtist();
		cout << endl;
		cout << "\tDuration: " << (*Music).getDuration() << endl;
		cout << "\tPublisher: ";
		(*Music).getPublisher();
		cout << endl << "\tType: Music" << endl;
	      }
	      else if ((*mediaFind)->getType() == 2) {
		movies* Movie = (movies*)(*mediaFind);
		cout << "\tDirector: ";
		Movie->getDirector();
		cout << endl;
		cout << "\tDuration: " << Movie->getDuration() << endl;
		cout << "\tRating: " << Movie->getRating() << endl;
		cout << "\tType: Movie" << endl;
	      }
	      else {
		videogames* VideoGame = (videogames*)(*mediaFind);
		cout << "Publisher: ";
		VideoGame->getPublisher();
		cout << endl;
		cout << "Rating: " << VideoGame->getRating() << endl;
		cout << "Type: Video Game" << endl;
	      }
	      found = true;
	    }
	  }
	  if (found == false) {
	    cout << "No Media Found" << endl;
	  }
	  cout << endl;
	  if (rid == true) {
	    cout << "would you like to delete these files?\n1. Yes\n2. No" << endl;
	    int answer;
	    cin >> answer;
	    cin.ignore();
	    if (answer == 1) {
	      for (int i = 0; i < counter; i++) {
		vector<media*>::iterator mediaFinder;
	      for(mediaFinder = mediaFiles.begin(); mediaFinder != mediaFiles.end(); mediaFinder++) {
		if ((*mediaFinder)->getYear() == Year) {
		  delete *mediaFinder;
		  mediaFiles.erase(mediaFinder);
		  break;
		}
	      }
	      }
	      cout << "Files deleted" << endl;
	    }
	    else {
	      cout << "You said: No" << endl;
	    }
	  }
	}
    }
    //quit the program
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Goodbye" << endl;
      return 0;
    }
  }
  return 0;
}
