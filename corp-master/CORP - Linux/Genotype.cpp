/**
*  file:	Genotype.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Genotype is a container for chromosomes.
*/

#include"Genotype.h"
#include<sstream>
#include<fstream>
#include"ColoringFitness.h"

// return the genotype as a vector of chromosomes
std::vector<Chromosome>& Genotype::getChromosomes() { return _chromosomes; }

// add a chromosome to the genotype
bool Genotype::appendChromosome(Chromosome& chromosome)
{
	_chromosomes.push_back(chromosome);
	return true;
}

// remove a chromsome for the genotype
bool Genotype::removeChromosome(int index)
{
	_chromosomes.erase(_chromosomes.begin()+index);
	return true;
}

// string representation of a genotype
std::string Genotype::toString()
{
	std::string result = "";

	for (Chromosome chrom : getChromosomes())
	{

		result += (chrom.getCover().toString() + "\t|\t" + std::to_string(chrom.getFitness()) + "\t|\t" + std::to_string(chrom.getCover()._bitVector.numberSelected())+ "\n");
	}

	return result;
}

// return the most fit chromosome of the genotype
Chromosome Genotype::getMostFit()
{
	Chromosome max = _chromosomes.at(0);

	for (Chromosome& chromo : _chromosomes) {
		if (chromo.getFitness() >= max.getFitness())
			max = chromo;
	}

	return max;

}
