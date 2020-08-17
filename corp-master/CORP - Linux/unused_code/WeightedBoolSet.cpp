

/**
*  file:	WeightedBoolSet.cpp
*  author:	Sarah McGlasson
*  date:	9/17/2017
*  updated:	9/24/2017
*
*  This is a weighted version of the BoolSet class
*
*/

/*
#include "WeightedBoolSet.h"
# include <string>

//constructor
WeightedBoolSet::WeightedBoolSet(int size) 
{
	_length = size;
	_numberSelected = 0;
	_values = new bool[_length];
	_weights = new int[_length];
}

//copy constructor
WeightedBoolSet::WeightedBoolSet(const WeightedBoolSet & original) 
{
	_length = original.length();
	_numberSelected = original._numberSelected;
	std::memcpy(_values, original._values, sizeof _values);
	std::memcpy(_weights, original._weights, sizeof _weights);
}

//destructor
WeightedBoolSet::~WeightedBoolSet() 
{
	delete[]_values;
	_values = nullptr;
	delete[]_weights;
	_weights = nullptr;
}

//overloaded brackets
bool & WeightedBoolSet::operator[](int index) 
{
	return _values[index];
}

//overloaded brackets
bool WeightedBoolSet::operator[](int index) const
{
	return _values[index];
}

//sets weight for value at given index
void WeightedBoolSet::setWeight(int index, int weight) 
{
	if (index >= _length || index < 0)
		return;
	_weights[index] = weight;
}

//sets weight for value without checking bounds
void WeightedBoolSet::setWeightUnchecked(int index, int weight)
{
	_weights[index] = weight;
}

//returns the index of the highest weighted value
int WeightedBoolSet::getHighest() const 
{
	int indexOfHighest = 0;
	int currentHighest = 0;
	for (int i = 0; i < _length; i++)
	{
		if (_weights[i] > currentHighest)
		{
			currentHighest = _weights[i];
			indexOfHighest = i;
		}
	}
	return indexOfHighest;
}

//resets weights to 0
void WeightedBoolSet::resetWeights() 
{
	std::memset(_weights, 0, sizeof _weights);
}

//returns the weight of the value at the given index
int WeightedBoolSet::getWeight(int index) const
{
	if (index >= _length || index < 0)
	{
		//TODO: throw exception
	}
	return _weights[index];
}

//returns the weight of the value without checking bounds
int WeightedBoolSet::getWeightUnchecked(int index) const
{
	return _weights[index];
}

//sets every value to false and clears all weights
void WeightedBoolSet::clear()
{
	_numberSelected = 0;
	std::memset(_values, false, sizeof _values);
	std::memset(_weights, 0, sizeof _weights);
}
*/