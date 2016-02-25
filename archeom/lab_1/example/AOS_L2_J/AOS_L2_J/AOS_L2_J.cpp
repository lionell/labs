#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <math.h>
#include <stdlib.h> 

using namespace std;

int const reg=9,bit=20;
int Registers[reg][bit];
int nm[3]={0,0,0};
int OF=0,SF=0;

string Ins;
string operation,myregister[3];

// Трьохадресне додавання

void add3(int r,int t, int e)
{
	//CF=0;
	
	int per=0;
	for(int i=bit-1;i>=0;i--)
	{
		int sum=per+Registers[e][i]+Registers[t][i];
		switch(sum)
		{
			case 0: 
				{
					Registers[r][i]=0;
					per=0;
					break;
				}
			case 1: 
				{
					Registers[r][i]=1;
					per=0;
					break;
				}
			case 2: 
				{
					Registers[r][i]=0;
					per=1;
					
					break;
				}
			case 3: 
				{
					Registers[r][i]=1;
					per=1;
					
					break;
				}
		}
		
	}
	//if (per==1) CF=1;
	
}

// Додавання одиниці

void add2(int r,int t)
{
	int per=0;
	for(int i=bit-1;i>=0;i--)
	{
		int sum=per+Registers[r][i]+Registers[t][i];
		switch(sum)
		{
			case 0: 
				{
					Registers[r][i]=0;
					per=0;
					break;
				}
			case 1: 
				{
					Registers[r][i]=1;
					per=0;
					break;
				}
			case 2: 
				{
					Registers[r][i]=0;
					per=1;
					break;
				}
			case 3: 
				{
					Registers[r][i]=1;
					per=1;
					break;
				}

		}
	}
	
}

// Логічний зсув ліворуч

void shl(int r,int t, int e)
{
	for(int i=0;i<bit-e;i++)
	{
		Registers[r][i]=Registers[r][i+e];
		if (t!=r) Registers[t][i]=Registers[t][i+e];
	}
	for(int i=bit-e-1;i<bit;i++)
	{
		Registers[r][i]=0;
		Registers[t][i]=0;
	}

	
}

// Логічний зсув праворуч

void shr(int r,int t, int e)
{
	for(int i=bit-1;i>=e;i--)
	{
		Registers[r][i]=Registers[r][i-e];
		if (t!=r) Registers[t][i]=Registers[t][i-e];
	}
	for(int i=0;i<e;i++)
	{
		Registers[r][i]=0;
		Registers[t][i]=0;
	}	
}

// Пересилання даних

void mov(int r,int t)
{
	SF=0;
	for (int i=0;i<bit;i++)	Registers[r][i]=Registers[t][i];
	if (Registers[r][0]==1) SF=1;
}

// Інверсія двійкового числа

int invert(int i)
{
	if(i==1)	return 0;	
	return 1;
}

// Представлення числа у двійковому записі

void convert(int k,int l)
{
	int i=bit-1,f=k;SF=0;

	while (abs(k)>0)
	{
		Registers[l][i]=abs(k)%2;
		i--;
		k=k/2;
	}
	while (i>=0)
	{
		Registers[l][i]=0;
		i--;
	}
	
	if (f<0)
	{
		
		for(int h=0;h<bit;h++)	Registers[l][h]=invert(Registers[l][h]);	
		add2(l,8);		
	}
	if (Registers[l][0]==1) SF=1;
	if (f>0 && SF==1) OF=1;
	
	
	
}

//запуск операцій

