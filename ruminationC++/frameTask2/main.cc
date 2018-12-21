#include "PictureHandle.h"
#include <iostream>
#include <memory>
using namespace std;
int main()
{
    PictureHandle picture({"hello", "laili", "dsafsafd"});
    //auto picture = make_shared<PictureHandle>(picture1);
    PictureHandle picture1({"hello", "laili"});
    picture1.Frame();
    picture.V_Cat(picture1);
    picture.Frame();
    picture.C_Cat(picture1);
    picture.Frame();

    picture.Print(std::cout);
    return 0;
}