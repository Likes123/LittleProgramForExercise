/*
** EPITECH PROJECT, 2018
** ruminationC++
** File description:
** Count
*/

#ifndef COUNT_H_
#define COUNT_H_
class Count
{
  public:
    //Count() : count(1) {}
    Count(unsigned int n = 1);
    void Add(unsigned int n=1);
    void Decrease(unsigned int n=1);
    unsigned int GetCount();

  private:
    unsigned int count;
};
#endif /* !COUNT_H_ */
