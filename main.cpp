#include <iostream>
#include <list>
#include <vector>
#include <bitset>
using namespace std;
namespace cf { //compare functions.
    /*
     * Function checks, is point better than other one
     * in ALL parameters. Works only for ALLMAX and ALLMIN cases
     */
    template<typename T>
    bool TwoElcmp (vector<T>& lhv, vector<T>& rhv) {
        bool are_all_more = (lhv[0] >=rhv[0]); // >= because if all criteria will be equal, point also not better
        for (int i = 0;i < lhv.size();i++) {
            if ((lhv[i] >= rhv[i]) != are_all_more) {
                /*it means, that one part of v1
                 * is more than v2 and other part
                 * is less. Therefore, points are
                 * incomparable*/
                return true;
            }
        }
        // all elements are more or less => comparable
        return false;
    }
}

int main() {
    vector<int> v1 = {1,3,3,4,5};
    vector<int> v2 = {3,1,4,5,6};
    std::cout<<cf::TwoElcmp(v1,v2);
    return 0;
}

