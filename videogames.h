

#include <iostream>
#include "media.h"

using namespace std;

class videogames : public media {
 public:
  videogames(char title[], int year, char publisher[], int rating);
  void getPublisher();
  int getRating();

 private:
  char *publisher;
  int rating;

};


