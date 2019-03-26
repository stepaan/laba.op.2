#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct command
{
	string name;
	int rez;
	command(void)
	{
		rez = 0;
	};
};
void sort(command[]);
void newfile(command[]);
void read(command[],int);
int main()
{
	int a;
	ifstream input("premier_league.csv");
	input >> a;
	input.ignore(1);
	command *fil = new command[a];
	read(fil, a);
	sort(fil);
	newfile(fil);
	input.close();
}
void read(command fil[],int a)
{
	ifstream input("premier_league.csv");
	input.ignore(3);
	string d;
	for (int i = 0; i < a; i++)
	{
		int k, r;
		getline(input, fil[i].name, ',');
		for (int j = 0; j < 9; j++)
		{
			getline(input, d, ':');
			k = stoi(d);
			getline(input, d, ',');
			r = stoi(d);
			if (k > r)
				fil[i].rez = fil[i].rez + 3;
			else if (k == r)
				fil[i].rez = fil[i].rez + 1;
		}
		getline(input, d, ':');
		k = stoi(d);
		getline(input, d, '\n');
		r = stoi(d);
		if (k > r)
			fil[i].rez = fil[i].rez + 3;
		else if (k == r)
			fil[i].rez = fil[i].rez + 1;
	}
}

void sort(command fill[])
{
	int g = 1;
	while (g > 0)
	{
		g = 0;
		for (int i = 0; i < 19; i++)
		{
			if (fill[i].rez < fill[i + 1].rez)
			{
				swap(fill[i], fill[i + 1]);
				g++;
			}
		}
	}
}
void newfile(command fill[])
{
	ofstream output("results.csv");
	for (int i = 0; i < 19; i++)
	{
		output << fill[i].name << "," << fill[i].rez << "\n";
	}
	output << fill[19].name << "," << fill[19].rez;
	output.close();
}

