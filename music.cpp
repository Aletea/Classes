#include <iostream>
#include "music.h"
#include <cstring>

using namespace std;

//constructor- overwrite parent
music::music (char tt[], int yr, char art[], int dur, char pub[]) : media(tt, yr) {
  type = 1;
  int size = strlen(art);
  artist = new char[size];
  int count = 0;
  for(int i = 0; i < size; i++) {
    artist[i] = art[i];
    count++;
  }
  artist[count] = '\0';
  duration = dur;
  size = strlen(pub);
  publisher = new char[size];
  count = 0;
  for(int i = 0; i < size; i++) {
    publisher[i] = pub[i];
    count++;
  }
  publisher[count] = '\0';
}


//functions...
int music::getDuration() {
  return duration;
}
void music::getArtist() {
  cout << artist;
}

void music::getPublisher() {
  cout << publisher;
}
