#include "tools.h"
std::ostream &operator<<(ostream &out, Picture &picture)
{
    picture.Print(out);
    return out;
}
Picture &operator|(Picture &picture_left, Picture &picture_right)
{
    picture_left.C_Cat(picture_right);
    return picture_left;
}
Picture &operator&(Picture &picture_left, Picture &picture_right)
{
    picture_left.V_Cat(picture_right);
    return picture_left;
}

Picture &frame(Picture &picture)
{
    picture.Frame();
    return picture;
}