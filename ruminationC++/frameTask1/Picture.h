/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** Picture
*/

#ifndef PICTURE_H_
#define PICTURE_H_
#include <iostream>
#include <deque>

#include <vector>
#include <string>
using namespace std;
class Picture
{
  friend std::ostream &operator<<(ostream &out, Picture &picture);
  friend Picture &operator|(Picture &picture_left, Picture &picture_right);
  friend Picture &operator&(Picture &picture_left, Picture &picture_right);
  friend Picture &frame(Picture &picture);

public:
  Picture();
  Picture(vector<string> &picture);
  Picture(initializer_list<string> il);
  // ~Picture();
  // Picture(const Picture &other);
  // Picture &operator=(Picture &other);

private:
  unsigned int Width();
  unsigned int Length();
  void Print(ostream &out);
  void Frame();
  void C_Cat(Picture &other);
  void V_Cat(Picture &other);
  void Init();

private:
  deque<string> picture;
};

#endif /* !PICTURE_H_ */
