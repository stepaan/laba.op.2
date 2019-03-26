#include<iostream>
#include<string>
#include<fstream>
struct command
{
	string name;
	int rez; //rezultat
};
using namespace std;
void sort(command );
void newfile(command );
void sort(command fill[])
{
	int a, g=1;
	while(g>0)
	{
		g = 0;
		for (int i = 0; i < 19; i++)
		{
			if (fill[i].rez > fill[i+1].rez)
			{
				a = fill[i].rez;
				fill[i].rez = fill[i + 1].rez;
				fill[i + 1].rez = a;
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