#include"MetricCalculator.h"
#include"ColoringFitness.h"
#include<fstream>
MetricCalculator::MetricCalculator(Genotype& genotype) : _genotype { genotype } {}


std::vector<double> MetricCalculator::getMetric(int metric_num)
{
  std::vector<double> result;
  ColoringFitness  cf;

  for (Chromosome chromo : _genotype.getChromosomes())
    switch(metric_num)
    {
    case 0:
      result.push_back(chromo.getFitness());
      break;
    case 1:
      result.push_back((double)chromo.getCover()._bitVector.numberSelected());
      break;
    case 2:
      result.push_back(chromo.getCover().coverPercent());
      break;
    case 3:
      result.push_back(cf.getChromaticNumber(chromo));
      break;
  }
    // define more metrics here then update METRIC_COUT in writeAll()...

  return result;
}


bool MetricCalculator::writeVectorAsList(std::vector<double>& metric ,std::string outfile_path)
{
  std::ofstream outfile;

  outfile.open(outfile_path, std::ios_base::app);

  if (!outfile)
  {
    std::cout << "Metric outputfile not found\n";
    return false;
  }


  // prepare to write fitness list []
  outfile << "[";

  int index = 0;

  // write fitness list
  for (auto item : metric)
  {
    // write the the item
    outfile << item;

    // followed by a comma
    // unlesss its the last item
    if (index < metric.size()-1) outfile << ",";

    // increment index to track where in list we are
    index++;
  }

  // end fitness list
  outfile << "]\n";

  outfile.close();
}

bool MetricCalculator::writeAll(std::string outfile_path)
{

  // UPDATE THIS TO MATCH # of metrics in getMetric()
  const int METRIC_COUNT = 3;

  for(int i = 0; i <= METRIC_COUNT;i++)
  {
    std::vector<double> metric = getMetric(i);
    writeVectorAsList(metric, outfile_path);
  }

  std::ofstream out(outfile_path, std::ios_base::app);
  out << "\n";
  out.close();
}
