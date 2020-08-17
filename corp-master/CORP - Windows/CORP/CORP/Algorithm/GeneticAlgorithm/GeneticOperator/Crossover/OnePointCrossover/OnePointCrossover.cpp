/*
*  file:	OnePointCrossover.cpp
*  author:	Steven Gallagher
*  date:	10/1/2017
*  updated:	10/12/2017
*
*  This class is used to take a genotype and crossover the tail heads
*  of the two most fit chromosomes and replace the two least fit chromosomes
*  with the result
*
*/

#include"OnePointCrossover.h"
#include <ctime>

// find the two most fit chromosomes in the genotype
// select swap the tail ends heads
// replace the two least fit chromosomes in the genotype
// with the result of 
bool OnePointCrossover::performCrossover(Genotype& genotype, Star* star)
{


	// find the two most fit chromosomes
	std::vector<Chromosome> most_fit = getMostFit(genotype);

	// store them each
	Chromosome most_fit1 = most_fit.at(0);
	Chromosome most_fit2 = most_fit.at(1);
	
	// need covers for child chromosomes
	Cover temp_cover1(star);
	Cover temp_cover2(star);

	// children of most fit chromosomes
	Chromosome child1(temp_cover1);
	Chromosome child2(temp_cover2);

	// prepare child chromosomes for tails to be swapped
	child1 = most_fit.at(0);
	child2 = most_fit.at(1);

	int rand_index = rand() % child1.getCover()._bitVector.length();
	// get first half of parent2 for child1
	for (int i = 0; i < rand_index; i++)
	{
		if (most_fit2.getCover()._bitVector[i]) child1.getCover().select(i);
		else child1.getCover().deselect(i);
	}



	// get the first half of parent1 for child2
	for (int i = 0; i < rand_index; i++)
	{
		if (most_fit1.getCover()._bitVector[i]) child2.getCover().select(i);
		else child2.getCover().deselect(i);
	}

	//
	// select survivors
	//

	// get the two least fit chromosomes
	std::vector<int> least_fit = getLeastFit(genotype);

	//  give children fitness of 0, it will be calculated in the next iteration
	child1.setFitness(0);
	child2.setFitness(0);


	// remove the least fit chromosomes
	genotype.removeChromosome(least_fit.at(0));

	// -1 because this chromosome will always fall after the first removed
	genotype.removeChromosome(least_fit.at(1)-1);

	// append the child chromosomes to the genotype
	genotype.appendChromosome(child1);
	genotype.appendChromosome(child2);
	
	// haven't thought of how this might fail yet
	return true;
}

// return two chromsomes with the highest fitness
std::vector<Chromosome> OnePointCrossover::getMostFit(Genotype& genotype) 
{

	// start with top of genotype for future comparisons
	Chromosome max1 = genotype.getChromosomes().at(0);
	Chromosome max2 = genotype.getChromosomes().at(0);

	max2.setFitness(0);
	max1.setFitness(0);


	// linearly search for the most fit chromosome
	for (Chromosome& chromo : genotype.getChromosomes()) 
		if (chromo.getFitness() > max1.getFitness()) max1 = chromo;

	// linearly search for second most fit chromsoem
	for (Chromosome& chromo : genotype.getChromosomes()) 
		if (chromo.getFitness() > max2.getFitness() && chromo.getFitness() != max1.getFitness())
			max2 = chromo;

	// return the two most fit chromosomes
	std::vector<Chromosome> result = { max1, max2 };

	return result;
}


// return two chromosomes of the least fitness
std::vector<int> OnePointCrossover::getLeastFit(Genotype& genotype) 
{
	// min chromsomes are indices to make removing them easier
	int min1 = 0;
	int min2 = 0;

	// the index that will be stored into min1,min2
	int index = 0;

	// find first least fit
	for (Chromosome& chromo : genotype.getChromosomes()) 
	{

		if (chromo.getFitness() < genotype.getChromosomes().at(min1).getFitness()) 
			min1 = index;

		index++;
	}

	// reset index to -1 to account for the first min being removed
	index = 0;

	//find second least fit chromosome
	for (Chromosome& chromo : genotype.getChromosomes()) 
	{
		if (chromo.getFitness() <= genotype.getChromosomes().at(min2).getFitness() && min1 != min2);
			min2 = index;
		index++;
	}

	// store least fit chromosomes
	std::vector<int> result = { min1, min2 };

	// return least fit chromosomes
	return result;
}





