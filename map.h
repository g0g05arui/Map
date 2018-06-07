#ifndef M
#define M
#include "vector.h"
template<class Cont,class Key,class Hash>
class Map{
private:
    struct ST{int x;Key y;};
    Vector<ST>v;
public:
    void insert(Cont,Key);
    Key & operator [](Cont);
    int size();
};
#include "map.hpp"
#endif
