#ifndef MH
#include "map.h"
#define MH
#define T template<class Cont,class Key,class Hash>
T void Map<Cont,Key,Hash>::insert(Cont x,Key y){
    int hash=Hash::hash_(x);
    int p2=1<<28,r=0;
        while(p2)
        {
            if(p2+r<v.size())
                if(v[p2+r-1].x<=hash)
                    r+=p2;
            p2/=2;
        }
    if(!v.empty() && v.back().x<hash)
        v.push_back((ST){hash,y});
    else
        v.insert((ST){hash,y},std::max(0,r));
     for(int i=0;i<v.size();i++)
        std::cout<<v[i].x<<" ";
    std::cout<<'\n';
}
T Key & Map<Cont,Key,Hash>::operator [](Cont x){
    int hash=Hash::hash_(x);
    int i=0;
        int p2=(1<<29),r=0;
        while(p2)
        {
            if(p2+r-1<v.size())
                if(v[p2+r-1].x<=hash)
                    r+=p2;
            p2/=2;
        }
    return v[r-1].y;
}
#undef T
#endif // MH
