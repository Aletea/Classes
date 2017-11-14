

#include <iostream>
#include "media.h"

using namespace std;

class music : public media {
 public:
  //constructor
  music(char title[], int year, char artist[], int duration, char publisher[]);
  int getDuration();
  void getArtist();
  void getPublisher();

 private:
  //variables
  char *artist;
  char *publisher;
  int duration;
 
};


