#include"Purge.h"
class RandomHalfPurge : public Purge {

public:
	bool purgeGenotype(Genotype& geno, Star* star);


private:

	bool appendChromosomes(Genotype & geno, Star* star, int size);
	bool removeRandomChromosomes(Genotype& geno);

};