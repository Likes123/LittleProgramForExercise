#include "SourcePictureNode.h"
#include <string>
using namespace std;
SourcePictureNode::SourcePictureNode(initializer_list<string> &il)
{
    for (auto &s : il)
        data_.push_back(s);
    Init();
}

void SourcePictureNode::Init()
{
    int max = 0;
    for (auto &s : data_)
    {
        if (s.size() > max)
            max = s.size();
    }

    for (auto &s : data_)
    {
        s = s + string(max - s.size(), ' ');
    }

    width_ = max;
    length_ = data_.size();
}

void SourcePictureNode::PirntOneRaw(std::ostream &out, int num_row)
{
    out << data_[num_row];
}
