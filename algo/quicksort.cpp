#include<algorithm>
#include<vector>

#include"../sort.hpp"

namespace sort{

    // méthode du quicksort => pivot = v[0]
    std::vector<double> sortVector(const std::vector<double>& v){
        if (v.size() <= 1)
            return v;

        double pivot = v[0];
        std::vector<double> v1, v2, v3;

        for (size_t x : v){
            if (x < pivot)
                v1.push_back(x);
            else if (x > pivot)
                v3.push_back(x);
            else
                v2.push_back(x);
        }
        
        v1 = sortVector(v1);
        v3 = sortVector(v3);
        v1.insert(v1.end(), v2.begin(), v2.end());
        v1.insert(v1.end(), v3.begin(), v3.end());

        return v1;
    }


} //namespace sort