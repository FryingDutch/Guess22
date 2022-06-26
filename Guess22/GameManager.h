#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

namespace FrD
{
	class GameManager
	{
	private:
		static bool isRunning;
		static std::string userInput;
		static uint32_t secretNumber;
		static uint32_t maxNumber;
		static uint32_t maxGuesses;
		static uint32_t numOfGuesses;

	private:
		static uint32_t randomNumber(uint32_t max_number);
		static bool isDigit(std::string);
		static std::string getUserInput(std::string message);
		static void setDifficulity();

	public:
		static void run();
	};
}