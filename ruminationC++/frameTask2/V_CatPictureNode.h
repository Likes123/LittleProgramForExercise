/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** V_CatPictureNode
*/
#ifndef V_CATPICTURENODE_H_
#define V_CATPICTURENODE_H_
#include "PictureNode.h"
#include <memory>
using namespace std;
class PictureHandle;
class V_CatPictureNode : public PictureNode
{
  public:
    // V_CatPictureNode(PictureHandle* p_picture_node,
    //                  PictureHandle* p_other_picture_node);
    V_CatPictureNode(shared_ptr<PictureHandle> p_picture_node,
                     shared_ptr<PictureHandle> p_other_picture_node);
    virtual void PirntOneRaw(std::ostream &out, int num_row) override;

  private:
    std::shared_ptr<PictureHandle> up_picture_handle_;
    std::shared_ptr<PictureHandle> down_picture_handle_;
};
#endif /* !V_CATPICTURENODE_H_ */
