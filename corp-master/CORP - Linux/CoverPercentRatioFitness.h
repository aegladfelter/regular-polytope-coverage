/*
*  file:	CoverPercentRatio.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/

#ifndef _COVER_PERCENT_RATIO_FITNESS_
#define _COVER_PERCENT_RATIO_FITNESS_


#include"Fitness.h"
#include"GeneticOperator.h"

class CoverPercentRatioFitness : Fitness {

public:
	
	// return the percent 
	bool setFitness(Genotype&);

};

#endif