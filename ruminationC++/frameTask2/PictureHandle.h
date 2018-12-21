/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** PictureHandle
*/

#ifndef PICTUREHANDLE_H_
#define PICTUREHANDLE_H_
#include <iostream>
#include <memory>
#include <string>
using namespace std;
class PictureNode;
class PictureHandle : public enable_shared_from_this<PictureHandle>
{
    friend class FramePictureNode;

  public:
    PictureHandle(initializer_list<string> il);
    //PictureHandle() {}
    //PictureHandle(const PictureHandle& other);

    //private:
    void Print(ostream &out);
    void PinctureNodePrintOneRow(ostream &out, int num_row);
    void Frame();
    void C_Cat(PictureHandle &other);
    void V_Cat(PictureHandle &other);

    int GetWidth();
    int GetLength();
    // int SetWidth(int width);
    // int SetLength(int length);
    shared_ptr<PictureHandle> GetThis();

  private:
    shared_ptr<PictureNode> p_picture_node_;
    // int width_;
    // int length_;
};

#endif /* !PICTUREHANDLE_H_ */
