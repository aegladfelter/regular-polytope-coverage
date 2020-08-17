/*
*  file:	CoverPercentRatio.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/

#ifndef _ONE_POINT_CROSSOVER_
#define _ONE_POINT_CROSSOVER_

#include"Crossover.h"

class OnePointCrossover : Crossover {

private:
	// return 2 least fit chromosomes
	std::vector<int> getLeastFit(Genotype&);

	// return vector of 2 most fit chromosomes
	std::vector<Chromosome> getMostFit(Genotype&);


public:

	// swap tail ends of most fit chromosomes
	// replace least fit chromosomes with result
	bool performCrossover(Genotype&, Star*);

};

#endif