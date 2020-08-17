

#include "InputParser.h"
#include<sstream>

InputParser::InputParser(std::ifstream& in) : _is{ in }
{}

// Stores all values from input file into the Matrix object
Matrix<int>* InputParser::parse()
{
    //
    // The first value we expect to read is the number of facets in the file
    //
    unsigned rows, columns;
    _is >> rows >> columns;

    // Allocate the matrix
    Matrix<int>* matrix = new Matrix<int>{ rows, columns };

    // Read in the the contents of the array
    unsigned tempVal;
    for (unsigned r = 0; r < rows; r++)
    {
        for (unsigned c = 0; c < columns; c++)
        {
            _is >> tempVal;
            matrix->set(r, c, tempVal);
            std::cout << matrix->get(r, c) << " ";
        }
        std::cout << std::endl;
    }

    _is.close();
    return matrix;
}