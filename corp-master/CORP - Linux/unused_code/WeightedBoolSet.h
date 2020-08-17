/**
*  file:	BoolSet.h
*  author:	Sarah McGlasson
*  date:	9/17/2017
*  updated:	10/12/2017
*
*  The header file for the WeightedBoolSet class
*
*/

#ifndef _WEIGHTEDBOOLSET_GUARD_
#define _WEIGHTEDBOOLSET_GUARD_

#include "BoolSet.h"

class WeightedBoolSet : public BoolSet
{
protected:					

	int* _weights = nullptr;							//weights for the values stored

public:
	WeightedBoolSet(int size = _MAX);					//constructor
	WeightedBoolSet(const WeightedBoolSet& original);	//copy constructor
	~WeightedBoolSet();									//destructor

	bool& operator[](int index);						//overloaded brackets
	bool operator[](int index) const;
	void setWeight(int index, int weight);				//set the weight for the given index
	void setWeightUnchecked(int index, int weight);		//set the weight without checking bounds
	int getHighest() const;								//returns the index of the highest weighted value, if there are multiple, returns the first it finds
	void resetWeights();								//sets all weights to 0
	int getWeight(int index) const;						//returns the weight of the value at the given index
	int getWeightUnchecked(int index) const;			//returns the weight without checking bounds
	void clear();										//sets every entry to false

};	

#endif

