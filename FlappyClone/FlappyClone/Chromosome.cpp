#include "Chromosome.h"

Chromosome::Chromosome() 
{
}

Chromosome::~Chromosome() 
{
}

void Chromosome::addGene(Gene gene)
{
	m_genes.push_back(gene);
}

std::vector<Gene> & Chromosome::getGenes()
{
	return m_genes;
}

void Chromosome::print()
{
	for (auto & gene : m_genes)
	{
		std::cout << "From Id: " << gene.fromId << ", To Id: " << gene.toId << ", Weight: " << gene.weight << std::endl;
	}
}

void Chromosome::saveToTextFile(std::string path)
{
	std::ofstream fileStream;
	fileStream.open(path, std::ofstream::out | std::ofstream::trunc);
	for (auto & gene : m_genes)
	{
		fileStream << gene.fromId << "," << gene.toId << "," << gene.weight << std::endl;
	}
	fileStream.close();
}

void Chromosome::loadFromTextFile(std::string path)
{
	m_genes.clear();
	std::string delimiter = ",";
	int pos = 0;
	int count = 0;
	std::string output;
	std::string value[3];
	std::ifstream fileStream;
	fileStream.open(path);
	while(!fileStream.eof())
	{
		output = "";
		fileStream >> output;
		if ("" != output)
		{
			while ((pos = output.find(delimiter)) != std::string::npos) 
			{
				value[count] = output.substr(0, pos);
				output.erase(0, pos + delimiter.length());
				++count;
			}
			value[2] = output;
			Gene loadedGene;
			loadedGene.fromId = value[0];
			loadedGene.toId = value[1];
			loadedGene.weight = std::stof(value[2]);
			m_genes.push_back(loadedGene);
			count = 0;
		}
	}
	fileStream.close();
}
