/*
*  file:	Fitness.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* Determine the "goodness" of solution
*
*/

#ifndef _FITNESS_GUARD_
#define _FITNESS_GUARD_

#include"Genotype.h"

class Fitness {

public:

	// set the fitness of each chromosome in 
	virtual bool setFitness(Genotype&) = 0;

};

#endif
