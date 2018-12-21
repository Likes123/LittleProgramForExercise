/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** SourcePictureNode
*/

#ifndef SOURCEPICTURENODE_H_
#define SOURCEPICTURENODE_H_
#include "PictureNode.h"
#include <vector>
#include <string>

class SourcePictureNode : public PictureNode
{
  public:
    SourcePictureNode(std::initializer_list<std::string> &il);
    virtual void PirntOneRaw(std::ostream &out, int num_row) override;
  private:
    void Init();

  private:
    std::vector<std::string> data_;
};

#endif /* !SOURCEPICTURENODE_H_ */
