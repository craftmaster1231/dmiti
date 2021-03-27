#include <iostream>
#include <list>
#include <vector>
#include <bitset>
using namespace std;
namespace cf { //compare functions
    template<typename T>
    bool TwoElcmp (vector<T>& lhv, vector<T>& rhv, int size) { //for maxmax or minmin only
        bool are_all_more = (lhv[0] >=
                             rhv[0]); // >= because if all criteria will be equal, point will be good for multitude
        for (int i = 0;i < size;i++) {
            if (lhv[0] >= rhv[0] != are_all_more) {
                /*it means, that one part of v1
                 * is more and other part
                 * is less. Therefore, points are
                 * incomparable*/
                return true;
            }
        }
        return false;
        // all elements are more or less => comparable
    }
}

int main() {

    return 0;
}

