/**
*  file:	Chromosome.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Chromosome wrapper for cover that includes a fitness attribute.
*/

#include "Chromsome.h"


// copy constructor
Chromosome::Chromosome(const Cover& cover) : _cover{ cover } {}

// default constructor
Chromosome::Chromosome() {}

// return pointer to the cover
Cover& Chromosome::getCover() { return _cover; }

// set the cover of the chromsome
void Chromosome::setCover(Cover& cover) { _cover = cover; }

// set the fitness of the chromosome
void Chromosome::setFitness(double fitness) { _fitness = fitness; }

// return the fitness of the chromosome
double Chromosome::getFitness() const { return _fitness; }

// overloaded =
Chromosome & Chromosome::operator=(const Chromosome& original) 
{
	_cover = original._cover;
	_fitness = original._fitness;
	return *this;
}

// copy constructor
Chromosome::Chromosome(const Chromosome& original) 
{
	_cover = original._cover;
	_fitness = original._fitness;
}
