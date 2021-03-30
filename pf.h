//
// Created by alex on 28.03.2021.
//

#ifndef DMITITOCOPY_PF_H
#define DMITITOCOPY_PF_H

#include <iostream>
#include <list>
#include <vector>
namespace pf { //Functions for Pareto multitude.
    /*
     * if lhv is better - returns true.
     * if incomparable  - returns true
     * if worse         - returns false
     * if same          - returns true
     */
    template<typename T>
    bool check (const std::vector<T>& lhv, const std::vector<T>& rhv) {
        if(lhv.size() != rhv.size()) {
            std::cout<<"check() different sizes!"<<std::endl; //debug thing
        }
        bool element_more=false; //do we found that any lhv[i] >rhv[i]
        bool element_less=false;
        int size = lhv.size();
        for(int i = 0;i<size;i++){
            if(lhv[i]>rhv[i]) {
                element_more = true;

            }
            if(lhv[i]<rhv[i]) {
                element_less = true;
            }
            if(!element_less && !element_more) {
                return true; //lhv and rhv are incomparable;
            }
        }
        /* if rhv and lhv are incomparable, it will be known in cycle.
         * So, lhv is only better, worse or equal than rhv.
         */
        if(element_less && element_more){
            return true;
        }
        if(element_more && !element_less) {
            return true; // lhv is better
        }
        return false; //lhv is worse

    }

    template<typename T>
    std::list<std::vector<T>>&& find_and_alloc_Pareto(const std::list<std::vector<T>>& base ) {
        auto current = base.begin();
        auto tocmp = base.begin();
        auto retn = new std::list<std::vector<T>>;
        for(int i=0; i<base.size();i++) {
            bool is_in_miltitude = true;
            for(int j=0; j<base.size();j++) {
                if(i==j) {
                    ++tocmp;
                    continue;
                }
                if(!check(*current,*tocmp)) {
                    is_in_miltitude = false;
                    break;
                }
                ++tocmp;
            }
            if(is_in_miltitude){
                retn->push_back(std::vector<T>{*current});
            }
            tocmp = base.begin();
            ++current;
        }
        return std::move(*retn);
    }
}
#endif //DMITITOCOPY_PF_H