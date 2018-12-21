#include "FramePictureNode.h"
#include "PictureHandle.h"
#include <string>
#include <iostream>
using namespace std;
//FramePictureNode::FramePictureNode(PictureHandle *p_picture_node) : picture_handle_(shared_ptr<PictureHandle>(p_picture_node))
FramePictureNode::FramePictureNode(shared_ptr<PictureHandle> p_picture_node) : picture_handle_(p_picture_node) //
{
    width_ = picture_handle_->GetWidth() + 2;
    length_ = picture_handle_->GetLength() + 2;
    //cout << width_ << "  " << length_ << endl;
}

void FramePictureNode::PirntOneRaw(std::ostream &out, int num_row)
{
    if (num_row != 0 && num_row != length_ - 1)
    {
        out << "|";
        picture_handle_->PinctureNodePrintOneRow(out, num_row - 1);
        out << "|";
    }
    else
    {
        out << "+";
        out << string(width_ - 2, '-');
        out << "+";
    }
}