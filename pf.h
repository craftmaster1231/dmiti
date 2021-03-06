//
// Created by alex on 28.03.2021.
//

#ifndef DMITITOCOPY_PF_H
#define DMITITOCOPY_PF_H

#include <iostream>
#include <list>
#include <vector>
namespace pf { //Functions to work with Pareto multitude.
    /*
     * if lhv is better         - returns true.
     * if lhv isincomparable    - returns true
     * if lhv is worse          - returns false
     * if same                  - returns true
     */
    template<typename T>
    bool check (const std::vector<T>& lhv, const std::vector<T>& rhv) {
        if(lhv.size() != rhv.size()) {
            std::cout<<"check() different sizes!"<<std::endl; //debug thing
        }
        bool element_more=false;    //do we found that any lhv[i] > rhv[i]
        bool element_less=false;    //do we found that any lhv[i] < rhv[i]
        int size = lhv.size();
        for(int i = 0;i<size;i++){
            if(lhv[i]>rhv[i]) {
                element_more = true;

            }
            if(lhv[i]<rhv[i]) {
                element_less = true;
            }
            if(element_less && element_more) {
                return true; //lhv and rhv are incomparable;
            }
        }
        /* if rhv and lhv are incomparable, it will be known in cycle.
         * So, lhv is only better, worse or equal than rhv.
         */
        if(!element_less && !element_more){ // are same
            return true;
        }
        if(element_more && !element_less) {
            return true; // lhv is better
        }
        return false; //lhv is worse

    }

    template<typename T>
    std::list<std::vector<T>> find_Pareto(const std::list<std::vector<T>>& base) {
        auto current = base.begin();
        auto tocmp = base.begin();
        std::list<std::vector<T>> retn;
        const int list_size = base.size();
        for(int i=0; i<list_size;i++) {
            bool is_in_multitude = true;
            for(int j=0; j<list_size;j++) {
                if(i==j) {
                    ++tocmp;
                    continue;
                }
                if(!check(*current,*tocmp)) {
                    is_in_multitude = false;
                    break;
                }
                ++tocmp;
            }
            if(is_in_multitude){
                retn.push_back(std::vector<T>{*current});
            }
            tocmp = base.begin();
            ++current;
        }
        return retn;
    }

    template<typename T>
    void printmultitude(const std::list<std::vector<T>>& multitude_to_print) {
        if(multitude_to_print.empty()) {
            std::cout<<"multitude is free!"<<std::endl;
            return;
        }
        auto it = multitude_to_print.begin();
        const int list_size = multitude_to_print.size();
        const int vec_size = multitude_to_print.begin()->size();
        for(int i=0;i < list_size;i++) {
            std::cout<<"Object:\t";
            for(int j=0;j < vec_size;j++) {
                std::cout<<(*it)[j]<<" ";
            }
            std::cout<<std::endl;
            ++it;
        }
        std::cout<<std::endl;
    }
}



#endif //DMITITOCOPY_PF_H