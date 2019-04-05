#include "Perceptron.h"

Perceptron::Perceptron(std::string id, float threshold, float bias, bool isOutputDigital)
	: m_id(id),
	m_outputVal(0.f),
	m_inputCounter(0),
	m_threshold(threshold),
	m_bias(bias),
	m_isDigital(isOutputDigital) 
{
	m_biasWeight = 0.f;
}

Perceptron::~Perceptron() 
{
}

void Perceptron::addInput(Perceptron * perceptron, float weight)
{
	Input input;
	input.node = perceptron;
	input.weight = weight;
	m_inputs.insert(std::pair<std::string, Input>(perceptron->getId(), input));
}

void Perceptron::addOutput(Perceptron * perceptron)
{
	m_outputs.push_back(perceptron);
}

void Perceptron::setValue(float val)
{
	m_outputVal = val;
	for (Perceptron * outputNode : m_outputs)
	{
		outputNode->signalInput();
	}
}

std::string Perceptron::getId()
{
	return m_id;
}

std::map<std::string, Input> & Perceptron::getInputs()
{
	return m_inputs;
}

float Perceptron::getBiasWeight()
{
	return m_biasWeight;
}

void Perceptron::setBiasWeight(float weight)
{
	m_biasWeight = weight;
}

float Perceptron::getOutput()
{
	return m_outputVal;
}

void Perceptron::signalInput()
{
	++m_inputCounter;
	if (m_inputCounter == m_inputs.size())
	{
		float inputSum = 0.f;
		for (auto & pair : m_inputs)
		{
			Input input = pair.second;
			inputSum += (input.weight * input.node->getOutput());
		}
		inputSum += m_bias * m_biasWeight;
		float sigmoid = fastSigmoid(inputSum);
		m_outputVal = m_isDigital ? (sigmoid >= m_threshold ? 1.f : 0.f) : sigmoid;
		for (Perceptron * outputNode : m_outputs)
		{
			outputNode->signalInput();
		}
	}
}

void Perceptron::reset()
{
	m_inputCounter = 0;
	m_outputVal = 0.f;
}

float Perceptron::sigmoid(float val)
{
	return 1 / (1 + pow(2.7, val));
}

float Perceptron::fastSigmoid(float val)
{
	return val / (1 + abs(val));
}
