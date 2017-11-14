#include "videogames.h"
#include <iostream>
#include <cstring>

using namespace std;
//constructor - overwrite parent
videogames::videogames(char tt[], int yr, char pub[], int rat) : media(tt, yr) {
  type = 3;
  int size = strlen(pub);
  publisher = new char[size];
  int count = 0;
  for (int i = 0; i < size; i++) {
    publisher[i] = pub[i];
    count++;
  }
  publisher[count] = '\0';
  rating = rat;
}

//functions...

void videogames::getPublisher() {
  cout << publisher;
}

int videogames::getRating() {
  return rating;
  
}
