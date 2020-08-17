/*
*  file:	RandomInitGenotype.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/


#include"RandomInitGenotype.h"
#include"../../../Genotype/Genotype.h"
#include"../../../../../Star/Star.h"
#include<cstdlib>
#include<ctime>

// return a randomly generated chromosome
Chromosome RandomInitGenotype::getRandomChromosome(Star* star)
{ 

	// cover to randomly select vertices
	Cover temp_cover(star);

	// chromosome with the random cover
	Chromosome chromo(getRandomCover(star));
	
	// return the randomly generated chromosome
	return chromo;

}

//generate a random cover
Cover RandomInitGenotype::getRandomCover(Star* star)
{
	// create a cover to return
	Cover temp_cover(star);

	// generate i random numbers between 0 and the length of the bitvector
	int number_of_vertices_to_flip = rand() % temp_cover._bitVector.length();


	int rand_index;
	// select i random bits to flip
	for (int i = 0; i < number_of_vertices_to_flip;i++) 
	{

		// which bit to flip?
		int rand_index = rand() % temp_cover._bitVector.length();

		// select that bit in our cover
		temp_cover.select(rand_index);
	}
	return temp_cover;
}

// fill the genotype with randomly generated chromsomes
Genotype RandomInitGenotype::fillGenotype(Star* star, int size) 
{

	// seed random numbers with time
	srand(std::time(nullptr));

	// the genotype we will be filling
	Genotype genotype;

	// the chromosome we will be filling the genotype with
	Chromosome chromo;

	// randomly generate chromosomes and add them to the genotype
	for (int i = 0; i < size; i++) 
	{
		// get a random chromosome
		chromo = getRandomChromosome(star);

		// add it to the genotype
		genotype.appendChromosome(chromo);
	}

	// return the filled genotype
	return genotype;
}

