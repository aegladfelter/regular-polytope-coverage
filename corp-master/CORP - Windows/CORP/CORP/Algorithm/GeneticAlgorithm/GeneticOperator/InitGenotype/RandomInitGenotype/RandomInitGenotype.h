/**
*  file:	RandomInitGenotype.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  RandomInitGenotype is an InitGenotype that randomly
*  generates chromosomes to fill the genotype with.
*
*
*/

#ifndef _RANDOM_INIT_GENOTYPE_GAURD_
#define _RANDOM_INIT_GENOTYPE_GAURD_ 1


#include"../InitGenotype.h"
#include"../../../Genotype/Genotype.h"
#include"../../../Genotype/Chromosome/Chromsome.h"

class RandomInitGenotype : public InitGenotype
{
private:
	// return a randomly generated cover
	Cover getRandomCover(Star* star);

public:
	// return a genotype that has been filled
	// with random chromosomes
	// the initial genotype will have size chromosomes
	Genotype fillGenotype(Star* star, int size);

	// return a randomly generated chromosome
	Chromosome getRandomChromosome(Star* star);

};

#endif