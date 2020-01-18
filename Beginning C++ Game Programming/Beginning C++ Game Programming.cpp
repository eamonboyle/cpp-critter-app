// Beginning C++ Game Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void GetStats();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

void Critter::Talk()
{
	cout << "I'm a critter and I feel ";
	int mood = GetMood();

	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "fustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";
	m_Hunger -= food;

	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!\n";
	m_Boredom -= fun;

	if (fun < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

void Critter::GetStats()
{
	cout << "Boredom: " << m_Boredom << "\n"
		<< "Hunger: " << m_Hunger << "\n"
		<< "Mood: " << GetMood();
}

int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

int main()
{
	Critter crit;
	crit.Talk();

	int choice;

	do
	{
		cout << "\nCritter Caretaker\n\n"
			<< "\t0 - Quit\n"
			<< "\t1 - Listen to your critter\n"
			<< "\t2 - Feed your critter\n"
			<< "\t3 - Play with your critter\n\n";

		cout << "Choice: ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 0:
			cout << "Goodbye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			crit.GetStats();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
			break;
		}

	} while (choice != 0);

	return 0;
}
