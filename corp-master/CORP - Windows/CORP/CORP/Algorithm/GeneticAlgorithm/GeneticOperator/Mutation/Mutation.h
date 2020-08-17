/*
*  file:	Mutation.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* Modify each chromosome in a genotype
*
*/

#ifndef _MUTATION_GUARD_
#define _MUTATION_GUARD_

#include "../GeneticOperator.h"
class Mutation {


private:
	virtual bool mutateGenotype(Genotype&) = 0;

};

#endif
