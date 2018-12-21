#include "V_CatPictureNode.h"
#include "PictureHandle.h"
V_CatPictureNode::V_CatPictureNode(shared_ptr<PictureHandle> p_picture_node,
                                   shared_ptr<PictureHandle> p_other_picture_node)
    : up_picture_handle_(p_picture_node),
      down_picture_handle_(p_other_picture_node)
{
    width_ = max(up_picture_handle_->GetWidth(), down_picture_handle_->GetWidth());
    length_ = up_picture_handle_->GetLength() + down_picture_handle_->GetLength();
}

void V_CatPictureNode::PirntOneRaw(std::ostream &out, int num_row)
{
    if (num_row < up_picture_handle_->GetLength())
    {
        up_picture_handle_->PinctureNodePrintOneRow(out, num_row);
        if (up_picture_handle_->GetWidth() < width_)
            out << string(width_ - up_picture_handle_->GetWidth(), ' ');
    }
    else
    {
        down_picture_handle_->PinctureNodePrintOneRow(out, num_row - up_picture_handle_->GetLength());
        if (down_picture_handle_->GetWidth() < width_)
            out << string(width_ - down_picture_handle_->GetWidth(), ' ');
    }
}
