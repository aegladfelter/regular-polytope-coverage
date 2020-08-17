#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"Algorithm.h"
#include"Cover.h"
#include<vector>
#include<string>
#include<iostream>
#include"Config.h"

class NaiveAlgorithm : public Algorithm
{
public:
	void run(Star* star);

private:
	void runHelper(
		const Cover& cover,
        int MAX_SIZE = 10,
		std::vector<int> solution = {});
};

#endif 