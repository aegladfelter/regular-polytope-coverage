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



#include "../CORP/Config/Config.h"
#include "../CORP/InputParser/InputParser.h"
#include "../CORP/Matrix/Matrix.hpp"
#include "../CORP/Cover/Cover.h"
#include "../CORP/Star/Star.h"
#include "../CORP/Algorithm/AlgorithmSelect/AlgorithmSelect.h"
#include "../CORP/Algorithm/AlgorithmRunner/AlgorithmRunner.h"
#include "../CORP/Algorithm/GeneticAlgorithm/GeneticAlgorithm.h"
#include"../CORP2/Validator.hpp"
#include"../CORP/Algorithm/RandomSolutionAlgorithm/RandomSolutionAlgorithm.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/Crossover/OnePointCrossover/OnePointCrossover.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/Mutation/BitFlipMutation/BitFlipMutation.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/Fitness/CoverPercentRatioFitness/CoverPercentRatioFitness.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/InitGenotype/RandomInitGenotype/RandomInitGenotype.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/Fitness/ColoringFitness/ColoringFitness.h";
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/Purge/RandomHalfPurge/RandomHalfPurge.h"
#include"../CORP/Algorithm/GeneticAlgorithm/GeneticOperator/InitGenotype/RandomInitGenotype/KindOfRandomInitGenotype/KindOfRandomInitGenotype.h"

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
		AlgorithmRunner<GeneticAlgorithm<
			KindOfRandomInitGenotype, 
			BitFlipMutation, 
			ColoringFitness, 
			OnePointCrossover, 
			RandomHalfPurge>> runner;

        Star* star = new Star(*_matrix);

		Cover cover(star);

        runner.start(star);

        delete star;
		std::cout << "SOLUTIONS";
        std::cout << runner.toString();
    }
};

#endif