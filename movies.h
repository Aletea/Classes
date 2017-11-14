

#include <iostream>
#include "media.h"

using namespace std;

class movies : public media {
 public:
  //constructor
  movies(char title[], int year, char director[], int duration, int rating);
  //functions
  int getDuration();
  void getDirector();
  int getRating();

 private:
  //variables
  char *director;
  int duration;
  int rating;
};


