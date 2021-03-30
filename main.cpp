#include <iostream>
#include <list>
#include <vector>
#include "pf.h"
#include <forward_list>
int main() {
    std::cout<<"Enter number of parameters for each object"<<std::endl;
    int vectorSize;
    std::cin>>vectorSize;
    std::cout<<"Enter number of objects"<<std::endl;
    int listSize;
    std::cin>>listSize;
    std::list<std::vector<int>> base(listSize);
    auto listIt = base.begin();
    for(int i=0;i<listSize;i++) {
        std::cout<<"Enter parameters of object "<<i+1<<std::endl;
        for(int j=0;j<vectorSize;j++) {
            int tmp;
            std::cin>>tmp;
            (*listIt).push_back(tmp);
        }
        ++listIt;
    }
    std::cout<<std::endl;
    auto Pareto = pf::find_and_alloc_Pareto(base);
    pf::printmultitude(Pareto);
    return 0;
}

