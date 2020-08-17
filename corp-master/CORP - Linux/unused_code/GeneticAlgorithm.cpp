/**
*  file:	GeneticAlgorithm.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Execute a genetic algorithm with the provided
*  genetic operators.
*
*
*/

#include"GeneticAlgorithm.h"
#include"RandomInitGenotype.h"
#include"Genotype.h"
#include<ctime>



#include"OnePointCrossover.h"
#include"BitFlipMutation.h"
#include"CoverPercentRatioFitness.h"

#include <fstream>

/*
void GeneticAlgorithm::run(Star* star) 
{
	// seed random number generation
	srand(std::time(nullptr));

	// the size of the initial genotype
	const int INIT_GENOTYPE_SIZE = 50;

	
	RandomInitGenotype rig;
	Genotype geno;
	BitFlipMutation bitflip;
	CoverPercentRatioFitness fit;
	OnePointCrossover cross;
	const int step = 1;
	geno = rig.fillGenotype(star, INIT_GENOTYPE_SIZE);
	int i = 0;
	std::ofstream myfile;

	Chromosome most_fit = geno.getMostFit();
	bool toggle = true;

	//  -> mutate -> set fitness -> crossover ->
	while (true) 
	{
		// periodically print the genotype and the current generation
		if (i % 100 == 0) 
		{
			std::cout << "Generation:\t" << i << std::endl;

			std::cout << geno.toString() << std::endl;
		}

		// perform STEP_SIZE mutations
		for (int i = 0; i < step; i++)
		{
			// mutate each chromosome in the genotype
			bitflip.mutateGenotype(geno);

			// check if we have a solution after each mutation
			for (Chromosome chromo : geno.getChromosomes())
			{
				// if a solution is found print it and write it to SOLUTION_FILE
				if (chromo.getCover().checkCover())
				{
					std::cout << "-----------------------------------------\n";
					// print solution
					std::cout << "SOLUTION FOUND\n" << std::endl;
					std::cout << chromo.getCover()._bitVector.length() << "\t|\t" << chromo.getCover()._bitVector.numberSelected() << "\t|\t" << chromo.getCover().toString() << "\n";
					std::cout << std::endl;

					// write to SOLUTION_FILE
					myfile.open("C:/Users/Steven/Source/Repos/corp13/corp/CORP/CORP/Algorithm/GeneticAlgorithm/solutions.txt", std::ios::app);
					myfile << chromo.getCover()._bitVector.length() << "\t|\t" << chromo.getCover()._bitVector.numberSelected() << "\t|\t" << chromo.getCover().toString() << "\n";
					myfile.close();
					std::cout << "-----------------------------------------\n";
				}
			}
		}

		fit.setFitness(geno);

		cross.performCrossover(geno, star);
		
		i++;

	}
	


}
*/


