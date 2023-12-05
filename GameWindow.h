#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TrieNode.h"
#include "HashTable.h"

using namespace sf;
using namespace std;

class GameWindow {

private:
	RenderWindow* gameWindow;
	Font font;
	map<string, Texture> textures;
	vector<vector<string>> orientations;
	vector<vector<string>> legalWords;
	vector<vector<string>> trieLegalWords;
	vector<vector<string>> hashLegalWords;
	vector<string> userWords;
	int total_score = 0;
	int counterTime = 0;

public:
	GameWindow(RenderWindow& desiredWindow, Font desiredFont, map<string, Texture>& desiredTextures,
		vector<vector<string>>& desiredOrientations, vector<vector<string>>& desiredWords, 
		vector<vector<string>>& desiredTrie, vector<vector<string>>& desiredHash,
		int time);

	void open();
};