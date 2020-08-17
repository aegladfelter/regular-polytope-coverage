

#include"AlgorithmSelect.h"
#include"AlgorithmRunner.h"



AlgorithmSelect::AlgorithmSelect(const Cover& cover, const Config* config) :
    _cover{ cover }, _config{config}
{}


//AlgorithmRunner AlgorithmSelect::selectAlgorithm(const std::string& choice)
//{
//	if (choice == "NaiveAlgorithm")
//    {
//		AlgorithmRunner runner(new NaiveAlgorithm());
//
//        runner.start(_cover, _config);
//
//        return runner;
//	}
//}