void FuncOperation(string operation,string myregister[])
{
	int x=0;
	nm[0]=0;
	nm[1]=0;
	nm[2]=0;
	
	for (int i=0;i<3;i++)
	{
		if (myregister[i][0]=='R' && myregister[i].length()==2) nm[i]=int(myregister[i][1])-48;
		else
		{
			if (myregister[i][0]=='M' && myregister[i].length()==2) nm[i]=int(myregister[i][1])+4-48;
			else
			{
			int j=0;
			if(myregister[i][0]=='-')
				j++;

			for(int k=j;k<myregister[i].length();k++)
			{
				x*=10;
				x+=(int(myregister[i][k])-48);
			}
			
			
			if(j==1) x=-x;				
			
			convert(x,i+5);
			cout<<x<<" : ";
			for (int h=0;h<bit;h++) cout<<Registers[i+5][h]<<" ";
			cout<<endl;
			cout<<endl;
			x=0;
		}
		}
	
	}
	
	if (operation=="mov")
	{
		if (nm[1]!=0) mov(nm[0],nm[1]);
		else mov(nm[0],6);
	}

	if (operation=="add")
	{
		if (nm[1]!=0 && nm[2]!=0) add3(nm[0],nm[1],nm[2]);
		if (nm[1]!=0 && nm[2]==0) add3(nm[0],nm[1],7);
		if (nm[1]==0 && nm[2]!=0) add3(nm[0],6,nm[2]);
		if (nm[1]==0 && nm[2]==0) add3(nm[0],6,7);
	}

	if (operation=="shl")
	{
		
		if (nm[1]!=0 && nm[2]!=0) cout<<"error";
		if (nm[1]!=0 && nm[2]==0) 
		{
			int j=0;
			if(myregister[2][0]=='-')
				j++;

			for(int k=j;k<myregister[2].length();k++)
			{
				x*=10;
				x+=(int(myregister[2][k])-48);
			}			
			if(j==1) shr(nm[0],nm[1],x);	
			shl(nm[0],nm[1],x);
		}
		if (nm[1]==0 && nm[2]!=0) cout<<"error";
		if (nm[1]==0 && nm[2]==0) 
		{
			int j=0;
			if(myregister[2][0]=='-')
				j++;

			for(int k=j;k<myregister[2].length();k++)
			{
				x*=10;
				x+=(int(myregister[2][k])-48);
			}			
			
			if(j==1) shr(nm[0],nm[0],x);	
			else shl(nm[0],nm[0],x);
		}
	}
	if (operation=="shr")
	{
		if (nm[1]!=0 && nm[2]!=0) cout<<"error";
		if (nm[1]!=0 && nm[2]==0) 
		{	
			int j=0;
			if(myregister[2][0]=='-')
				j++;

			for(int k=j;k<myregister[2].length();k++)
			{
				x*=10;
				x+=(int(myregister[2][k])-48);
			}			
			if(j==1) shl(nm[0],nm[1],x);
			shr(nm[0],nm[1],x);
		}
		if (nm[1]==0 && nm[2]!=0) cout<<"error";
		if (nm[1]==0 && nm[2]==0) 
		{
			int j=0;
			if(myregister[2][0]=='-')
				j++;

			for(int k=j;k<myregister[2].length();k++)
			{
				x*=10;
				x+=(int(myregister[2][k])-48);
			}			
			if(j==1) shl(nm[0],nm[0],x);
			shr(nm[0],nm[0],x);
		}
	}
	
	
}

// Виведення на екран поточного стану

void print_proc()
{
	cout<<Ins<<endl<<endl;
	for (int i=0;i<4;i++)
	{
		cout<<"R"<<i<<" : ";
		for (int j=0;j<bit;j++) cout<<Registers[i][j]<<" ";
		cout<<endl<<endl;
	}
	for (int i=4;i<6;i++)
	{
		cout<<"M"<<i-4<<" : ";
		for (int j=0;j<bit;j++) cout<<Registers[i][j]<<" ";
		cout<<endl<<endl;
	}

}

// Визначення операції та операнд

void model_proc(string line)
{
	int i=0;
	while(line[i]!=' ')
	{
		operation+=line[i];
		i++;
	}
	i++;
	while(line[i]!=',')
	{
		myregister[0]+=line[i];
		i++;
	}
	i++;
	while(line[i]!=',')
	{
		myregister[1]+=line[i];
		i++;
	}
	i++;
	while(i!=line.length())
	{
		myregister[2]+=line[i];
		i++;
	}

	Ins=operation+"  "+myregister[0]+"  "+myregister[1]+"  "+myregister[2];

	print_proc();
	FuncOperation(operation,myregister);
}

// Головна функція

void main()
{
	for(int j=0;j<bit-1;j++)
			Registers[reg-1][j]=0;
	Registers[reg-1][bit-1]=1;

	for(int i=0;i<reg-1;i++)
	{
		for(int j=0;j<bit;j++)
			Registers[i][j]=0;
	}

	string line;
    int count = 0;
    ifstream myfile ("AOS.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
			model_proc(line);
			print_proc();
			cout<<"OF="<<OF<<endl;OF=0;			
			cout<<"SF="<<SF<<endl;SF=0;
			cout<<"__________________________________________________________________"<<endl;
			getch();
			operation="";
			for (int i=0;i<3;i++) myregister[i]="";			
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}