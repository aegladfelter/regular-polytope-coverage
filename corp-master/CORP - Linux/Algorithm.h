#ifndef _Algorithm_Guard_
#define _Algorithm_Guard_ 1



#include <vector>
#include "Star.h"

class Algorithm
{
public:
	// every algorithm should overwrite this and use run() as the function to start the algorithm
	virtual void run(Star* star) = 0;
    std::vector<std::vector<int>> getSolutions() const { return _solutions; }

protected:
    std::vector<std::vector<int>> _solutions;
};

#endif
