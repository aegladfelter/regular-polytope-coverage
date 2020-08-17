/**
*  file:	GeneticAlgorithm.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Execute a genetic algorithm with the provided
*  genetic operators.
*
*
*/



#ifndef _GENETIC_ALGORITHM_
#define _GENETIC_ALGORITHM_

#include"GeneticOperator\GeneticOperator.h"
#include"GeneticOperator\Crossover\Crossover.h"
#include"GeneticOperator\InitGenotype\InitGenotype.h"
#include"GeneticOperator\Mutation\Mutation.h"
#include"../Algorithm.h"
#include"GeneticAlgorithm.h"
#include"GeneticOperator\InitGenotype\RandomInitGenotype\RandomInitGenotype.h"
#include"Genotype\Genotype.h"
#include<ctime>
#include"GeneticOperator\Crossover\OnePointCrossover\OnePointCrossover.h"
#include"GeneticOperator\Mutation\BitFlipMutation\BitFlipMutation.h"
#include"GeneticOperator\Fitness\CoverPercentRatioFitness\CoverPercentRatioFitness.h"
#include <fstream>

template <typename TheInitPopulation_T, typename TheMutation_T, 
	typename TheFitness_T,typename TheCrossover_T,typename ThePurge_T>
class GeneticAlgorithm : public Algorithm 
{

private:
	TheInitPopulation_T _init_population;
	TheMutation_T _mutation;
	TheFitness_T _fitness;
	TheCrossover_T _crossover;
	ThePurge_T _purge;

public:

	void run(Star* star)
	{
		

		// seed random number generation
		srand(std::time(nullptr));

		// the size of the initial genotype
		int GENOTYPE_SIZE = 10;
		GENOTYPE_SIZE = Config::getInstance()->pull("GENOTYPE_SIZE", GENOTYPE_SIZE);

		// number of times to mutate each generation
		int STEP_SIZE = 1;
		STEP_SIZE = Config::getInstance()->pull("STEP_SIZE", STEP_SIZE);

		// solution output file
		std::string GA_SOLUTION_FILE = "solutions.txt";
		GA_SOLUTION_FILE = Config::getInstance()->pull("GA_SOLUTION_FILE", GA_SOLUTION_FILE);

		// how many generations should we wait to purge?
		int PURGE_DELAY = 10;
		PURGE_DELAY = Config::getInstance()->pull("PURGE_DELAY", PURGE_DELAY);

		// metric output file
		std::string METRIC_OUTPUT = "metrics.txt";
		METRIC_OUTPUT = Config::getInstance()->pull("METRIC_OUTPUT", METRIC_OUTPUT);

		//rate to sample to metric output
		int SAMPLE_RATE = 1;
		SAMPLE_RATE = Config::getInstance()->pull("SAMPLE_RATE", SAMPLE_RATE);

		// rate we display genotype
		int DISPLAY_GENOTYPE_DELAY = 1;
		DISPLAY_GENOTYPE_DELAY = Config::getInstance()->pull("DISPLAY_GENOTYPE_DELAY", DISPLAY_GENOTYPE_DELAY);


		// fill the initial population
		Genotype geno = _init_population.fillGenotype(star, GENOTYPE_SIZE);

		std::cout << geno.toString() << std::endl;
		
		// generation count
		int generation = 1;

		// solution file to write to
		std::ofstream myfile;
		
		// clear metric file
		std::ofstream outfile;
		outfile.open(METRIC_OUTPUT);
		outfile.close();

		//  -> mutate -> set fitness -> crossover ->
		while (true)
		{
			
			// set the fitness of the population
			_fitness.setFitness(geno);


			// clear metric file


			// write metrics
			if(generation%SAMPLE_RATE == 0)
				geno.writeMetrics(
					geno.getFitnesses(),
					geno.getPercentCovereds(),
					geno.getNumberSelecteds(),
					geno.getChromaticNumbers(),
					generation,
					METRIC_OUTPUT
			);

			// periodically print the genotype and the current generation
			if (generation % DISPLAY_GENOTYPE_DELAY == 0)
			{
				std::cout << "Generation:\t" << generation << std::endl;

				std::cout << geno.toString() << std::endl;
			}

			// perform STEP_SIZE mutations
			for (int i = 0; i < STEP_SIZE; i++)
			{
				// mutate each chromosome in the genotype
				_mutation.mutateGenotype(geno);

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
						myfile.open(GA_SOLUTION_FILE, std::ios::app);
						myfile << chromo.getCover()._bitVector.length() << "\t|\t" << chromo.getCover()._bitVector.numberSelected() << "\t|\t" << chromo.getCover().toString() << "\n";
						myfile.close();
						std::cout << "-----------------------------------------\n";
					}
				}
			}

			// set the fitness of the population
			_fitness.setFitness(geno);

			// perform the crossover on the population
			_crossover.performCrossover(geno, star);

			// if we have reached x generations, purge

			if (generation % PURGE_DELAY == 0) _purge.purgeGenotype(geno, star);

			// increment generation
			generation++;

		}

	}

};




#endif
