#include "GameManager.h"
#include <vector>

namespace FrD
{
	bool GameManager::isRunning = true;
	std::string GameManager::userInput = "";
    std::string GameManager::difficulityAsString = "";
    uint32_t GameManager::secretNumber = NULL;
    uint32_t GameManager::maxNumber = NULL;
    uint32_t GameManager::maxGuesses = NULL;
    uint32_t GameManager::numOfGuesses = 0;
    std::vector<uint32_t>  GameManager::pastGuesses = {};

    uint32_t GameManager::randomNumber(uint32_t max_number)
    {
        return (rand() % max_number) + 1;
    }

    bool GameManager::isDigit(std::string str)
    {
        if (str.length() == 0)
            return false;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (!std::isdigit(str[i]))
                return false;
        }
        return true;
    }

    bool GameManager::isYesOrNo(std::string answer)
    {
        if (answer == "n" || answer == "N" || answer == "y" || answer == "Y")
            return true;
        return false;
    }

    bool GameManager::isYes(std::string answer)
    {
        if (answer == "y" || answer == "Y")
            return true;
        return false;
    }

    bool GameManager::isNo(std::string answer)
    {
        if (answer == "n" || answer == "N")
            return true;
        return false;
    }

    std::string GameManager::getUserInput(std::string message)
    {
        std::string _userInput = "";
        std::cout << message;
        std::getline(std::cin, _userInput);
        return _userInput;
    }

    void GameManager::printStats()
    {
        if (pastGuesses.size() > 0)
        {
            std::cout << "Difficulity: " << difficulityAsString << "\n"
                "Max Number: " << maxNumber << "\n\n" 
                << "Previous Guesses: ";

            for (size_t i = 0; i < pastGuesses.size(); i++)
                std::cout << pastGuesses[i] << "  ";
            std::cout << "\n";

            std::cout << "Tries left: " << (maxGuesses - numOfGuesses) + 1 << "\n";
        }
    }

    void GameManager::setDifficulity()
    {
        std::string _userInput = "";

        do
        {
            system("CLS");
            static std::string text =
                "1) Easy\n"
                "2) Normal\n"
                "3) Hard\n"

                "\nChoose a difficulity: ";

            _userInput = getUserInput(text);

        } while (!isDigit(_userInput) || std::stoi(_userInput) < 1 || std::stoi(_userInput) > 3);

        switch (std::stoi(_userInput))
        {
        case 1:
            maxGuesses = 7;
            maxNumber = 10;
            difficulityAsString = "Easy";
            break;
        case 2:
            maxGuesses = 5;
            maxNumber = 20;
            difficulityAsString = "Normal";
            break;

        case 3:
            maxGuesses = 3;
            maxNumber = 30;
            difficulityAsString = "Hard";
            break;

        default:
            break;
        }
    }

    void GameManager::run()
    {
        srand((uint32_t)time(0));

        while (isRunning)
        {
            static bool keepLastDifficultySetting = false;

            if (!keepLastDifficultySetting)
                setDifficulity();

            secretNumber = randomNumber(maxNumber);
            uint32_t userInputAsDigit = NULL;
            numOfGuesses = 0;
            pastGuesses.clear();

            do
            {
                if (numOfGuesses > maxGuesses)
                {
                    break;
                }

                userInput = "";
                userInputAsDigit = NULL;
                while (!isDigit(userInput) || std::stoi(userInput) > maxNumber || std::stoi(userInput) < 0)
                {
                    system("CLS");
                    printStats();
                    userInput = getUserInput("\nEnter your guess: ");
                }
                userInputAsDigit = std::stoi(userInput);
                pastGuesses.push_back(userInputAsDigit);

                numOfGuesses++;
            } while (userInputAsDigit != secretNumber);

            if (numOfGuesses > maxGuesses)
                std::cout <<
                "\nYou Lost!\n"
                "The secret number was: " << secretNumber << "!\n\n";

            else
                std::cout << "\nYou Win!\n";

            std::string anotherGameAnswer = "";

            while (!isYesOrNo(anotherGameAnswer))
            {
                anotherGameAnswer = getUserInput("Do another game? [y/n]: ");

                if (isNo(anotherGameAnswer))
                {
                    isRunning = false;
                    std::cout << "Bye!";
                }

                else if (isYes(anotherGameAnswer))
                {
                    std::string keepSettingAnswer = "";

                    while (!isYesOrNo(keepSettingAnswer))
                    {
                        keepSettingAnswer = getUserInput("Keep difficulity setting? [y/n]: ");

                        if (isNo(keepSettingAnswer))
                            keepLastDifficultySetting = false;

                        else if (isYes(keepSettingAnswer))
                            keepLastDifficultySetting = true;
                    }
                }
            }

        };
	}
}