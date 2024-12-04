// #include <greeter/greeter.h>

#include"dataset/dataset.h"
#include <cxxopts.hpp>
#include <iostream>
#include <string>
#include <unordered_map>



auto main(int argc, char** argv) -> int {

    Dataset dataset("/home/naruto/projects/datasets/audible_uncleaned.csv");
    std::cout<<"hello world"<<std::endl;
    // Add columns

    // Access column data
    std::vector<std::string> names = dataset["name"];
    std::cout<<dataset["name"][0];
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    // Access specific data
    // std::cout << "Name at index 1: " << dataset("Name", 1) << "\n";  // Bob

    // Print entire dataset
    // dataset.print();

    return 0;
}


