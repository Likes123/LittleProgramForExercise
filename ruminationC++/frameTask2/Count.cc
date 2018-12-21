#include "Count.h"
Count::Count(unsigned int n) : count(n) {}
void Count::Add(unsigned int n) { count = count + n; }
void Count::Decrease(unsigned int n) { count = count - n; }
unsigned int Count::GetCount()
{
    return count;
}
