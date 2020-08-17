/**
*  file:	KindOfRandomInitGenotype.h
*  author:	Steven Gallagher
*  date:	3/27/2018
*  updated:	3/27/2018
*
*  Fills genotype from file and then the rest randomly
*
*/

#include"../RandomInitGenotype.h"
class KindOfRandomInitGenotype : RandomInitGenotype {

public:
	
	// returns genotype filled with solutions from text file
	// fills the rest with random chromosomes
	Genotype fillGenotype(Star* star, int size);

private:
	// declare initial genotype as empty with no chromosomes
	Genotype _genotype;

	// loop through file and make chromosomes to append to genotype
	bool fillGenotypeFromFile(std::string file_path, Star* star);

	// fill as many random chromosomes as needed till we are at size
	void fillRest(int size, Star* star);
};