#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class GameWindow {

private:
	int counterTime = 0;
	RenderWindow* gameWindow;
	Font font;
	map<string, Texture> textures;
	vector<vector<string>> orientations;
	vector<vector<string>> legalWords;
	int total_score = 0;

public:
	GameWindow(RenderWindow& desiredWindow, Font desiredFont, map<string, Texture> desiredTextures, 
		vector<vector<string>> desiredOrientations, vector<vector<string>> desiredWords, int time);
	void open();


};