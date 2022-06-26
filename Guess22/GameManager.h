#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

namespace FrD
{
	class GameManager
	{
	private:
		static bool isRunning;
		static std::string userInput;
		static std::string difficulityAsString;
		static uint32_t secretNumber;
		static uint32_t maxNumber;
		static uint32_t maxGuesses;
		static uint32_t numOfGuesses;

		static std::vector<uint32_t> pastGuesses;

	private:
		static uint32_t randomNumber(uint32_t max_number);
		static bool isDigit(std::string str);
		static bool isYesOrNo(std::string answer);
		static bool isYes(std::string answer);
		static bool isNo(std::string answer);
		static std::string getUserInput(std::string message);
		static void printStats();
		static void printTriesLeft();
		static void setDifficulity();

	public:
		static void run();
	};
}