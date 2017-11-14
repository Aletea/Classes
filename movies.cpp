#include <iostream>
#include "movies.h"
#include <cstring>

using namespace std;

//constructor- overwrite parent constructor
movies::movies (char tt[], int yr, char dir[], int dur, int rat) : media(tt, yr) {
  type = 2;
  int size = strlen(dir);
  director = new char[size];
  int count = 0;
  for (int i = 0; i < size; i++) {
    director[i] = dir[i];
    count++;
  }
  director[count] = '\0';
  duration = dur;
  rating = rat;
}

//return or print different members

int movies::getDuration() {
  return duration;
}

int movies::getRating() {
  return rating;
}

void movies::getDirector() {
  cout << director;
}
