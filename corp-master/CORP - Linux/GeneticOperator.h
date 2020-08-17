/**
*  file:	GeneticOperator.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  This is a pure virtual class that every genetic operator's interface
*  will extend
*
*/

#ifndef _GENETIC_OPERATOR_
#define _GENETIC_OPERATOR_

#include"Genotype.h"

class GeneticOperator 
{
public:
	// each genetic operator will do something to the genotype
	virtual bool start(Genotype& genotype) = 0;

};

#endif
