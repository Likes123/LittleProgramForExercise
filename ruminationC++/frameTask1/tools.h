/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** tools
*/

#ifndef TOOLS_H_
#define TOOLS_H_
#include "Picture.h"
#include <iostream>
std::ostream &operator<<(ostream &out, Picture &picture);
Picture &operator|(Picture &picture_left, Picture &picture_right);
Picture &operator&(Picture &picture_left, Picture &picture_right);
Picture &frame(Picture &picture);

#endif /* !TOOLS_H_ */
