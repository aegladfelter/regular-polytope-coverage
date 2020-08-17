

#include"Validator.hpp"
#include "Executor.hpp"
#include"Config.h"

const std::string DEFAULT_INPUT = "600cell_facets.txt";
const std::string DEFAULT_SOLUTION_SET = "../../data/24cell_corelist.txt";

int main(int argc, const char* argv[])

{
	Validator valid;
	Cover cover;

    if (!Config::initialize(argc, argv))
    {
        std::cerr << "Config file could be parsed; exiting." << std::endl;
        return 1;
    }

    Executor* executor = new Executor{Config::getInstance()->pull("AdjacencyList", DEFAULT_INPUT)};

    executor->execute();

    delete executor;

}
