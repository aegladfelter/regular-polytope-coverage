/**
*  file:	InitGenotype.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Solution Generator will randomly flip bits until we have a solution
*/

#include"../../Cover/Cover.h";
#include"../Algorithm.h";
#include<ctime>
#include<cstdlib>

class RandomSolutionAlgorithm : public Algorithm
{

private:

	void generateSolutions(Star* star)
	{

	
		// temp cover to find a solution
		Cover temp_cover(star);

		

		int index_to_select;

		std::vector<int> solution = {};

		while (!temp_cover.checkCover())
		{
			// get the random index to select
			index_to_select = rand() % temp_cover._bitVector.length();

			// select that index
			temp_cover.select(index_to_select);

			// store that to solution
			solution.push_back(index_to_select);
		}



		// push solution to _solutions
		_solutions.push_back(solution);
	}


public:
	
	RandomSolutionAlgorithm() {}

	void run(Star* star) 
	{
		// seed random number generation  with the time
		srand(std::time(nullptr));
		const int SOLUTIONS_TO_GENERATE = 10;

		for(int i = 0; i < SOLUTIONS_TO_GENERATE;i++) generateSolutions(star);
	}



};