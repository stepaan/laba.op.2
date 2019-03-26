#include<iostream>
#include<string>
#include<fstream>
struct command
{
	string name;
	int rez; //rezultat
};
using namespace std;
<<<<<<< HEAD
struct comand
{
	string name;
	int rez;
	comand(void)
	{
		rez=0;
	}
}
int main()
{
	int a;
	ifstream input("premier_league.csv");
	input >> a;
	input.ignore(1);
	command *fil=new command[a];
	string d;
	for(int i=0;i<a;i++)
	{
		int k,r;
		getline(input,fil[i].name,',');
		for(int j=0;j<10;j++)
		{
			getline(input,d,':');
			k=stoi(d);
			getline(input,d,',');
			r=stoi(d);
			if(k>r)
			fil[i].rez=+3;
			else if(k==r)
			fil[i].rez=+1;
		}
	}
}
=======
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
>>>>>>> mykImp
