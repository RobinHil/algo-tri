#include<algorithm>
#include<vector>

#include"../sort.hpp"

namespace sort{

    // méthode std::stable_sort
    std::vector<double> sortVector(const std::vector<double>& v){
        if (v.size() <= 1)
            return v;

        std::vector<double> vCpy = v;

        std::stable_sort(vCpy.begin(), vCpy.end());
        return vCpy;
    }

} //namespace sort