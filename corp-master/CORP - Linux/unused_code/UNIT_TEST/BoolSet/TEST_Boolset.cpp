/**
*  file:	TEST_BoolSet.cpp
*  author:	Sarah McGlasson
*  date:	9/24/2017
*  updated:	9/24/2017
*
*  Unit test file for the Boolset and Weighted Boolset classes
*
*/

#include <iostream>
#include "../../CORP/Boolset/BoolSet.h"
#include "../../CORP/Boolset/WeightedBoolSet.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BOOLSETTEST
{
	TEST_CLASS(TEST_Boolset)
	{
	public:
		TEST_METHOD(length)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(60, set.length());
		}

		TEST_METHOD(numberSelectedEmpty)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(0, set.numberSelected());
		}
		TEST_METHOD(bracketsGet)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(false, set[0]);
		}
		TEST_METHOD(bracketsSet)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set[1] = true;
			Assert::AreEqual(true, set[1]);
		}

		TEST_METHOD(getValueFalse)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(false, set.getValue(0));
		}

		TEST_METHOD(getValueTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set[0] = true;
			Assert::AreEqual(false, set.getValue(0));
		}

		TEST_METHOD(getValueFalseUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(false, set.getValueUnchecked(0));
		}

		TEST_METHOD(getValueTrueUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set[0] = true;
			Assert::AreEqual(false, set.getValueUnchecked(0));
		}

		TEST_METHOD(setTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(4);
			Assert::AreEqual(true, set[4]);
		}

		TEST_METHOD(numberSelected)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(0);
			set.setTrue(1);
			set.setTrue(2);
			set.setTrue(2);
			Assert::AreEqual(3, set.numberSelected());
		}

		TEST_METHOD(numberSelectedempty)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(0, set.numberSelected());
		}

		TEST_METHOD(setTrueInvalid)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(100);
			Assert::AreEqual(0, set.numberSelected());
		}

		TEST_METHOD(setTrueUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrueUnchecked(4);
			Assert::AreEqual(true, set[4]);
		}

		TEST_METHOD(toggleValueTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.toggleValue(1);
			Assert::AreEqual(true, set[1]);
			Assert::AreEqual(1, set.numberSelected());
		}

		TEST_METHOD(toggleValueFalse)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.toggleValue(1);
			set.toggleValue(1);
			set.toggleValue(1);
			set.toggleValue(1);
			Assert::AreEqual(true, set[1]);
			Assert::AreEqual(0, set.numberSelected());
		}

		TEST_METHOD(toggleValueTrueUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.toggleValueUnchecked(1);
			Assert::AreEqual(true, set[1]);
			Assert::AreEqual(1, set.numberSelected());
		}

		TEST_METHOD(toggleValueFalseUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.toggleValueUnchecked(1);
			set.toggleValueUnchecked(1);
			set.toggleValueUnchecked(1);
			set.toggleValueUnchecked(1);
			Assert::AreEqual(true, set[1]);
			Assert::AreEqual(0, set.numberSelected());
		}

		TEST_METHOD(setValueTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setValue(4, true);
			Assert::AreEqual(true, set[4]);
		}

		TEST_METHOD(setValueFalse)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(4);
			set.setValue(4, false);
			Assert::AreEqual(false, set[4]);
		}

		TEST_METHOD(setValueInvalid)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setValue(100, true);
			Assert::AreEqual(0, set.numberSelected());
		}

		TEST_METHOD(setValueTrueUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setValueUnchecked(4, true);
			Assert::AreEqual(true, set[4]);
		}

		TEST_METHOD(setValueFalseUnchecked)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(4);
			set.setValueUnchecked(4, false);
			Assert::AreEqual(false, set[4]);
		}

		TEST_METHOD(allTrueFalse)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(false, set.allTrue());
		}

		TEST_METHOD(allTrueTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			for (int i = 0; i < set.length(); i++)
			{
				set[i] = true;
			}
			Assert::AreEqual(true, set.allTrue());
		}

		TEST_METHOD(emptyFalse)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(1);
			set.setTrue(7);
			set.setTrue(9);
			Assert::AreEqual(false, set.empty());
		}

		TEST_METHOD(emptyTrue)
		{
			BoolSet set = BoolSet::BoolSet(60);
			Assert::AreEqual(true, set.empty());
		}

		TEST_METHOD(clear)
		{
			BoolSet set = BoolSet::BoolSet(60);
			set.setTrue(1);
			set.setTrue(7);
			set.setTrue(9);
			set.clear();
			Assert::AreEqual(true, set.empty());
		}

		


		
	};
}

//Boolset Functions:
//int length() const;									//returns the length of the list
//int numberSelected() const;							//returns the number of values set to true
//void setTrue(int index);								//sets the value at the given index to true
//void setTrueUnchecked(int index);						//sets the value without checking bounds
//void setValue(int index, bool value);					//sets the value at the given index to the given value
//void setValueUnchecked(int index, bool value);		//sets the value without checking bounds
//void toggleValue(int index);							//toggles the value a the given index between true and false
//void toggleValueUnchecked(int index);					//toggles the value without checking bounds
//bool getValue(int index) const;						//gets the value at the given index
//bool getValueUnchecked(int index) const;				//gets the value without checking bounds
//bool allTrue() const;									//returns true if every value in the array is true
//void clear();											//sets every entry to false
//bool empty() const;									//returns true if all values are false


