#include <iostream>
#include <list>
#include <vector>
#include "pf.h"
#include <algorithm>

void applyMask(std::list<std::vector<int>>& list,std::vector<bool>& mask){
    std::for_each(list.begin(),list.end(),[&](std::vector<int>& to_apply){
        int i{0};
        std::for_each(to_apply.begin(),to_apply.end(),[&](int& to_apply){
            if(!mask[i])
                to_apply*=-1;
            ++i;
        });
    });
}
int main() {
    std::cout<<"Enter number of parameters for each object"<<std::endl;
    int vectorSize{0};
    std::cin>>vectorSize;
    std::cout<<std::endl;
    std::cout<<"Enter number of objects"<<std::endl;
    int listSize{0};
    std::cin>>listSize;
    std::list<std::vector<int>> base(listSize);
    std::cout<<"Enter MIN and MAX mask"<<std::endl;
    int mask_size = vectorSize;
    std::vector<bool> mask(mask_size,false);
    for(int i{0};i<mask_size;++i){
        std::string tmp{};
        std::cin>>tmp;
        if(tmp=="MAX")
            mask[i] = true;
    }
    int i{0};
    std::for_each(base.begin(),base.end(),[&](std::vector<int>& to_write){
        to_write.resize(vectorSize);
        std::cout<<"Enter parameters of object "<<++i<<std::endl;
        std::for_each(to_write.begin(),to_write.end(),[](int& to_write){
            std::cin>>to_write;
        });
    });
    applyMask(base,mask);
    auto Pareto = pf::find_Pareto(base);
    std::cout<<"Pareto multitude: \t"<<std::endl;
    applyMask(Pareto,mask);// Deapply. It does same
    pf::printmultitude(Pareto);
    return 0;
}
