
#include<string>
#include"Cover.h"
#include"Algorithm.h"
#include "AlgorithmRunner.h"
#include<vector>

class AlgorithmSelect
{
public:
	AlgorithmSelect(const Cover& cover, const Config* config);

	//AlgorithmRunner selectAlgorithm(const std::string& choice);
	

protected:
	Cover _cover;
	const Config* _config;
};