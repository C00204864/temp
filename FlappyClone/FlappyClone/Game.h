#ifndef GAME_H
#define GAME_H

// Standard and Library Includes
#include <iostream>
#include <list>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui/imgui-sfml/imgui-SFML.h"

// Game Includes
#include "Bird.h"
#include "PipePair.h"

// Neuroevolution Includes
#include "ANN.h"
#include "Pool.h"

class Game
{
public:
	// Public Methods
	Game();
	~Game();
	void run();
private:
	// Private Methods
	void processEvents();
	void update(sf::Time t_deltaTime);
	void feedForwardANN();
	void nextAi();
	void nextGeneration();
	void handleData();
	void render();
	void renderImgui();
	void renderInputWindow(ImGuiWindowFlags window_flags);
	void renderOutputWindow(ImGuiWindowFlags window_flags);
	void renderColor(float optimal, float val);
	void collisionCheck();
	void reset();
	void setupANN();
	PipePair getClosestPipePair();

	// Private Members
	sf::RenderWindow m_window; // main SFML window
	sf::RenderTexture m_gameRenderTexture; // Used to draw the game within a certain bounds (720p)
	const int GAME_SCREEN_WIDTH = 1280;
	const int GAME_SCREEN_HEIGHT = 720;
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;
	float m_screenRatioX;
	float m_screenRatioY;
	sf::Time timePerFrame;

	// Game Objects
	Bird m_bird;
	std::vector<PipePair> m_pipePairs;

	// Neuroevolution Trackers
	bool m_trainAi;
	ANN * m_ann;
	Pool * m_pool;
	int m_memberNo;
	int m_score;
	int m_generations;

	// Imgui Inputs
	int m_inputPopulation;
	int m_inputHiddenLayerWidth;
	int m_inputElitism;
	float m_inputCrossoverRate;
	float m_inputMutationRate;
	int m_inputFrameRateDivisor;
	int m_inputGenerationsToSkip;
	bool m_inputSkipGenerations;
	int m_inputScoreThreshold;

	// Optimal Inputs
	const int OPT_POPULATION = 200;
	const int OPT_ELITISM = 2;
	const float OPT_MUTATION = 0.1f;
	const float OPT_CROSSOVER = 1.0f;


	// Graph Data
	std::list<float> m_recenteAvg;
	std::list<int> m_recentMax;

	// Ruuning Data
	float m_currentAverage;
	float m_currentMax;
	int m_highestFitness;
	float m_highestAverage;
	int m_runningSum;
	const int GRAPH_SIZE = 120;

	// Imgui Window Attributes
	sf::Vector2f m_outputPos;
	sf::Vector2f m_outputSize;
	float m_outputScale;	
	sf::Vector2f m_parameterPos;
	sf::Vector2f m_parameterSize;
	float m_parameterScale;
};

#endif // !GAME_H