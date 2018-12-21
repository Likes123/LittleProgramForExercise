/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** C_CatPictureNode
*/
#ifndef C_CATPICTURENODE_H_
#define C_CATPICTURENODE_H_
#include "PictureNode.h"
#include <memory>
using namespace std;
class PictureHandle;
class C_CatPictureNode : public PictureNode
{
  public:
    //C_CatPictureNode(PictureHandle* p_picture_node,
    //                 PictureHandle* p_other_picture_node);
    C_CatPictureNode(shared_ptr<PictureHandle> p_picture_node,
                     shared_ptr<PictureHandle> p_other_picture_node);
    virtual void PirntOneRaw(std::ostream &out, int num_row) override;

  private:
    std::shared_ptr<PictureHandle> left_picture_handle_;
    std::shared_ptr<PictureHandle> right_picture_handle_;
};
#endif /* !C_CATPICTURENODE_H_ */
