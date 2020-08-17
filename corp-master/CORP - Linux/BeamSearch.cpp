#include"BeamSearch.h"
#include<algorithm>

BeamSearch::BeamSearch() {}

void BeamSearch::run(Star* star) {
  int k = 2;
  int MAX_SIZE = 48;

  std::vector<int> solution = {};

  // need a cover to work with
  Cover cover(star);

  // pass cover to recursive helper method
  runHelper(cover, solution, k, MAX_SIZE,0,0);
}

///////////////////////////////////////////////////////////////
// return true if an element is a vector
template<typename T>
bool inSolution(const std::vector<T>& solution, const T& element) {
	return std::find(solution.begin(), solution.end(), element) != solution.end();
}

void displaySolution(std::vector<int> solution) {
  for(auto item : solution)
    std::cout << item << " ";

  std::cout << std::endl;
}
///////////////////////////////////////////////////////////////

// display map of freq counts
void BeamSearch::displayFacetCounts(std::map<int,double> map)
{
  // display counts
  for(auto key : map)
    std::cout << key.first << "\t|\t" << key.second << std::endl;
}

std::map<int,double> BeamSearch::getPercentCovered(Cover& cover) {

  std::map<int,double> result;

  // loop through each vertex in cover
  for (int i = 0; i < cover.vertices(); i++)
  {
    // select the  the vertex in the cover
    cover.select(i);

    // store that percent covered
    result[i] = cover.coverPercent();

    // deslect to modify cover
    cover.deselect(i);
  }

  return result;
}

int BeamSearch::getAndRemoveMax(std::map<int,double>& map) {
  double max_value = 0;
  int max_key = 0;

  for(auto pair : map)
  {
    if(pair.second > max_value)
    {
      max_key = pair.first;
      max_value = pair.second;
    }
  }

  map.erase(map.find(max_key));

  return max_key;
}

// recrusive helper
void BeamSearch::runHelper(Cover& cover, std::vector<int>& solution, int k, int MAX_SIZE, int current_branch, int current_vertex) {

  std::cout << "current branch:\t" << current_vertex << std::endl;
  // if we found a solution
  if (cover.checkCover())
  {
    // store it
    _solutions.push_back(solution);

    // display it
    std::cout << "SOLUTION FOUND\n";
    displaySolution(solution);

    // kill this branch because every solution following will be a solution of greater length
    return;
  }

  // do all this for each vertice
  if(current_vertex <= cover.vertices())
  {
    // need a new cover for each starting vertex
    Cover temp_cover(cover);

    // get the number of times each vertice appears in a facet
    std::map<int,double> facet_counts = getPercentCovered(temp_cover);

    // need new solution vector for each starting vertex
    std::vector<int> temp_solution = solution;

    // select the starting vertex
    temp_cover.select(current_vertex);

    // if our current solution has exceeded the max solution size, kill this branch
    if (solution.size() > MAX_SIZE) return;

    // go the width of the branching factor
    if(current_branch < k)
    {
      // display solution
      displaySolution(solution);

      // get the next best of the facet counts
      int best = getAndRemoveMax(facet_counts);

      while(inSolution(temp_solution,best))
      {
        best = getAndRemoveMax(facet_counts);
      }

      // store in the solution
      temp_solution.push_back(best);

      // select best vert in current cover
      temp_cover.select(best);

      // recurse with new cover and solution
      runHelper(temp_cover, temp_solution, k, MAX_SIZE, ++current_branch, current_vertex);

    } else runHelper(temp_cover, temp_solution, k, MAX_SIZE, 0, ++current_vertex);

  }
}
