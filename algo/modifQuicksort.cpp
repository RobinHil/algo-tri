#include<algorithm>
#include<vector>

#include<cstdint>
#include<iostream>
#include<random>

#include"../sort.hpp"

namespace sort{

    // génération du pivot aléatoire
    size_t randomP(const size_t max, const size_t min = 0){
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<size_t> distrib(min, max);
        size_t i = distrib(gen);

        return i;
    }

    // méthode du quicksort modifié => pivot aléatoire
    std::vector<double> sortVector(const std::vector<double>& v){
        if (v.size() <= 1)
            return v;

        double pivot = v[randomP(v.size()-1)];
        std::vector<double> v1, v2, v3;

        for (double x : v){
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