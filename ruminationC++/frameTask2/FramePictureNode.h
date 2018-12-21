/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** FramePictureNode
*/
#ifndef FRAMEPICTURENODE_H_
#define FRAMEPICTURENODE_H_
#include "PictureNode.h"
#include <memory>
class PictureHandle;
class FramePictureNode : public PictureNode
{
  public:
    //FramePictureNode(PictureHandle *p_picture_node);
    FramePictureNode(std::shared_ptr<PictureHandle> p_picture_node);
    virtual void PirntOneRaw(std::ostream &out, int num_row) override;

  private:
    std::shared_ptr<PictureHandle> picture_handle_;
};
#endif /* !FRAMEPICTURENODE_H_ */
