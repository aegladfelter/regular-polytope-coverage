------------------------------------------------------
Introduction
------------------------------------------------------
This C++ framework addresses the question:

"For any given polytope, find the minimum set of vertices required such that at
least one vertice in the set is adjacent to each of the polytope's facets."

The framework includes classes and methods for the representation of the problem.
Additionally, we provide an environment for the running and testing of relevant algorithms.

Three relevant algorithms have been implemented:
  - Genetic Algorithm
  - Beam Search Algorithm
  - Graph Coloring Algorithm

------------------------------------------------------
Compilation & Execution Instructions
------------------------------------------------------
Visual Studio:
1. Open CORP.sln
2. In the Solution Explorer, right click "Solution 'CORP' (2 projects) and select "Properties"
3. Under "Common Properties", be sure "Single startup project" is selected
3. Click on the drop down menu below the "Single startup project" radio box, select CORP2.
4. Press OK

5. In the Solution Explorer, right click CORP2 and select "Properties"
6. Under "Configuration Properties", select "Debugging"
7. For the field "Command Arguments", supply the path to a configuration file
8. Press Ok
9. Press play to execute the compiled code

g++:
1. Set current directory to "CORP - Linux"
2. Run the command: g++ -std=c++11 *.cpp -out corp.out
3. If there are permission issues, use "chmod 755 corp.out"
4. Execute the compiled code with "./corp.out"

------------------------------------------------------
Configuration
------------------------------------------------------
#
# Example configuration file
#

# the path to the file containing the adjacency matrix
AdjacencyList = adjacency_list_120cell.txt

#
# Genetic Algorithm Settings
#


# the size of the genotype to use
GENOTYPE_SIZE = 15

# the number of mutations to apply to each generation
STEP_SIZE = 1

# the file to output solutions found to
GA_SOLUTION_FILE = GA_solutions.txt

# the file good solutions are found to initialize genotype
CHROMOSOME_FILE = chromosomes.txt

# how many generations to wait before purging
PURGE_DELAY = -1

# output file for metrics
METRIC_OUTPUT = metrics.txt

# how often to write metrics to file
SAMPLE_RATE = 500

# how often we print genotype
DISPLAY_GENOTYPE_DELAY = 500

------------------------------------------------------
Class Descriptions
------------------------------------------------------
InputParser
  InputParser parses a configuration file into an OptionsContainer.

OptionsContainer
  OptionsContainer is a variable length data structure for multiple different
  data types.

Logger
  Logger is used to write text to files and display text in the console.

Config.cpp
  Config uses a singleton design pattern to offer easy access
  across classes to values parsed using InputParser.

Matrix
  Matrix is a 1D representation of a 2D matrix.

Star
  Star stores data regarding the current adjacency list we are
  working with.

BoolSet
  A wrapper of star for this specific problem.

Cover
  Cover offers methods to interact with a BoolSet.

Algorithm
  Algorithm provides functions to assist with running algorithms.

AlgorithmRunner
  AlgorithmRunner provides an environment to run algorithms.

Executor
  Executor allows for easy substitution of algorithm to run.

BeamSearch
  BeamSearch recurses the depth of the tree until a solution is found while
  exploring the width of a given branching factor.

GeneticAlgorithm
  GeneticAlgorithm applies the provided genetic operators.

Chromosome
  Chromosome is a representation of a solution in the genetic algorithm.

Genotype
  A genotype is a container for chromosomes.

InitGenotype
  InitGenotype is a pure virtual class to define the functions a child of
  InitGenotype will overwrite. This class is used to initialize a genotype.

RandomInitGenotype
    RandomInitGenotype is an InitGenotype where a genotype is randomly filled with
    a provided number of chromosomes.

KindOfRandomInitGenotype
  KindOfRandomInitGenotype is an InitGenotype that initializes a genotype using
  solutions listed in a given text file. If the number of solutions provided in
  this text file does not match the desired genotype size, the remainder of the
  genotype will be filled with randomly generated chromosomes.

Crossover
  Crossover is a pure virtual class to define the functions a child of
  Crossover will overwrite. This class is used to generate offspring and select
  the chromosomes that will advance to the next generation.

OnepointCrossover
  OnepointCrossover is a crossover that selects the two strongest chromosomes and
  a random pivot in the range of the length of these chromosomes. The tail ends of
  the two strongest chromosomes are swapped to generate two offspring. These two
  offspring then replace the 2 weakest chromosomes in the genotype for the next
  generation.

Mutation
  Mutation is a pure virtual class to define the functions a child of
  Mutation will overwrite. This class is used to slightly modify each chromosome
  in a given genotype.

BitFlipMutation
  BitFlipMutation is a Mutation that selects a random bit in each chromosome of a given genotype
  negates it.

Fitness
  Fitness is a pure virtual class to define the functions a child of
  Fitness will overwrite. This class is used to calculate and set the fitness of
  each chromosome in a given genotype.

ColoringFitness
  ColoringFitness is a Fitness that uses the number selected, the cover percent,
  and the number of colors used to determine the fitness of each chromosome in a
  given genotype.

CoverPercentFitness
  ColoringFitness is a Fitness that uses the number selected and the cover
  percent to determine the fitness of each chromosome in a given genotype.
