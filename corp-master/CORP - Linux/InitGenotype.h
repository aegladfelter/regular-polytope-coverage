/**
*  file:	InitGenotype.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  This is a pure virtual class that all classes to to initialize
*  the genotype must extend. Every class that will initialize the genotype
*  will have a fillGentype() method that takes a reference to a genotype
*  and fills it with chromosomes that the class will generate.
*
*/

#ifndef _INITIALIZE_POPULATION_GAURD_
#define _INITIALIZE_POPULATION_GAURD_

#include"GeneticOperator.h"


class InitGenotype
{

public:
	// fill the genotype with chromosomes
	virtual Genotype fillGenotype(Star* star, int size) = 0;


};

#endif
