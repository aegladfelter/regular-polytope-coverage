/**
*  file:	Genotype.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Genotype is a container for chromosomes.
*/

#include"Genotype.h"
#include<sstream>
#include<fstream>
#include"../GeneticOperator/Fitness/ColoringFitness/ColoringFitness.h"
#include"../../../Config/Config.h"
// return the genotype as a vector of chromosomes
std::vector<Chromosome>& Genotype::getChromosomes() { return _chromosomes; }

// add a chromosome to the genotype
bool Genotype::appendChromosome(Chromosome& chromosome)
{
	_chromosomes.push_back(chromosome);
	return true;
}

// remove a chromsome for the genotype
bool Genotype::removeChromosome(int index) 
{
	_chromosomes.erase(_chromosomes.begin()+index);
	return true;
}

// string representation of a genotype
std::string Genotype::toString() 
{
	std::string result = "";

	for (Chromosome chrom : getChromosomes()) 
	{
	
		result += (chrom.getCover().toString() + "\t|\t" + std::to_string(chrom.getFitness()) + "\t|\t" + std::to_string(chrom.getCover()._bitVector.numberSelected())+ "\n");
	}

	return result;
}

// return the most fit chromosome of the genotype
Chromosome Genotype::getMostFit() 
{
	Chromosome max = _chromosomes.at(0);

	for (Chromosome& chromo : _chromosomes) {
		if (chromo.getFitness() >= max.getFitness())
			max = chromo;
	}

	return max;
	
}

std::vector<double> Genotype::getFitnesses()
{
	std::vector<double> result;

	for (Chromosome chromo : _chromosomes)
		result.push_back(chromo.getFitness());

	return result;

}

std::vector<double>  Genotype::getNumberSelecteds()
{
	std::vector<double> result;

	for (Chromosome chromo : _chromosomes)
		result.push_back((double)chromo.getCover()._bitVector.numberSelected());

	return result;
}

std::vector<double> Genotype::getPercentCovereds()
{
	std::vector<double> result;

	for (Chromosome chromo : _chromosomes)
		result.push_back(chromo.getCover().coverPercent());

	return result;
}

std::vector<double> Genotype::getChromaticNumbers()
{

	ColoringFitness cf;

	std::vector<double> result;

	for (Chromosome chromo : _chromosomes)
		result.push_back(cf.getChromaticNumber(chromo));

	return result;
}

// write vector as a list python's eval() will understamd
bool Genotype::writeVectorAsList(std::vector<double> vector, std::string outfile_path)
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
	for (auto item : vector)
	{
		// write the the item
		outfile << item;

		// followed by a comma
		// unlesss its the last item
		if (index < vector.size()-1) outfile << ",";


		// increment index to track where in list we are
		index++;
	}

	// end fitness list
	outfile << "]";

	outfile.close();
}

bool Genotype::writeString(std::string outfile_path, std::string towrite)
{
	// open file
	std::ofstream outfile;
	outfile.open(outfile_path, std::ios_base::app);

	if (!outfile)
	{
		std::cout << "Metric outputfile not found\n";
		return false;
	}

	// write new line
	outfile << towrite;

	// close file
	outfile.close();

	return true;
}


bool Genotype::writeMetrics(std::vector<double> fitness, 
	std::vector<double> cover_perc, std::vector<double> num_selected, std::vector<double> chromatic_numbers, int generation, std::string outfile_path)
{

	// write generation
	//if(!writeString(outfile_path, "Generation:\t"+ std::to_string(generation))) return false;
	//if (!writeString(outfile_path, "\n")) return false;

	// write fitness
	if(!writeVectorAsList(fitness,outfile_path)) return false;

	if(!writeString(outfile_path,"\n")) return false;

	// write cover_perc
	if(!writeVectorAsList(cover_perc, outfile_path)) return false;

	if(!writeString(outfile_path,"\n")) return false;

	// write num selected
	if(!writeVectorAsList(num_selected,outfile_path)) return false;

	if (!writeString(outfile_path, "\n")) return false;

	// write chromatic numbers
	if (!writeVectorAsList(chromatic_numbers, outfile_path)) return false;


	if (!writeString(outfile_path, "\n")) return false;
	if (!writeString(outfile_path, "\n")) return false;

	return true;

}