#include<algorithm>
#include<vector>

#include"../sort.hpp"

namespace sort{

    // méthode du tri par insertion
    std::vector<double> sortVector(const std::vector<double>& v){
        if (v.size() <= 1)
            return v;

        std::vector<double> vCpy = v;        

        for (int i=0; i<(int)vCpy.size(); i++){
            bool end = true;
            int j = i;

            while (end && (j>=1)){
                end = (vCpy[j-1]>vCpy[j]);
                if (end)
                    std::swap(vCpy[j-1], vCpy[j]);
                j -= 1;   
            }   
        }
        return vCpy;
    }


} //namespace sort