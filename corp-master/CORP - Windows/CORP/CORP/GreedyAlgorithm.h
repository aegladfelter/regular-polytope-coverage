#ifndef _GREEDY_ALGORITHM_GUARD
#define _GREEDY_ALGORITHM_GUARD 1
#include "Algorithm\Algorithm.h"
#include "Cover\Cover.h"
#include <vector>
#include <string>
#include <iostream>
#include "Config\Config.h"

class GreedyAlgorithm : public Algorithm
{
public:
	Star* _star;
	int greedinessMod;
	void run(Star* star);

private:
	int getValue(Cover& original, int vertex);
	std::vector<std::vector<int>> _partialSolutions;
	void runHelper();


};
#endif

/*#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"
#include<vector>
#include<string>
#include<iostream>
#include"../../Config/Config.h"

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

#endif */