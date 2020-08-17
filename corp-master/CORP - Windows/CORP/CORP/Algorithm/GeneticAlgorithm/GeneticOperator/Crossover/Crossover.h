/*
*  file:	Corssover.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* Replace chromosomes in genotype with generated offspring
*
*/

#ifndef _CROSSOVER_GUARD_
#define _CROSSOVER_GUARD_

#include"../GeneticOperator.h"

class Crossover {

private:

	// perform a crossover and produce offspring
	virtual bool performCrossover(Genotype&, Star* star) = 0;
	
};

#endif