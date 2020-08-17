/*
*  file:	BitFlipMutation.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number of vertices selected
*
*/

#include "BitFlipMutation.h"
#include <ctime>

// flip a random bit in the bitvector of each chromosome
bool BitFlipMutation::mutateAll(Genotype& genotype) 
{
	Cover cover;
	int rand_index;
	for (Chromosome& chromo : genotype.getChromosomes())
	{

		cover = chromo.getCover();



			rand_index = rand() % cover._bitVector.length();

			if (!cover._bitVector.getValue(rand_index))
				cover.select(rand_index);


			else {
				//if(rand()%3 == 0) 
				cover.deselect(rand_index);
			}

			chromo.setCover(cover);
		
		/*else
		{
			rand_index = rand() % cover._bitVector.length();
			while(cover._bitVector.getValue(rand_index))
				rand_index = rand() % cover._bitVector.length();

			cover.deselect(rand_index);
		}*/
		
	}

	return true;
}

// seed random number generation and mutate chromosomes
bool BitFlipMutation::mutateGenotype(Genotype& genotype) 
{
	
	return mutateAll(genotype);
}