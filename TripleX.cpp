#include <iostream>
#include <ctime>

void GameIntroduction(int32_t Difficulty)
{
    // The Story
    std::cout << "\n You are very smart kid, but u was born in poor family with " << Difficulty << " child." << std::endl
        << " U find a safe with money, but u don't know the CODE." << std::endl
        << " Try to find a right combination for take all money and realize your dreams!" << std::endl;
}

bool CheckPlayerCode(int32_t PlayerMultiply, int32_t PlayerSum, int32_t CodeMultiply, int32_t CodeSum)
{
    // Check IsCorrect player code
    if (PlayerMultiply == CodeMultiply && PlayerSum == CodeSum)
    {
        std::cout << "\n----Good job! you open this safe! Keep going!----" << std::endl;
        return true;
    }
    else
    {
        std::cout << "\n----Oops, it's code not right. Try another.----" << std::endl;
        return false;
    }
}

bool PLayGame(int32_t Difficulty)
{
    // Call story
    GameIntroduction(Difficulty);

    // Initialize variables
    const int32_t CodeA = rand() % Difficulty + Difficulty;
    const int32_t CodeB = rand() % Difficulty + Difficulty;
    const int32_t CodeC = rand() % Difficulty + Difficulty;

    // declare and Initialize CodeMultiply and CodeSum variables
    const int32_t CodeMultiply = CodeA * CodeB * CodeC;
    const int32_t CodeSum = CodeA + CodeB + CodeC;

    // Out CodeMultiply and CodeSum
    std::cout << std::endl
        << "--The code multiple is: " << CodeMultiply << std::endl
        << "--The code sum is:      " << CodeSum << std::endl;

    // Declare Player inputs and out them
    int32_t PlayerA, PlayerB, PlayerC;
    std::cout << "Enter your code: " << std::endl;
    std::cin >> PlayerA >> PlayerB >> PlayerC;
    std::cout << "\n==============================" << std::endl;

    // Declare and Initialize PlayerMultiply, PlayerSum
    int32_t PlayerMultiply = PlayerA * PlayerB * PlayerC;
    int32_t PlayerSum = PlayerA + PlayerB + PlayerC;

    // Out Player inputs
/*std::cout << std::endl
    << "----The Player code multiple is: " << PlayerMultiply << std::endl
    << "----The Player code sum is:      " << PlayerSum << std::endl;*/

    // Call Check PLayer Victory
    return CheckPlayerCode(PlayerMultiply, PlayerSum, CodeMultiply, CodeSum);
}

int32_t main()
{
    // real random values
    srand(time(NULL));

    // Current and Max difficult ( numver of safes )
    int32_t LevelDifficulty = 1;
    const int32_t MaxDifficulty = 10;

    // Attempt for open one safe
    const int32_t MaxAttempt = 3;
    int32_t SafeAttempt = MaxAttempt;

    // Counter opened safes
    int32_t OpenSafes = 0;

    while (LevelDifficulty <= MaxDifficulty) // Loop while all level complete
    {
        bool bLevelComplete = PLayGame(LevelDifficulty);

        std::cin.clear(); // clear any errors
        std::cin.ignore(); // Discards any buffer

        if (bLevelComplete)
        {
            // logic if u opened safe
            ++LevelDifficulty;
            SafeAttempt = MaxAttempt;
            ++OpenSafes;
        }
        else
        {
            // logic if u don't open safe
            --SafeAttempt;
            std::cout << "This safe now has " << SafeAttempt << " attempt." << std::endl;

            // skip safe if all attempts are gone
            if (SafeAttempt == 0)
            {
                std::cout << "Unfortunately! You lose this safe." << std::endl;
                ++LevelDifficulty;
            }
        }
        std::cout << "\n==============================" << std::endl;
    }
    // end game message
    std::cout << "\nCongratulations!!! You open " << OpenSafes << " safes with money and your dreams come true!!" << std::endl;

    // exit program
    return 0;
}