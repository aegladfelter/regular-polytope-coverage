#ifndef _METRIC_CALCULATOR_GAURD_
#define _METRIC_CALCULATOR_GAURD_ 1

#include<vector>
#include"Genotype.h"

class MetricCalculator
{

public:

  // take genotype in constructor
  MetricCalculator(Genotype& genotype);

  bool writeAll(std::string outfile);

  // metrics to get
  std::vector<double> getMetric(int metric_num);

  // define custom calculations here...


private:
  // store the genotype we are working with
  Genotype _genotype;

  // write a metric as a list python's eval() will understand
  bool writeVectorAsList(std::vector<double>& metric ,std::string outfile_path);

};


#endif
