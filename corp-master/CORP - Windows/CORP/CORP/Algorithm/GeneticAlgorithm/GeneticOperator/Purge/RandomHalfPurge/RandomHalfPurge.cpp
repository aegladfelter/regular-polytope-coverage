#include"RandomHalfPurge.h"
#include"../../InitGenotype/RandomInitGenotype/RandomInitGenotype.h"
#include<ctime>
#include<cstdlib>

bool RandomHalfPurge::purgeGenotype(Genotype& geno, Star* star) {

	// seed random numbers with time
	srand(std::time(nullptr));

	removeRandomChromosomes(geno);

	// randomly fill with chromosomes the same number that were purged
	appendChromosomes(geno, star, geno.getChromosomes().size() / 2);

	return true;
}

bool RandomHalfPurge::removeRandomChromosomes(Genotype& geno)
{

	// loop from 0 to number to get
	for (int i = 0; i < geno.getChromosomes().size()/2; i++)

		// push random indice between 0 and max
		geno.removeChromosome(rand() % geno.getChromosomes().size());

	return true;

}

bool RandomHalfPurge::appendChromosomes(Genotype& geno, Star* star, int size)
{
	RandomInitGenotype ig;

	for (int i = 0; i < size; i++)
	{
		geno.appendChromosome(ig.getRandomChromosome(star));
	}

	return true;
}