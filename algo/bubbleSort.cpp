#include<algorithm>
#include<vector>

#include"../sort.hpp"

namespace sort{

    // méthode du tri à bulles
    std::vector<double> sortVector(const std::vector<double>& v){
        if (v.size() <= 1)
            return v;

        bool end = false;
        std::vector<double> vCpy = v;

        do{
            end = true;
            for (int i=1; i<(int)vCpy.size(); i++){
                if (vCpy[i]<vCpy[i-1]){
                    end = false;
                    std::swap(vCpy[i], vCpy[i-1]);
                }
            }
        } while (!end);
        
        return vCpy;
    }


} //namespace sort