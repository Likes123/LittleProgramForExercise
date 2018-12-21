#include "PictureHandle.h"
#include "SourcePictureNode.h"
#include "FramePictureNode.h"
#include "C_CatPictureNode.h"
#include "V_CatPictureNode.h"
#include "iostream"
using namespace std;
PictureHandle::PictureHandle(initializer_list<string> il)
{
    p_picture_node_ = make_shared<SourcePictureNode>(il);
    // cout << p_picture_node_->width_ << "  " << p_picture_node_->length_ << endl;
}
void PictureHandle::Frame()
{
    //PictureHandle source_picture_handle(*this);
    //auto p = new PictureHandle(*this);
    auto p = make_shared<PictureHandle>(*this);
    //cout << p->p_picture_node_->width_ << "  " << p->p_picture_node_->length_ << endl;
    p_picture_node_ = make_shared<FramePictureNode>(p->GetThis());
}
void PictureHandle::C_Cat(PictureHandle &other)
{
    //PictureHandle source_picture_handle(*this);
    auto p = make_shared<PictureHandle>(*this);
    auto q = make_shared<PictureHandle>(other);
    p_picture_node_ = make_shared<C_CatPictureNode>(p->GetThis(), q->GetThis());
}
void PictureHandle::V_Cat(PictureHandle &other)
{
    //PictureHandle source_picture_handle(*this);
    auto p = make_shared<PictureHandle>(*this);
    auto q = make_shared<PictureHandle>(other);
    p_picture_node_ = make_shared<V_CatPictureNode>(p->GetThis(), q->GetThis());
}
void PictureHandle::Print(ostream &out)
{
    int len = p_picture_node_->length_;
    //cout << len << endl;
    for (int i = 0; i < len; i++)
    {
        PinctureNodePrintOneRow(out, i);
        out << endl;
    }
}

void PictureHandle::PinctureNodePrintOneRow(ostream &out, int num_row)
{
    p_picture_node_->PirntOneRaw(out, num_row);
}

shared_ptr<PictureHandle> PictureHandle::GetThis()
{
    return shared_from_this();
}

int PictureHandle::GetWidth()
{
    return p_picture_node_->width_;
}
int PictureHandle::GetLength()
{
    return p_picture_node_->length_;
}
// int PictureHandle::SetWidth(int width)
// {
//     width_ = width;
// }
// int PictureHandle::SetLength(int length)
// {
//     length_ = length;
// }