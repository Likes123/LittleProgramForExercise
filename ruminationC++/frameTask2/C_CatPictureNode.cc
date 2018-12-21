#include "C_CatPictureNode.h"
#include "PictureHandle.h"
#include <memory>
C_CatPictureNode::C_CatPictureNode(shared_ptr<PictureHandle> p_picture_node,
                                   shared_ptr<PictureHandle> p_other_picture_node)
    : left_picture_handle_(p_picture_node),
      right_picture_handle_(p_other_picture_node)
{
    width_ = left_picture_handle_->GetWidth() + right_picture_handle_->GetWidth();
    length_ = max(left_picture_handle_->GetLength(), right_picture_handle_->GetLength());
    //cout << width_ << "  " << length_ << endl;
}

void C_CatPictureNode::PirntOneRaw(std::ostream &out, int num_row)
{
    int len_min = min(left_picture_handle_->GetLength(), right_picture_handle_->GetLength());
    if (num_row < len_min)
    {
        left_picture_handle_->PinctureNodePrintOneRow(out, num_row);
        right_picture_handle_->PinctureNodePrintOneRow(out, num_row);
    }
    else
    {
        //cout << "num_row  " << num_row << endl;
        if (num_row < left_picture_handle_->GetLength())
        {
            left_picture_handle_->PinctureNodePrintOneRow(out, num_row);
            out << string(right_picture_handle_->GetWidth(), ' ');
        }
        else if (num_row < right_picture_handle_->GetLength())
        {
            out << string(left_picture_handle_->GetWidth(), ' ');
            right_picture_handle_->PinctureNodePrintOneRow(out, num_row);
        }
    }
}
