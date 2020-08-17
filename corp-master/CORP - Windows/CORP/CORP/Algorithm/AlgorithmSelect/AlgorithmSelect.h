#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include<string>
#include"../../Cover/Cover.h"
#include"../Algorithm.h"
#include "../AlgorithmRunner/AlgorithmRunner.h"
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