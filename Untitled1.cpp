#include <iostream>

using namespace std;
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
