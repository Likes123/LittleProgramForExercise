#include "Picture.h"
Picture::Picture() {}
Picture::Picture(vector<string> &picture) : picture(picture.begin(), picture.end()) { Init(); }
Picture::Picture(initializer_list<string> il) : picture(il.begin(), il.end())
{
    Init();
    // for (auto &l : il)
    //     picture.push_back(l);
}

// Picture::~Picture()
// {
// }
// Picture::Picture(const Picture &other)
// {
// }
// Picture::Picture &operator=(Picture &other)
// {
// }
void Picture::Print(ostream &out)
{
    int width = Width();
    for (auto &s : picture)
    {
        cout << s << endl;
    }
}

void Picture::Frame()
{
    string temp(Width(), '-');
    int width = Width();
    for (auto &s : picture)
        s = "|" + s + string(width - s.size(), ' ') + "|";

    temp = "+" + temp + "+";
    picture.push_front(temp);
    picture.push_back(temp);
}

void Picture::C_Cat(Picture &other)
{
    int len = other.Length() - Length();
    if (len >= 0)
    {
        // for (int i = 0; i < len; i++)
        //     picture.push_back(string(Width(), ' '));
        picture.insert(picture.end(), len, string(Width(), ' '));

        for (int i = 0; i < other.picture.size(); i++)
            picture[i] = picture[i] + other.picture[i];
    }
    else
    {
        for (int i = 0; i < other.picture.size(); i++)
            picture[i] = picture[i] + other.picture[i];
        int other_width = other.Width();
        for (int i = other.Length(); i < picture.size(); i++)
            picture[i] = picture[i] + string(other_width, ' ');
    }
}
void Picture::V_Cat(Picture &other)
{
    picture.insert(picture.end(), other.picture.begin(), other.picture.end());
    Init();
}

void Picture::Init()
{
    int width = Width();
    for (auto &s : picture)
        s = s + string(width - s.size(), ' ');
}

unsigned int Picture::Width()
{
    unsigned int with = 0;
    for (auto &s : picture)
    {
        if (s.size() > with)
            with = s.size();
    }
    return with;
}
unsigned int Picture::Length()
{
    return picture.size();
}