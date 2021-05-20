#include <iostream>

using namespace std;

class Animal
{
private:
	int Foodchain;
	int Distance;
	bool Arrival;

public:
	Animal(int Foodchain)
	{
		Arrival = false;
		Distance = 0;
		this->Foodchain = Foodchain;
	}
	void setArrival(bool Arrival)
	{
		this->Arrival = Arrival;
	}
	int getDistance(void)
	{
		return Distance;
	}
	bool getArrival(void)
	{
		return Arrival;
	}
	void reset()
	{
		this->Distance = 0;
	}
	void setDistance(int Distance)
	{
		this->Distance += Distance;
	}
	int getFoodchain()
	{
		return Foodchain;
	}
	virtual void run() = 0;
};

class Frog : public Animal
{
public:
	Frog(int Foodchain) : Animal(Foodchain) {};
	
	virtual void run()
	{
		setDistance(2);
		if (getDistance() >= 11)
		{
			setArrival(true);
			reset();
		}
	
	}
};

class Snake : public Animal
{
public:
	Snake(int Foodchain) : Animal(Foodchain) {};
	virtual void run()
	{
		setDistance(1);
		if (getDistance() >= 11)
		{
			setArrival(true);
			reset();
		}

	}
};

class Eagle : public Animal
{
public:
	Eagle(int Foodchain) : Animal(Foodchain) {};
	virtual void run()
	{
		setDistance(4);
		if (getDistance() >= 11)
		{
			setArrival(true);
			reset();
		}

	}
};

class Tiger : public Animal
{
public:
	Tiger(int Foodchain) : Animal(Foodchain) {};
	virtual void run()
	{
		setDistance(3);
		if (getDistance() >= 11)
		{
			setArrival(true);
			reset();
		}

	}
};



int main()
{
	char track[11] = { 0 };
	int i;
	for (i = 1; i < 11; ++i)
		track[i] = '0';
	char c;
	char command;
	int S, F, E, T;
	int s_num, f_num, e_num, t_num;
	s_num = f_num = e_num = t_num = 0;
	S = F = E = T = 0;
	i = 0;
	Animal* frog = new Frog(4);
	Animal* snake = new Snake(3);
	Animal* eagle = new Eagle(2);
	Animal* tiger = new Tiger(1);

	cout << "Select Animal Sequence(S, F, E, T / ex : S F T E) : ";

	while (cin.get(c) && c != '\n')
	{
		if (c == ' ');
		else
		{
			switch (c)
			{
			case 'S':
				s_num++;
				S = i;
				break;
			case 'F':
				f_num++;
				F = i;
				break;
			case 'E':
				e_num++;
				E = i;
				break;
			case 'T':
				t_num++;
				T = i;
				break;
			default:
				break;
			}
			++i;
		}
	}

	if (s_num > 1 || f_num > 1 || e_num > 1 || t_num > 1)
	{
		cout << "Error!\n";
		return 0;
	}

	while (true)
	{
		char predator;
		for (i = 1; i < 11; ++i)
		{
			cout << "\t" << track[i];
		}
		cout << endl;

		
		for (i = 1; i < 11; ++i)
			track[i] = '0';

		if (frog->getArrival() && snake->getArrival() && tiger->getArrival() && eagle->getArrival())
			break;
		if (T <= 0)
			if (tiger->getArrival() != true)
			{
				tiger->run();
				track[tiger->getDistance()] = 'T';
			}
		if (E <= 0)
			if (eagle->getArrival() != true)
			{
				eagle->run();
				predator = track[eagle->getDistance()];
				if (predator == 'T')
				{
					//cout << "eagle got caught\n";
					eagle->reset();
				}
				else
					track[eagle->getDistance()] = 'E';
			}
		if (S <= 0)
			if (snake->getArrival() != true)
			{
				snake->run();
				predator = track[snake->getDistance()];
				if (predator == 'E' || predator == 'T')
				{
					//cout << "snake got caught\n";
					snake->reset();
				}
				else
					track[snake->getDistance()] = 'S';

			}

		if (F <= 0)
			if (frog->getArrival() != true)
			{
				frog->run();
				predator = track[frog->getDistance()];
				if (predator == 'E' || predator == 'T' || predator == 'S')
				{
					//cout << "frog got caught\n";
					frog->reset();
					//cout << "frog->distance : " << frog->getDistance() << endl;
				}
				else
					track[frog->getDistance()] = 'F';
			}
		--S;
		--F;
		--T;
		--E;
	}

	delete[] frog;
	delete[] snake;
	delete[] eagle;
	delete[] tiger;
}