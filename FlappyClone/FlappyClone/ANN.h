#ifndef ANN_H
#define ANN_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "MathUtil.h"
#include "Perceptron.h"
#include "Chromosome.h"

class ANN
{
public:
	ANN(float threshold, float bias, bool isOutputDigital);
	~ANN();
	Perceptron * createNode(std::string id);
	Perceptron * createInputNode(std::string id);
	Perceptron * createOutputNode(std::string id);
	void createConnection(std::string fromId, std::string toId);
	void createConnection(std::string fromId, std::string toId, float weight);
	std::map<std::string, Perceptron *> getAllNodes();
	std::map<std::string, Perceptron *> getInputNodes();
	std::map<std::string, Perceptron *> getOutputNodes();
	Chromosome genChromosome();
	void applyChromosome(Chromosome chromosome);
	void genFromChromosome(Chromosome chromosome);
	void reset();
private:
	std::map<std::string, Perceptron *> m_allNodes;
	std::map<std::string, Perceptron *> m_inputNodes;
	std::map<std::string, Perceptron *> m_outputNodes;
	float m_threshold;
	float m_bias;
	bool m_isDigital;
};

#endif // !ANN_H
