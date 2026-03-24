#include <iostream>
#include <vector>
#include <random>

class player
{
	std::string m_name{};
	int m_health {};
public:
	player() {}
	player(std::string name,int health)
		:m_name(name)
		,m_health(health)
		{}
	
	std::string getName()
	{
		return m_name;
	}

	int getHealth() 
	{
		return m_health;
	}

	void damage(int numCase)
	{
		switch (numCase)
		{
			case 1: case 2:
			{
				m_health -= 50;
				break;
			}

			case 4: case 5:
			{
				m_health -= 20;
				break;
			}
		}
	}

	void printHealth()
	{
		std::cout << "Health: " << m_health << std::endl;
	}
		

};

class game
{
public:
	static int genNum()
	{
		static std::random_device rd;
		static std::mt19937 gen {rd()};
		static std::uniform_int_distribution<int> dist {1,100};
		return dist(gen);
	}

	static int guessNum(int result,int p1Choice,int p2Choice)
	{
		if (p1Choice == result && p2Choice == result)
		{
			
			return 3;
		}

		else if (p1Choice == p2Choice)
		{
			std::cout << "Both Guessed The Same Number!" << std::endl;
			return 0;
		}

		else if (p1Choice == result || p2Choice == result)
		{
			if (p1Choice == result)
			{
				return 1;
			}
			else 
			{
				return 2;
			}	
		}
		if (abs(p1Choice - result) == abs(p2Choice - result))
		{
			std::cout << "Both The Same Distance!" << std::endl;
			return 0;
		}
		else if (abs(p1Choice - result) > abs(p2Choice - result))
		{
			return 4;
		}

		else
		{
			return 5;
		}
		
		return 0;
	}
		


	
	

};
int main()
{
	std::string player1;
	std::string player2;
	int p1Guess{};
	int p2Guess{};
	int finalNum{};

	
	
	
	
	std::cout << "Number Guessing Game" << std::endl;
	std::cout << "Press 1 to Exit" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "PLayer 1 Name: ";
	std::getline(std::cin,player1);
	std::cout << "Player 2 Name: ";
	std::getline(std::cin,player2);
	
	std::cout << "Guess a Number Between 1-100" << std::endl;
	std::cout << "If a Player guesses correctly 50 Health Points are taken off" << std::endl;
	std::cout << "If No Player Guesses Correctly, Whoever is Furthest Gets 20 Health Points Reduced" << std::endl;

	player p1(player1, 100);
	player p2(player2, 100);

	while (p1.getHealth() > 0 && p2.getHealth() > 0)
	{
		std::cout << p1.getName() << " Guess: ";
		std::cin >> p1Guess;
		std::cout << p2.getName() << " Guess: ";
		std::cin >> p2Guess;
		int finalGuess = game::genNum();
		std::cout << "Result: " << finalGuess << std::endl;

		int userGuess = game::guessNum(finalGuess,p1Guess,p2Guess);

		switch (userGuess)
		{
				
			case 3:
			{
				std::cout << "Both Correct!!" << std::endl;
				break;
			}

			case 1:
			{
				p2.damage(1);
				break;

			}
				
			case 2:
			{
				p1.damage(2);

				break;
			}

			case 4:
			{
				p1.damage(4);
				break;
			}

			case 5:
			{
				p2.damage(5);
				break;
			}

		}

		std::cout << p1.getName() << " " << p1.getHealth() << std::endl;
		std::cout << p2.getName() << " " << p2.getHealth() << std::endl;

	}

	return 0;
}
