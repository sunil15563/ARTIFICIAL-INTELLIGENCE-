#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char tic[3][3];
void user();
void display()                //display function definition
{
	for( int t=0;t<3;t++)
	{
		cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
		cout<<"		--|---|--"<<endl;
	}
}
void newdisp()                //display function definition
{
	for( int t=0;t<3;t++)
	{
		cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
		cout<<"		--|---|--"<<endl;
	}
}

int horcheck()              //checks each element of a horizontal line to be same    
{ 
	int d;
	if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])&&(tic[0][1]!=' '))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])&&(tic[1][1]!=' '))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])&&(tic[2][2]!=' ')))
		d=1;                        
	else                        //returns 1 if all 3 elements of any horizontal line are same
		d=0;                        //else returns 0
	return d;
}
int vercheck()              //checks each element of a vertical line to be same   
{ int e;
if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])&&(tic[0][0]!=' '))||((tic[0][1]==tic[1][1])&&(tic[1][1]==tic[2][1])&&(tic[0][1]!=' '))||((tic[0][2]==tic[1][2])&&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' ')))
e=1;                        
else                        //returns 1 if all 3 elements of any verticalline are same
e=0;                        //else returns 0
return e;
}

int diagcheck()             //checks each element of a diagonal line to be same
{ 
	int f;
	if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])&&(tic[0][0]!=' '))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' ')))
		f=1;                        
	else                        //returns 1 if all 3 elements of any diagonalline are same
		f=0;                        //else returns 0
	return f;
}

int check()                     //check winning conditions for any player
{
int d=horcheck();                 //horcheck function call
int e=vercheck();                 //vercheck function call
int f=diagcheck();                //diagcheck function call

return (d||e||f);
}


void pc()          //pc turn
{
	int f,z,i;
	srand(time(NULL));
	cout<<"\n	THIS IS THE COMPUTER'S MOVE \n";
	for(i=0;i<=20;i++)
	{
		f=rand()%3;
		z=rand()%3;
		if(tic[f][z]==' ')      //check for vacant space at entered co-ordinates
		{
			tic[f][z]='O';  //assigning pc 'O' to the co-ordinates
			goto x;         //exiting for loop to display new tictactoe
		}
		else	
		continue;               
	}
	x:newdisp();                    //newdisp function call
	int d=check();                      //check function call
	if(d==0)
		user();                         //user function call
	else
	{
		cout<<"	YOU LOST THIS GAME\n\n";
		exit(1);            //program termination
	}
}

void user()                  //user function definition
{ 
	int x,y;
	cout<<"		ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' i.e 0,1,2 \n";
	cin>>x>>y;
	if(((x<0)||(x>2)) && ((y<0)||(y>2)))  //check for valid co-ordinates
	{
		cout<<"	ENTER THE CORRECT CO-ORDINATES\n";
		user();    // user call again
	}
	else
	{
		if(tic[x][y]==' ')    //check for vacant space at entered co-ordinates
		{
		tic[x][y]='X';  //assigning user 'X' to the co-ordinates
		newdisp();    //newdisp function call
		}
		else
		{
		cout<<"	THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES\n";
		user();       //user function call
		}
	}
	int d=check();            //check function call
	if(d==0)
		pc();                 //pc function call
	else
	{
		cout<<"	YOU ARE THE WINNER\n\n";
		exit(1);      //program termination
	}
}



int main()
{
	srand(time(NULL));	
	int turn;//user turn or pc
	int i,j;
	turn=rand()%2;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			tic[i][j]=' '; 
	cout<<"X is user        ....     O  is pc \n\n";		

	if (turn==0)
		display();
	turn==0?user():pc();
	return 0;
}
