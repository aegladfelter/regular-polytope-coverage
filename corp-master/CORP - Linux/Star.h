#ifndef _STAR_GUARD_
#define  _STAR_GUARD_
#include "Matrix.hpp"
#include <iostream>
#include<vector>
class Star
{
protected:

	//int _numberOfFacets;
	//int _numberOfVertices;
	int _lowerBound;
	int _upperBound;
    int _facetsPerVertex;

	int _starRows;
	int _starCols;
	int _vertex;

public:
		
	Matrix<int> _matrix;
	Matrix<int> _vertexMatrix;
		
	std::vector<int> getAdjacent(int vertex);

	//Constructor
	Star(const Matrix<int>& matrix);
private:
	//Star();
	//Copy Constructor
	Star(const Star& original);

public:
	//Destructor
	virtual ~Star();

	//Returns the number of rows
	int rows() const; 

	//Returns the number of columns
	int cols() const;


	//Valculates the theoretical minimum vertices
	int lowerBound() const;

	//Calculates the theoretical maximum vertices
	int upperBound() const;

	//return the matrix obj
	//Matrix<int> & getMatrix();

    //returns the number of facets
	int numberOfFacets() const;

    //returns the number of vertices
	int numberOfVertices() const;

    //returns the number of facets converging at each vertex
	int facetsPerVertex() const;
    
    //uses nested for loops to create the secondary matrix **POTENTIALLY INEFICIENT**
   // void ineficientMatrixConvert();
    
    //new function to create the secondary matrix
    void matrixConvert();
    
    //caulculates and sets the bounds
    void calculateBounds();

};


#endif