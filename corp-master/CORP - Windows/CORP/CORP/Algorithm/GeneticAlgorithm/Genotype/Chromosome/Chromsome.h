/**
*  file:	Chromosome.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Chromosome wrapper for cover that includes a fitness attribute.
*/

#ifndef _CHROMOSOME_GUARD_
#define  _CHROMOSOME_GUARD_

#include"../../../../Cover/Cover.h"

class Chromosome {

private:
	// store the cover for the chromosome
	Cover _cover;
  
	// store the fitness of the chromosome
	double _fitness = 0;

public:

	// default constructor
	Chromosome();

	// construct a chomosome from a given cover
	Chromosome(const Cover& cover);

	//  copy constructor
	Chromosome(const Chromosome& original);

	// overloaded =
	Chromosome& Chromosome::operator=(const Chromosome& original);

	// return the cover
	Cover& getCover();

	void setCover(Cover&);

	// return the fitness of the chromosome
	double getFitness() const;

	// set the fitness of a chromosome
	void setFitness(double fitness);

	


};

#endif
