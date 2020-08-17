#ifndef _TEST_MATRIX_HPP
#define _TEST_MATRIX_HPP
#include <iostream>
#include <string>
#include "../../CORP/Matrix/Matrix.hpp"
#include "CppUnitTest.h"
//Unit tets for Matrix.hpp

//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//{

	template <typename T>
	class MatrixTester
	{
	protected:
		Matrix<T>* _m

	public:

		TEST_CLASS(IntMatrixTester)
		{
			_m = new Matrix<int>*;

			runAll();

			delete _m;
		}

		TEST_CLASS(DoubleMatrixTester)
		{
			_m = new Matrix<double>*;

			runAll();

			delete _m;
		}

		TEST_CLASS(BoolMatrixTester)
		{
			_m = new Matrix<bool>*;

			runAll();

			delete _m;
		}

		TEST_CLASS(UnsignedMatrixTester)
		{
			_m = new Matrix<unsigned>*;

			runAll();

			delete _m;
		}

		TEST_CLASS(FloatMatrixTester)
		{
			_m = new Matrix<float>*;

			runAll();

			delete _m;
		}






		TEST_METHOD(testConstructor)
		{
			_os << "\t" << "Test constructor..." << std::endl;

			int errors = 0;

			if (_m->size() != 0)
			{
				emitError("Constructor error; size is not zero");
				errors++;
			}
			if (_m->empty())
			{
				emitError("Constructor error; array is empty");
				errors++
			}

			else { return 0; }

			check(_m, errors);

		}

		TEST_METHOD(testGet)
		{
			_m->get();
		}

		TEST_METHOD(testSet)
		{
			_m->set();
		}

		TEST_METHOD(testRemove)
		{
			_m->remove();
		}

		TEST_METHOD(testToString)
		{
			m->toString();
		}

		virtual ~MatrixTester()
		{
			_m->clear();
		}

		virtual runAll()
		{
			//Run Tests and reports
			_m->clear();

			testConstructor();
			testGet();
			testSet();
			testRemove();
			testToString();

			//_errorCountMap["constructor"] = testConstructor();
			//_m->clear();

			//_errorCountMap["set"] = testSet();
			//_m->clear();

			//_errorCountMap["get"] = testGet();
			//_m->clear();

			//_errorCountMap["remove"] = testRemove();
			//_m->clear();

			//_errorCountMap["toString"] = testToString();
			//_m->clear();
		}

		/*
			MatrixTester(Matrix<T>* aMatrix, const std::string& name = "Adjacency Matrix", std::ostream& out = std::cout) : AbstractTester{ name, out }, _m{ aMatrix }
			{

			}



			TEST_METHOD(testConstructor)
			{
				_os << "\t" << "Test constructor..." << std::endl;

				int errors = 0;

				if (_m->size() != 0)
				{
					emitError("Constructor error; size is not zero");
					errors++;
				}
				if (_m->empty())
				{
					emitError("Constructor error; array is empty");
					errors++
				}
				check(_m, errors);

				_m->remove(Utilities::generate());

				if (_m->contains(Utilities::generate()))
			}
		*/
	};
//}

#endif // _TEST_MATRIX_HPP
