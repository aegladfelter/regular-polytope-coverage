
#ifndef _MATRIX_GUARD
#define _MATRIX_GUARD 1

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

template <typename T>
class Matrix
{
protected:
    T* _matrix;
    unsigned _rows;
    unsigned _columns;

public:
    //
    // For default initialization only
    //
    Matrix() : _matrix{ nullptr }, _rows{ 0 }, _columns{ 0 }
    {}

    //
    // Rectangular matrix
    //
    Matrix(unsigned rows, unsigned cols) : _rows(rows), _columns(cols)
    {
        _matrix = new T[rows * cols];
        clear();
    }

    //
    // Square matrix
    //
    Matrix(unsigned rows) : _rows(rows), _columns(rows)
    {
        _matrix = new T[rows * rows];
        clear();
    }

    //
    // Copy Construction
    //
    Matrix(const Matrix<T>& rhs) : _rows{ rhs._rows }, _columns{rhs._columns}
    {
        // Allocate parallel array
        this->_matrix = new T[_rows * _columns];

        // Copy contents
        memcpy(this->_matrix, rhs._matrix, _rows * _columns * sizeof(T));
    }

    virtual ~Matrix()
    {
        delete[] _matrix;
        _matrix = nullptr;
    }

    unsigned numRows() const { return _rows; }
    unsigned numColumns() const { return _columns; }

    // Zero out the array
    void clear()
    {
        memset(_matrix, T{}, _rows * _columns * sizeof(T));
    }

    const Matrix<T>& operator= (const Matrix<T>& rhs)
    {
        // check for self-assignment
        if (&rhs == this) return *this;

        //
        // Kill old array, acquire dimensions, and reallocate the array.
        //
        delete[] this->_matrix;

        _rows = rhs.numRows();
        _columns = rhs.numColumns();

        this->_matrix = new T[_rows * _columns];

        //
        // Copy contents
        //
        memcpy(this->_matrix, rhs._matrix, _rows * _columns * sizeof(T));

        return *this;
    }

    //
    // Returns M[i][j] : We calculate as matrix[offset = i * cols + j];
    //
    inline T get(unsigned r, unsigned c) const
    {
        return _matrix[r * _columns + c];
    }

    //
    // Sets M[i][j] : We calculate as matrix[offset = i * cols + j];
    //
    inline void set(unsigned r, unsigned c, const T& val)
    {
        //std::cout << "M[" << r << "][" << c << "] = M[" << r * _columns + c << "] = " << val << std::endl;
        _matrix[r * _columns + c] = val;
        //std::cout << "M[" << r << "][" << c << "] = M[" << r * _columns + c << "] = " << _matrix[r * _columns + c] << std::endl;
    }

    //
    // toString
    //
    std::string toString() const
    {
        std::string str = "";

        for (unsigned r = 0; r < _rows; r++)
        {
            for (unsigned c = 0; c < _columns; c++)
            {

                str += std::to_string(this->get(r, c));
                if (c - 1 != _columns) str += " "; // formatting
            }
            str += "\n";
        }

        return str;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
    {
        os << m.toString();
        return os;
    }
};

#endif
