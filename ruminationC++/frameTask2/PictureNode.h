/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** PictureNode
*/
#ifndef PICTURENODE_H_
#define PICTURENODE_H_
#include "Count.h"
#include "iostream"
class PictureNode
{
    friend class PictureHandle;

  public:
    virtual void PirntOneRaw(std::ostream &out, int num_row) = 0;
    // virtual int GetWidth() { return width_; }
    // virtual int GetLength() { return length_; }
    // virtual void SetWidth(int width) { width_ = width; }
    // virtual void SetLength(int length) { length_ = length; }

    virtual ~PictureNode() {}

  protected:
    int width_;
    int length_;
    Count count;
};
#endif /* !PICTURENODE_H_ */
