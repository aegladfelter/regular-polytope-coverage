#ifndef _ALGORITHM_CONTAINER_GUARD
#define _ALGORITHM_CONTAINER_GUARD 1


#include"Algorithm.h"
#include "NaiveAlgorithm.h"
#include"Config.h"

#include <vector>
#include <memory>

template <typename TheAlgorithm_T>
class AlgorithmRunner
{
public:
    AlgorithmRunner() {}

	// run the algorithm provided in the constructor with the given cover
	bool start(Star* star)
    {
        _algorithm.run(star);

        return _algorithm.getSolutions().size() != 0;
    }

	// get 2d vector representation of solution set
	std::vector<std::vector<int>> getSolutionSet() const
    {
        // increment all vertices by 1 before returning the solution set
        std::vector<std::vector<int>> result = _algorithm.getSolutions();

        for (auto solution : result)
            for (int& vertex : solution) vertex++;

        return result;
    }

	// get string representation of solution set
	std::string toString() const
    {
		if (getSolutionSet().size() == 0) return "No solutions found";
        std::string result = "";

        int count = 1;
        for (std::vector<int> solution : getSolutionSet())
        {
            result += std::to_string(count++) + ": ";
            for (int vertex : solution)
            {
                result += (std::to_string(vertex) + " ");
            }
            result += "\n";
        }

        return result;
    }

	// output toString to a text file
    // CTA: unimplemented
	//void write(const std::string& file_path);

protected:
    TheAlgorithm_T _algorithm;
	std::vector<std::vector<int>> _solutions;
};


#endif
