/**
 *  Main execution class.
 *     (a) Given an input file name
 *     (b) Parse
 *     (c) Run algorithm
 *     (d) Report
 *     (e) Clean up
 *
 *  @author C. Alvin, et. al.
 */
#ifndef _EXECUTOR_GUARD
#define _EXECUTOR_GUARD



#include "Config.h"
#include "InputParser.h"
#include "Matrix.hpp"
#include "Cover.h"
#include "Star.h"
#include "AlgorithmSelect.h"
#include "AlgorithmRunner.h"
#include "GeneticAlgorithm.h"
#include"Validator.hpp"
#include"RandomSolutionAlgorithm.h";
#include"OnePointCrossover.h";
#include"BitFlipMutation.h";
#include"CoverPercentRatioFitness.h";
#include"RandomInitGenotype.h";
#include"ColoringFitness.h";
#include"RandomHalfPurge.h"
#include"KindOfRandomInitGenotype.h"
#include"BeamSearch.h"

class Executor
{
protected:
    // Input file stream: adjacency
    std::ifstream _ifs;

    // The resulting adjacency matrix
    Matrix<int>* _matrix;

public:
    Executor(const std::string& infile) : _ifs{ infile }, _matrix{nullptr}
    {
        if (!_ifs) throw "Input file " + infile + " failed to open.";
    }

    virtual ~Executor()
    {
        cleanup();
    }

private:
    // Dynamic Memory Deallocation and closings
    void cleanup()
    {
        delete _matrix;
        Config::cleanUp();
    }

public:
    void execute()
    {
        // Acquire the input matrix
        parse();

        // Execute an algorithm
        run();
    }

private:
    //
    // Parse and acquire the adjacency matrix
    //
    void parse()
    {
        InputParser parser{ _ifs };
        _matrix = parser.parse();
        std::cout << "Parsing complete." << std::endl;
    }

    //
    // Execute the algorithm over the input matrix
    //
    void run()
    {
        // choose an algorithm and display the solution set
		//AlgorithmRunner<BeamSearch> runner;
    AlgorithmRunner<BeamSearch> runner;
    /*r<GeneticAlgorithm<
			KindOfRandomInitGenotype,
			BitFlipMutation,
			ColoringFitness,
			OnePointCrossover,
			RandomHalfPurge>>*/

    Star* star = new Star(*_matrix);

		Cover cover(star);
        runner.start(star);

        delete star;
		std::cout << "SOLUTIONS";
        std::cout << runner.toString();
    }
};

#endif
