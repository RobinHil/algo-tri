#include<iostream>
#include<vector>
#include<string>

#include<cstdint>
#include<random>

#include<chrono>

#include"sort.hpp"

// génération des vector random avec les différentes contraintes de tri
void randomVector1(size_t size, std::vector<double>& v){
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0, max = size;

    std::uniform_real_distribution<double> distrib(min, max);
    for (size_t k=0; k<size; k++){
        double n = distrib(gen);
        v.push_back(n);
    }
}

void randomVector2(size_t size, std::vector<double>& v){
    for (size_t k=0; k<(size/2); k++)
        v.push_back(k);

    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0, max = size;

    std::uniform_real_distribution<double> distrib(min, max);
    for (size_t k=size/2; k<size; k++){
        double n = distrib(gen);
        v.push_back(n);
    }
}

void randomVector3(size_t size, std::vector<double>& v){
    for (size_t k=0; k<(size/2); k++)
        v.push_back(size-k);

    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0, max = size;

    std::uniform_real_distribution<double> distrib(min, max);
    for (size_t k=size/2; k<size; k++){
        double n = distrib(gen);
        v.push_back(n);
    }
}

void randomVector(int content, size_t size, std::vector<double>& v){
    if (content == 1)
        randomVector1(size, v);

    else if (content == 2)
        randomVector2(size, v);

    else if (content == 3)
        randomVector3(size, v);
}

// main
int main(int argc, char *argv[]){

    size_t size = std::stoi(argv[1]);
    int content = std::stoi(argv[2]);

    std::vector<double> vect;
    randomVector(content, size, vect);

    std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();

    sort::sortVector(vect);

    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
    size_t duration = std::chrono::duration_cast<std::chrono::milliseconds> (t_end - t_start).count();

    std::cout << size << " " << duration << std::endl;
    
    return EXIT_SUCCESS;
}