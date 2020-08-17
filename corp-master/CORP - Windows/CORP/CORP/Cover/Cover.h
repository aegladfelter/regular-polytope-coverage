/**
*  file:	Cover.h
*  author:	Sarah McGlasson
*  date:	10/1/2017
*  updated:	2/11/2018
*
*  The header file for the Cover class
*
*/

#ifndef _COVER_GUARD_
#define _COVER_GUARD_

#include<iostream>
#include<string>
#include <memory>
#include "../Boolset/BoolSet.h"
#include "../Star/Star.h"



class Cover
{
protected:
public:
    BoolSet _bitVector;							//Boolset representing selected vertices
    BoolSet _facetVector;						//Boolset representing covered facets
    Star* _star;                    //the star object holding shape information

	  Cover();
    Cover(Star* star);					                    //Constructor
    Cover(const Cover& original);				            //copy constructor
    ~Cover();									                      //Destructor
    const Cover& operator=(const Cover& original);	//overloaded equals

    void select(int index);						//selects the vertex at the given index
    void selectUnchecked(int index);  //selects the vertex at the given index
    void deselect(int index);					//deselects the vertex at the given index
    void rebuildFacetVector();        // makes the facet vector match the cover
    bool checkCover() const;					//checks if the given vertex list is a valid cover
    double coverPercent() const;		  //what percent of facets are covered
    int facetsCovered() const;			  //how many facets are covered
    int facets() const;               //total number of facets
    int vertices() const;						  //total number of vertices
    std::string coverToString() const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream&, const Cover& cover)
    {
        std::cout << "Matrix: \n" << cover._star->_matrix.toString() << "\n";
        std::cout << "Vertex list: " << cover._bitVector.toString() << "\n";
        std::cout << "Facet list: " << cover._facetVector.toString() << "\n";
        std::cout << "Facets covered: " << cover.facetsCovered() << "\n";
        std::cout << "Is cover?: " << cover.checkCover() << "\n";
        std::cout << "Percent Covered: " << cover.checkCover() << "\n";
    }
	std::vector<int> ConvertToSet();
};

#endif
