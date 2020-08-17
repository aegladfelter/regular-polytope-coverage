#ifndef _INPUT_PARSER_GUARD
#define _INPUT_PARSER_GUARD


#include "OptionContainer.h"
#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

class InputParser
{
	protected:
		std::ifstream& _is;

	public:
		InputParser(std::ifstream& in);
        Matrix<int>* parse();

	private:
};
#endif