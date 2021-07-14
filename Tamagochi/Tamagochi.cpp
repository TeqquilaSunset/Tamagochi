#include<iostream>

using namespace std;

void points(int n)	//Вывод поинтов
{
	for (int i = 0; i < 10; i++)
	{
		if (n > 0) cout << "+";
		else cout << "_";
		n--;
	}
	cout << "  ";
}


class Tamagochi
{
public:
	int health = 10;	//здоровье
	int hunger = 0;		//голод
	int fatigue = 0;	//усталость
	int happiness = 5;	//счастье

	void feed()
	{
		hunger--;
		happiness++;
	}

	void play()
	{
		if (fatigue > 0) health--;
		fatigue++;
		happiness++;
	}

	void sleep()
	{
		fatigue = 0;
		health++;
		hunger++;
		happiness -= 2;
	}

	void heal()
	{
		happiness--;
		health += 2;
		fatigue++;
		hunger++;
	}

	void magic_pill()
	{
		health = rand() % 10 + 1;
		hunger = rand() % 10;
		fatigue = rand() % 10;
		happiness = rand() % 10;
	}

	void condition()
	{

		if (health > 10) health = 10;


		if (hunger >= 10)
		{
			hunger = 10;
			health -= 2;
		}
		if (hunger < 0)
		{
			hunger = 0;
			health--;
		}


		if (fatigue >= 10)
		{
			fatigue = 10;
			health--;
		}
		if (fatigue < 0) fatigue = 0;


		if (happiness >= 10) happiness = 10;
		if (happiness <= 0)
		{
			happiness = 0;
			health--;
			fatigue++;
		}
	}

	void out_data()
	{
		const int width = 120;
		const int height = 12;
		system("cls");
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 1 && j == 50)
				{
					cout << "       Bobby       ";
					j += 19;
				}

				if (i < 3 || i>5) cout << "#";

				if (i == 7 && j == 3)
				{
					cout << "  HEALTH      ";
					points(health);
					j += 26;
				}

				if (i == 8 && j == 3)
				{
					cout << "  HUNGER      ";
					points(hunger);
					j += 26;
				}

				if (i == 9 && j == 3)
				{
					cout << "  FATIGUE     ";
					points(fatigue);
					j += 26;
				}

				if (i == 10 && j == 3)
				{
					cout << "  HAPPINESS   ";
					points(happiness);
					j += 26;
				}
			}
			cout << endl;
		}
		cout << endl << "Select number action:" << endl;
		cout << " 1. Feed" << endl << " 2. Play" << endl << " 3. Sleep" << endl << " 4. Heal" << endl << " 5. The Magic Pill(Dangerous)" << endl;
	}

	void user_actions()
	{
		int action;
		cout << ">";
		cin >> action;
		if (!cin.fail())
		{

			switch (action)
			{
			case 1:
				feed();
				break;
			case 2:
				play();
				break;
			case 3:
				sleep();
				break;
			case 4:
				heal();
				break;
			case 5:
				magic_pill();
				break;
			default:
				cout << endl << " Input error, " << "enter: 1 or 2 or 3 or 4 or 5" << endl;
				cout << " To continue press enter...";
				cin.get();
				cin.ignore(100, '\n');
			}
		}
		else
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << " Input error, " << "enter: 1 or 2 or 3 or 4 or 5" << endl;
			cout << " To continue press enter...";
			cin.get();
			cin.ignore(100, '\n');
		}
	}
};

Tamagochi bobby;
int main()
{
	while (bobby.health > 0)
	{
		bobby.out_data();
		bobby.user_actions();
		bobby.condition();
	}

	system("cls");
	bobby.out_data();
	cout << "\t\t\t\t\t\t   ____Game over____" << endl;
	cout << "\t\t\t\t\t\t    Bobby got sick" << endl;
	cout << "\n\nTo continue press enter...";
	cin.get();
	cin.ignore(100, '\n');
	return 0;
}
