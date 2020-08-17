#include "../Fitness.h"

class ColoringFitness : public Fitness {

public:
	bool setFitness(Genotype &);

	int getChromaticNumber(Chromosome&);

	

};