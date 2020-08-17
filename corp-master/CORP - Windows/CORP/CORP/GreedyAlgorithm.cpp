#include<iostream>
#include <crtdbg.h>

#include "GreedyAlgorithm.h"
#include "Config\Config.h"
#include <vector>
#include <algorithm>

GreedyAlgorithm::GreedyAlgorithm()
{
}

GreedyAlgorithm::~GreedyAlgorithm()
{
}

void GreedyAlgorithm::run(Star * star)
{
	_star = star;

	std::vector<int> firstSolution;

	_partialSolutions.push_back(firstSolution);

	runHelper();

	std::cout << "Execution complete." << std::endl;

}

int GreedyAlgorithm::getValue(Cover& original, int vertex)
{
	Cover tempCover(original);

	tempCover.select(vertex);

	return tempCover.facetsCovered();
}

void GreedyAlgorithm::runHelper()
{
	std::vector<std::vector<int>> newSolutions;
	//loop through all partial solutions
	for each (std::vector<int> solution in _partialSolutions)
	{
		//check if solution is partial or not
		Cover tempCover(_star);
		for each (int vert in solution)
		{
			tempCover.select(vert);
		}
		//if it is, continue, else, add to solutionList
		if (!tempCover.checkCover())
		{
			int bestWeight = 0;
			std::vector<int> tempList;

			//loop through the vertices in the cover
			for (int vert = 0; vert < tempCover.vertices; vert++)
			{
				//calculate how many new facets the given vertex would cover
				int weight = getValue(tempCover, vert);

				if (weight > bestWeight)
				{
					bestWeight = weight;
					//if greediness is 0, clear the whole list to save time, 
					if (greedinessMod == 0)
						tempList.clear();
					else
					{
						//otherwise, remove all vertices who's value falls out of range of the new best weight
						std::vector<int> newList;
						for each (int tempVert in tempList)
						{
							if ((getValue(tempCover, tempVert) + greedinessMod) >= bestWeight)
								newList.push_back(tempVert);
						}
						tempList = newList;
					}
				}
				else if ((weight + greedinessMod) >= bestWeight)
				{
					//if the vertex's weight is not a new best, but is within range of it, add it to the list
					tempList.push_back(vert);
				}

			}
			for each (int vert in tempList)
			{
				//add the new solutions to the solution list
				std::vector<int> newSol(solution);
				newSol.push_back(vert);
				newSolutions.push_back(newSol);
			}
		}
		else
			_solutions.push_back(solution);
	}
	//if there are no new solutions to parse, end. otherwise recurse
	if (!newSolutions.empty)
	{
		_partialSolutions = newSolutions;
		runHelper();
	}
}
