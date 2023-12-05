#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Declares the Timer Class
class Timer {

private:
	// Creates a Clock and Time Objects used to Update the Timer
	Clock clock;
	Time elapsed;
	Time startTime;
	Time pausedTime;

	// Boolean Keeps Track of the Timer's Paused State
	bool isTimerPaused;

public:

	// Establishes the Objects needed to Display the First Counter Number Sprite
	Vector2f firstDigitPosition;
	Texture firstDigitTexture;
	Sprite firstDigitSprite;

	// Establishes the Objects needed to Display the Second Counter Number Sprite
	Vector2f secondDigitPosition;
	Texture secondDigitTexture;
	Sprite secondDigitSprite;

	int firstDigit = 0;
	int secondDigit = 0;

	// Declares the Timer Constructor
	Timer(float x, float y, int startingTime);


	// Declares Various Methods used throughout the Timer Class
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