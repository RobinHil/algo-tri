#include<iostream>
#include<vector>
#include<string>

#include<cstdint>
#include<random>

#include"sort.hpp"

// affichage de vector
void display(const std::vector<double> &v){
    std::cout << std::endl;
    for(int x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


// génération des vector random avec les différentes contraintes de tri
void randomVector(size_t size, std::vector<double>& v){
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0, max = size;

    std::uniform_real_distribution<double> distrib(min, max);
    for (size_t k=0; k<size; k++){
        double n = distrib(gen);
        v.push_back(n);
    }
}

// main
int main(){

    size_t size = 50;

    std::vector<double> vect;
    randomVector(size, vect);
    display(vect);

    std::vector<double> sortVect = sort::sortVector(vect);

    display(sortVect);
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}