#include "Timer.h"

Timer::Timer(float x, float y) {

	isTimerPaused = false;

	setPositions(x, y);
	setFirstTexture("PNGs/digits.png");
	setSecondTexture("PNGs/digits.png");

	firstDigitSprite.setTextureRect(sf::IntRect(0 + 21 * firstDigit, 0, 21, 32));
	secondDigitSprite.setTextureRect(sf::IntRect(0 + 21 * secondDigit, 0, 21, 32));

}

void Timer::setFirstTexture(string fileName) {

	firstDigitTexture.loadFromFile(fileName);
	setFirstSprite();

}

void Timer::setSecondTexture(string fileName) {

	secondDigitTexture.loadFromFile(fileName);
	setSecondSprite();

}

void Timer::setPositions(float x, float y) {

	firstDigitPosition.x = x;
	firstDigitPosition.y = y;

	secondDigitPosition.x = (x + 21);
	secondDigitPosition.y = y;

}

void Timer::setFirstSprite() {

	firstDigitSprite = sf::Sprite(firstDigitTexture);
	firstDigitSprite.setPosition(firstDigitPosition.x, firstDigitPosition.y);

}

void Timer::setSecondSprite() {

	secondDigitSprite = sf::Sprite(secondDigitTexture);
	secondDigitSprite.setPosition(secondDigitPosition.x, secondDigitPosition.y);

}

void Timer::updateTimer() {

	if (!(isTimerPaused)) {
		elapsed = (startTime - clock.getElapsedTime());

		int tempSeconds = floor(elapsed.asSeconds());

		if (tempSeconds >= 0) {

			string secondsString = to_string(tempSeconds);

			if (secondsString.length() == 2) {

				firstDigit = (int)(secondsString[0] - 48);
				secondDigit = (int)(secondsString[1] - 48);

			} else {

				firstDigit = 0;
				secondDigit = (int)(secondsString[0] - 48);

			}

			firstDigitSprite.setTextureRect(sf::IntRect(0 + 21 * firstDigit, 0, 21, 32));
			secondDigitSprite.setTextureRect(sf::IntRect(0 + 21 * secondDigit, 0, 21, 32));

		} else {

				setPaused(true);

		}

	}
}

void Timer::setPausedTime() {

	if (isTimerPaused) {

		pausedTime += clock.getElapsedTime();

	}

}

bool Timer::getTimerPausedState() {

	return isTimerPaused;

}

void Timer::setPaused(bool pauseState) {

	isTimerPaused = pauseState;

}

void Timer::restartTimer() {

	clock.restart();

}

sf::Time Timer::getElapsedTime() {

	return elapsed;

}
