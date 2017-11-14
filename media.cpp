#include <iostream>
#include "media.h"
#include <cstring>

using namespace std;

//constructor
media::media (char tt[], int yr) {
  //set title, year, and type
  type = 0;
  int size = strlen(tt);
  title = new char[size];
  int count = 0;
  for (int i = 0; i < strlen(tt); i++) {
    title[i] = tt[i];
    count++;
  }
  title[count] = '\0';
  year = yr;
}

//useless copy constructor that I'm too lazy to delete
media::media(const media& source) {
  //cout << "Copy Constructor" << endl;
  int size = strlen(source.title);
  title = new char[size];
  int count = 0;
  for (int i = 0; i < strlen(source.title); i++) {
    title[i] = source.title[i];
    count++;
  }
  title[count] = '\0';
  this->year = source.year;
  this->type = 0;
}

//useless overloaded assignment that I'm too lazy too delete
media& media::operator=(const media& source) {
  //cout << "Overloaded Assignment" << endl;
  if (this == &source) {
    return *this;
  }
  int count = 0;
  for (int i = 0; i < strlen(source.title); i++) {
    title[i] = source.title[i];
    count++;
  }
  title[count] = '\0';
  this->year = source.year;
  this->type = 0;
  return *this;
  }

//the very important deconstructor
  media::~media() {
    //cout << "Destructor for " << this->title << " @" << this << endl;
    delete[] title;
  }

//returns year, title, type, etc.

int media::getYear() {
  return year;
}

int media::getType() {
  return type;
}

void media::getTitle() {
  cout << title;
}

bool media::isTitle(char mediaTitle[]) {
  int size = strlen(title);
  for(int i = 0; i < size; i++) {
    if (title[i] != mediaTitle[i]) {
      return false;
    }
  }
  return true;
}
