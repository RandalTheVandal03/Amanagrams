#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Timer {

private:
	Clock clock;
	Time elapsed;
	Time startTime;
	Time pausedTime;
	bool isTimerPaused;

public:

	sf::Vector2f firstDigitPosition;
	sf::Texture firstDigitTexture;
	sf::Sprite firstDigitSprite;

	sf::Vector2f secondDigitPosition;
	sf::Texture secondDigitTexture;
	sf::Sprite secondDigitSprite;

	int firstDigit = 0;
	int secondDigit = 0;

	Timer(float x, float y, int startingTime);

	void setFirstTexture(string fileName);
	void setSecondTexture(string fileName);
	void setPositions(float x, float y);
	void setFirstSprite();
	void setSecondSprite();

	void updateTimer();
	void setPausedTime();
	void setPaused(bool pauseState);
	void restartTimer();

	bool getTimerPausedState();
	Time getElapsedTime();

};