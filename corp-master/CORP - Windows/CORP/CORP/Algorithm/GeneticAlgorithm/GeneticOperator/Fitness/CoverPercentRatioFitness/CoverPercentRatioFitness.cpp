/*
*  file:	CoverPercentRatio.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/
#include<math.h>
#include "CoverPercentRatioFitness.h"

// set the fitness of each chromosome in the genotype with their cover percent
// divided by the solution size
bool CoverPercentRatioFitness::setFitness(Genotype& genotype)
{
	float n, p, w;
	for (Chromosome& chromo : genotype.getChromosomes()) 
	{
		p = chromo.getCover().coverPercent();
		n = ((float)chromo.getCover()._bitVector.numberSelected()/ chromo.getCover()._bitVector.length());

		chromo.setFitness(1-p);
	}

	return true;
}

