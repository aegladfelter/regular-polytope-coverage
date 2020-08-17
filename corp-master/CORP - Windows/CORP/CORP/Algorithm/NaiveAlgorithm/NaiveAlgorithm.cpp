#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include"NaiveAlgorithm.h"
#include"../../Config/Config.h"
#include<vector>
#include<algorithm>

void NaiveAlgorithm::run(Star* star)
{
    Cover baseCover(star);

    //// call recursive helper method
    int max = 48;
    max = Config::getInstance()->pull("MAX_SOLUTION", max);

	runHelper(baseCover, max);

    std::cout << "Execution complete." << std::endl;
}

// return true if an element is a vector
template<typename T>
bool inSolution(const std::vector<T>& solution, const T& element)
{
	return std::find(solution.begin(), solution.end(), element) != solution.end();
}

void NaiveAlgorithm::runHelper(const Cover& cover, int MAX_SIZE, std::vector<int> solution)
{

	// we know min solution, so don't check past there
	if (solution.size() > MAX_SIZE) return;

	// if we found a solution, save it to _solution_set
	if (cover.checkCover())
	{
		_solutions.push_back(solution);

		static int sol = 0;
		std::cout << "Solution " << sol++ << ": " << std::endl;
		for (auto val : solution)
			std::cout << val << " ";
		std::cout << std::endl;

		// kill this branch because every solution following will be a solution of greater length
		return;
	}

	for (int vertex = cover.vertices(); vertex >= 0; vertex--)
	{
		// create a temporary cover and solution set for each branch
		Cover temp_cover(cover);
		std::vector<int> temp_solution = solution;

		// push the current node to the solution
		temp_solution.push_back(vertex);

		// turn on the current vertex in the cover
		temp_cover.select(vertex);

		runHelper(temp_cover, MAX_SIZE, temp_solution);

		// order doesn't matter, don't pursue repetitive solutions and don't pick the same vertex twice
		if (!solution.empty() && vertex <= solution.at(solution.size() - 1)) return;
	}
}
