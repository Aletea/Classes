#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>

using namespace std;

class media {
  friend ostream& operator<<(std::ostream& os, const media& md);
 public:
  //constructor, copy constructor, overloaded assignment, destructor
  media(char title[], int year);
  media(const media& source);
  media& operator=(const media& source);
  ~media();
  //functions
  int getType();
  int getYear();
  void getTitle();
  bool isTitle(char mediaTitle[]);

 private:
  //variables
  char *title;
  int year;
 protected:
  //keeps track of media type
  int type;
  
};

#endif
