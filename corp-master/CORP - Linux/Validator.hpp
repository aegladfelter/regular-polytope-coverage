#ifndef _VALIDATOR_GUARD
#define _VALIDATOR_GUARD



#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Cover.h"

class Validator
{
  public:
    bool checkSolution(Cover& cover, std::vector<int> solution)
    {
        for (int vertex : solution) cover.select(vertex);

        return cover.checkCover();
    }
	/*
    bool checkSolutions(Cover& cover, std::string solutions_file) {
        std::ifstream solutions(solutions_file);

        std::string line;
        std::vector<int> solution;
        bool allTrue = true;

        while (std::getline(solutions, line)) {
            std::istringstream ss(line);
            int num;
            while (ss >> num) {
                solution.push_back(num);
            }
            if (!checkSolution(cover, solution)) {
                std::cerr << "The Following Solution Failed:\n";
                for (int num : solution) { std::cout << num << " "; }
                std::cout << std::endl;
                allTrue = false;
            }
        }

        solutions.close();
        return allTrue;
    }
	*/
};

#endif