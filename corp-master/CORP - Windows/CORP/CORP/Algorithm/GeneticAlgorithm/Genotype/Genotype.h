/**
*  file:	Genotype.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Genotype is a container for chromosomes.
*/

#ifndef _GENOTYPE_GUARD_
#define  _GENOTYPE_GUARD_


#include"../../../Cover/Cover.h"
#include"Chromosome\Chromsome.h"


class Genotype {

private:
	// contains the chromosomes of the genotype
	std::vector<Chromosome> _chromosomes;

	bool writeString(std::string outfile_path, std::string towrite);




public:
	// return the genotype as a vector of chromosomes
	std::vector<Chromosome>& getChromosomes();

	// add a new chromosome to the genotype
	bool appendChromosome(Chromosome &chromosome);

	bool removeChromosome(int index);

	// string representation of genotype
	std::string toString();

	Chromosome getMostFit();

	std::vector<double> getFitnesses();

	std::vector<double> getNumberSelecteds();

	std::vector<double> getPercentCovereds();

	std::vector<double> getChromaticNumbers();

	bool writeMetrics(std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, int, std::string);

	bool writeVectorAsList(std::vector<double> vector, std::string outfile_path);


};

#endif
