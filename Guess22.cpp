#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

uint32_t randomNumber(uint32_t max_number)
{
    return rand() % max_number;
}

std::string getUserInput(std::string message)
{
    std::string userInput = "";
    std::cout << message;
    std::getline(std::cin, userInput);
    return userInput;
}

bool isDigit(std::string str)
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

int main()
{
    srand(time(0));
    bool running = true;
    uint32_t userChoice = NULL;
    uint32_t secretNumber = NULL;
    std::string userInput = "";

    while (running)
    {
        secretNumber = randomNumber(10);
        uint32_t userInputAsDigit = NULL;
        do
        {
            userInput = "";
            userInputAsDigit = NULL;
            while (!isDigit(userInput))
            {
                system("CLS");
                std::cout << secretNumber;
                userInput = getUserInput("Enter your guess: ");
            }
            userInputAsDigit = std::stoi(userInput);
        } while (userInputAsDigit != secretNumber);

        std::cout << "\nYou Win!\n";
        if (getUserInput("Go another round? [y/n]: ") != "y")
        {
            running = false;
            std::cout << "Bye!";
        }            
    };
}

