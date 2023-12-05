#include "Timer.h"

// Timer Constructor Definition
Timer::Timer(float x, float y, int startingTime) {

    isTimerPaused = false;

    // Calls the Below Functions
    setPositions(x - 16, y);
    setFirstTexture("PNGs/digits.png");
    setSecondTexture("PNGs/digits.png");

    // Sets the Texture Border of the Digits Asset to get the Correct Number
    firstDigitSprite.setTextureRect(sf::IntRect(0 + 21 * firstDigit, 0, 21, 32));
    secondDigitSprite.setTextureRect(sf::IntRect(0 + 21 * secondDigit, 0, 21, 32));

    // Sets the Counter Starting Time based on the Constructor Value
    startTime = seconds(startingTime);

}

// Function Sets the First Digit's Sprite's Texture
void Timer::setFirstTexture(string fileName) {

    firstDigitTexture.loadFromFile(fileName);
    setFirstSprite();

}

// Function Sets the Second Digit's Sprite's Texture
void Timer::setSecondTexture(string fileName) {

    secondDigitTexture.loadFromFile(fileName);
    setSecondSprite();

}

// Function Sets the First and Second Digits' Sprite's Positions
void Timer::setPositions(float x, float y) {

    firstDigitPosition.x = x;
    firstDigitPosition.y = y;

    secondDigitPosition.x = (x + 31);
    secondDigitPosition.y = y;

}

// Function Sets the First Digit's Sprite
void Timer::setFirstSprite() {

    firstDigitSprite = sf::Sprite(firstDigitTexture);
    firstDigitSprite.setScale(1.5f, 1.5f);
    firstDigitSprite.setPosition(firstDigitPosition.x, firstDigitPosition.y);

}

// Function Sets the Second Digit's Sprite
void Timer::setSecondSprite() {

    secondDigitSprite = sf::Sprite(secondDigitTexture);
    secondDigitSprite.setScale(1.5f, 1.5f);
    secondDigitSprite.setPosition(secondDigitPosition.x, secondDigitPosition.y);

}

// Function used to Continuously Update the Timer
void Timer::updateTimer() {

    // Checks whether the Timer is Paused or Not
    if (!(isTimerPaused)) {

        // Calculates the Elapsed Time based on the Start Time and Clock Elapsed Time
        elapsed = (startTime - clock.getElapsedTime());

        int tempSeconds = floor(elapsed.asSeconds());

        // Updates the Counter Digits if the Timer Has At Least 0 Seconds on it
        if (tempSeconds >= 0) {

            string secondsString = to_string(tempSeconds);

            if (secondsString.length() == 2) {

                firstDigit = (int)(secondsString[0] - 48);
                secondDigit = (int)(secondsString[1] - 48);

            }
            else {

                firstDigit = 0;
                secondDigit = (int)(secondsString[0] - 48);

            }

            firstDigitSprite.setTextureRect(sf::IntRect(0 + 21 * firstDigit, 0, 21, 32));
            secondDigitSprite.setTextureRect(sf::IntRect(0 + 21 * secondDigit, 0, 21, 32));

        // Paused the Timer once 0 Seconds is Reached
        } else {

            setPaused(true);

        }

    }
}

// Function Sets the Paused Time of the Timer
void Timer::setPausedTime() {

    if (isTimerPaused) {

        pausedTime += clock.getElapsedTime();

    }

}

// Function Returns the Timer's Pause State
bool Timer::getTimerPausedState() {

    return isTimerPaused;

}

// Function Sets the Pause State for the Timer
void Timer::setPaused(bool pauseState) {

    isTimerPaused = pauseState;

}

// Function Restarts the Clock Object
void Timer::restartTimer() {

    clock.restart();

}

// Function Returns the Elapsed Time
Time Timer::getElapsedTime() {

    return elapsed;

}