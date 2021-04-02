#include <iostream>
#include <list>
#include <vector>
#include "pf.h"
int main() {
    std::cout<<"Enter number of parameters for each object"<<std::endl;
    int vectorSize;
    std::cin>>vectorSize;
    std::cout<<std::endl;
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

    base.sort(vec_Comparator<int>());
    auto Pareto = pf::find_and_alloc_Pareto(base);
    std::cout<<"Pareto multitude: \t"<<std::endl;
    pf::printmultitude(Pareto);
    return 0;
}
