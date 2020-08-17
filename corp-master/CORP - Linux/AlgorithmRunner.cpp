


//#include"AlgorithmRunner.h"
//
//
//AlgorithmRunner::AlgorithmRunner(Algorithm* algorithm_to_run) :
//    _algorithm { algorithm_to_run }
//{}
//
//
//bool AlgorithmRunner::start(const Cover& cover, const Config* config)
//{
//	_solutions = _algorithm->run(cover, config);
//
//    return _solutions.size() != 0;
//}
//
//std::vector<std::vector<int>> AlgorithmRunner::getSolutionSet() const
//{
//	// increment all vertices by 1 before returning the solution set
//	std::vector<std::vector<int>> result = _solutions;
//
//	for (std::vector<int> solution : result)
//		for (int vertex : solution) vertex++;
//
//	return result;
//}
//
//std::string AlgorithmRunner::toString() const
//{
//	std::string result = "";
//
//    int count = 1;
//	for (std::vector<int> solution : getSolutionSet())
//	{
//        result += std::to_string(count++) + ": ";
//		for (int vertex : solution)
//		{
//			result += (std::to_string(vertex) + " ");
//		}
//		result += "\n";
//	}
//
//	return result;
//}
//
//
//
