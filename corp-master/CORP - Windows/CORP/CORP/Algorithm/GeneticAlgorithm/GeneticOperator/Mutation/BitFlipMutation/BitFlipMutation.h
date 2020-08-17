/**
*  file:	BitFlipMutation.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* Choose a random bit in each chromosome of a genotype
* and flip it
*
*
*/

#ifndef _BIT_FLIP_MUTATION_ 
#define _BIT_FLIP_MUTATION_

#include "../Mutation.h"

class BitFlipMutation : Mutation {


public:
	bool mutateGenotype(Genotype&);


private:
	bool mutateOne(Genotype&);

	bool mutateAll(Genotype&);

};
#endif