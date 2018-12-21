#include "Picture.h"
#include "tools.h"
int main()
{
    Picture picture({"laili", "hello", "asdsafas"});
    vector<string> s{"laili", "hello", "asdsafas"};
    Picture picture2(s);
    // picture.Frame();
    // picture.C_Cat(picture2);
    // picture.Frame();
    // picture2.Frame();
    // picture.V_Cat(picture2);
    frame(picture);
    cout << (picture | picture2 | picture) << endl;
    cout << (picture & picture2 & picture) << endl;
    //picture.Print(cout);
    cout << picture << picture << endl;
    return 0;
}