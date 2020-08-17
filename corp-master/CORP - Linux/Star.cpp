
/*
  Austin Gladfelter
  Star class uses a matrix structure

*/



#include "Star.h"
#include<vector>
#include<algorithm>

//Star::Star() {}
//Constructor

Star::Star(const Matrix<int>& matrix) :
    _matrix{ matrix }
{
	//calculate bounds
    calculateBounds();

    // matrixConvert();
    // CTA: Needs to be a pointer to a matrix.
}

//Copy Constructor
Star::Star(const Star& original)
{}
// CTA: Disallow copying of Star...only one needed
//	_upperBound = original.upperBound();
//	_lowerBound = original.lowerBound();
//	//_numberOfFacets = _matrix.numRows();
//	//_numberOfVertices = _matrix.numColumns();
//}

//Destructor

Star::~Star()
{

}

//CTA: Ug
bool inVector(std::vector<int>& v, int element) {
	return std::find(v.begin(), v.end(), element) != v.end();
}

std::vector<int> Star::getAdjacent(int vertex) 
{
	std::cout << "RESTARTING\n";
	std::vector<int> result = {};
	bool in_row;
	for (int i = 0; i < rows(); i++) {
		in_row = false;
		for (int j = 0; j < cols(); j++) {
			if (_matrix.get(i, j) == vertex && !in_row) {
				j = 0;
				in_row = true;
			}
			else if (in_row && !inVector(result, vertex)) {
				result.push_back(_matrix.get(i, j));
			}
		}
	}

	std::cout << "Adjacent to " << vertex << ":\t";
	for (int i : result) std::cout << i << " ";
	std::cout << std::endl;

	return result;
}

//Returns the number of rows
int Star::rows() const { return _matrix.numRows(); }

//Returns the number of columns
int Star::cols() const { return _matrix.numColumns(); }


//Valculates the theoretical minimum vertices
int Star::lowerBound() const { return _lowerBound; }

//Calculates the theoretical maximum vertices
int Star::upperBound() const { return _upperBound; }

//return the number of facets
int Star::numberOfFacets() const { return _matrix.numRows(); }

//return the number of vertices
int Star::numberOfVertices() const { return _upperBound; } // _matrix.numColumns(); }

//return the number of facets converging at each vertex
int Star::facetsPerVertex() const { return _facetsPerVertex;  }

//sets secondary matrix NOT WORKING
void Star::matrixConvert()
{
    _vertexMatrix = Matrix<int>(numberOfVertices(), _facetsPerVertex);
    std::vector<int> indexArray(_vertexMatrix.numRows(), 0);
    int curVertex = 0;
    int curFacet = 0;
    //loop through original matrix
    for (unsigned curRow = 0; curRow < _matrix.numRows(); curRow++)
    {
        for (unsigned curCol = 0; curCol < _matrix.numColumns(); curCol++)
        {
            //get the current vertex and facet
            curVertex = _matrix.get(curRow, curCol);
            curFacet = curRow;
            //insert that facet into the new matrix
            _vertexMatrix.set(curFacet, curVertex, indexArray[curVertex]);
            //incriment index
            indexArray[curVertex]++;
        }
    }
	std::cout << "THIS IS THE OLD FACET MATRIX!\n";
	std::cout << _matrix.toString() << "\n";
	std::cout << "THIS IS THE NEW VERTEX MATRIX!\n";
	std::cout << _vertexMatrix.toString() << "\n";
}

//calculates and sets bounds
void Star::calculateBounds()
{
    int count = 0;
    int maxVal = 0;
    for (int i = 0; i < _matrix.numRows(); i++)
    {
        for (int j = 0; j < _matrix.numColumns(); j++)
        {
            int val = _matrix.get(i, j);
            if (val == 1)
                count++;
            if (val > maxVal)
                maxVal = val;
        }
    }

    _facetsPerVertex = count;
    _upperBound = maxVal;
    _lowerBound = _matrix.numRows() / count;
    //_numberOfFacets = _matrix.numRows();
    //_numberOfVertices = maxVal + 1;
}






