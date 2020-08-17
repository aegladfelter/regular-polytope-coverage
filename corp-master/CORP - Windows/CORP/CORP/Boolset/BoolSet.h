/**
*  file:	BoolSet.h
*  author:	Sarah McGlasson
*  date:	9/10/2017
*  updated:	2/11/2018
*
*  The header file for the Boolset class
*
*/

#ifndef _BOOLSET_GUARD_
#define _BOOLSET_GUARD_
#include<string>
#include<memory>

#include<vector>

class BoolSet
{
protected:
	static const int _MAX = 600;  //max number of vertices allowed
	int _length;									//how many booleans are used in the set
	int _numberSelected;          //how many booleans are currently true
	std::vector<bool> _values;                //the booleans stored

public:
	BoolSet(int size = _MAX);                       //constructor
	BoolSet(const BoolSet& original);               //copy constructor
	BoolSet& operator=(const BoolSet& original);    //overloaded equals
	virtual ~BoolSet();                             //destructor
	bool operator[](int index);                    //overloaded brackets
	bool operator[](int index) const;               //overloaded brackets

	int length() const;                             //returns the length of the list
	int numberSelected() const;                     //returns the number of values set to true
	void setTrue(int index);                        //sets the value at the given index to true
	void setTrueUnchecked(int index);               //sets the value without checking bounds
	void setValue(int index, bool value);	          //sets the value at the given index to the given value
	void setValueUnchecked(int index, bool value);	//sets the value without checking bounds
	void toggleValue(int index);                    //toggles the value a the given index between true and false
	void toggleValueUnchecked(int index);           //toggles the value without checking bounds
	bool getValue(int index) const;                 //gets the value at the given index
	bool getValueUnchecked(int index) const;        //gets the value without checking bounds
	bool allTrue() const;                           //returns true if every value in the array is true
	void clear();                                   //sets every entry to false
	bool empty() const;                             //returns true if all values are false
	std::string toString() const;
};

#endif
