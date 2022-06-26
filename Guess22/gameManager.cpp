#include "GameManager.h"

namespace FrD
{
	bool GameManager::isRunning = true;
	std::string GameManager::userInput = "";
    uint32_t GameManager::secretNumber = NULL;
    uint32_t GameManager::maxNumber = NULL;
    uint32_t GameManager::maxGuesses = NULL;
    uint32_t GameManager::numOfGuesses = 0;

    uint32_t GameManager::randomNumber(uint32_t max_number)
    {
        return rand() % max_number;
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

    std::string GameManager::getUserInput(std::string message)
    {
        std::string _userInput = "";
        std::cout << message;
        std::getline(std::cin, _userInput);
        return _userInput;
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

        } while (!isDigit(_userInput) && std::stoi(_userInput) > 0 && std::stoi(_userInput) <= 3);

        switch (std::stoi(_userInput))
        {
        case 1:
            maxGuesses = 7;
            maxNumber = 10;
            break;
        case 2:
            maxGuesses = 5;
            maxNumber = 20;
            break;

        case 3:
            maxGuesses = 3;
            maxNumber = 30;
            break;

        default:
            break;
        }
    }

	void GameManager::run()
	{
        srand(time(0));
        
        while (isRunning)
        {
            setDifficulity();

            secretNumber = randomNumber(maxNumber);
            uint32_t userInputAsDigit = NULL;
            numOfGuesses = 0;
            do
            {
                if (numOfGuesses > maxGuesses)
                {
                    break;
                }

                userInput = "";
                userInputAsDigit = NULL;
                while (!isDigit(userInput))
                {
                    system("CLS");
                    //std::cout << secretNumber;
                    userInput = getUserInput("Enter your guess: ");
                }
                numOfGuesses++;
                userInputAsDigit = std::stoi(userInput);
            } while (userInputAsDigit != secretNumber);

            if (numOfGuesses > maxGuesses)
                std::cout << "\nYou Lost!\n";

            else
                std::cout << "\nYou Win!\n";

            if (getUserInput("Do another game? [y/n]: ") != "y")
            {
                isRunning = false;
                std::cout << "Bye!";
            }
        };
	}
}