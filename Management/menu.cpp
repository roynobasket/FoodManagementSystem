#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include <ctime>
#include <sstream> 
using namespace std;
int toString(char a[]) {                         // string value numerical value
  int c, sign, offset, n;

  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }

  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }

  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1) {
    n = -n;
  }

  return n;
}
void Create()
{	
	system("cls");
	std::fstream fil;
	std::fstream gil;
	
	fil.open ("list.txt",ios::app);
	gil.open ("price.txt",ios::app);
	char ch,L[80],P[80];
	cout<<"Enter line \t";
	   scanf(" %[^\n]s",L);
	cout<<"Enter Price \t";
		scanf(" %[^\n]s",P);
	fil<<L<<endl;
	gil<<P<<endl;
mn:	cout<<"\n do u wanna add another item.\t";
	cin>>ch; fil.close(); gil.close();
	if(ch=='Y'||ch=='y')
	{
		Create();
	}
	else if (ch=='N'||ch=='n') return ;
	else {
		cout<<"\nwrong entry...\n";
	goto mn;
	}
	return;
}

int billing(int i)
{
	int j=0;
	fstream fil,gil,mil,nil;
	fil.open("Billing.txt",ios::app);
	gil.open("History.txt",ios::app);
	nil.open("HisPrice.txt",ios::app);
	mil.open("price.txt",ios::in);
	
	char S[80],ch;
	while(i!=j++)
	mil>>S;
	fil<<S<<endl;
									// real time date...
	const int MAXLEN = 14;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));
    gil << s << '\n';
	nil<<S<<endl;
	
    gil.close();
    mil.close();
    fil.close();
    nil.close();
    cout<<"\n\t\t Do you wanna add something\n\t\t\t";
    cin>>ch;
    
	if(ch=='Y'||ch=='y')
    return 1;
    
	else return 0;
	
}
void Bill()
{
	fstream fil;
	fil.open("Billing.txt",ios::in);
	char W[20];
	int i=0;
		while(fil>>W)
		{
			cout<<"\n\t\t\t"<<W;
			i=i+toString(W);
			
		}
		cout<<"\n\t\tTotal:\t"<<i;
		fil.close();
		remove( "Billing.txt");
	fstream	gil("Billing.txt",ios::in);
		gil.close();
		getche();
}
void Display()										// 		Menu.........
{	
	system("cls");
	fstream fil,gil;
	fil.open("list.txt",ios::in);
	gil.open("price.txt",ios::in);
	char S[80]; int i=1;
	cout<<endl<<endl<<"\t\t";
	while(fil>>S)
	{      
		
		cout<<i++<<"."<<"\t"<<S<<"\t\t\t";
		gil>>S;
		cout<<S<<"\t Rs./only"<<"\n\t\t";
	}
	fil.close();
	gil.close();
	cout<<"\n\t\t Your Order:\n\t\t\t";
	cin>>i;
	if(billing(i)==1)
		Display();
	return;
	
}
void Word()											//		profit..
{
	const int MAXLEN = 14;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));
	fstream mil,nil;
	mil.open("History.txt",ios::in);
	nil.open("HisPrice.txt",ios::in);
	char W[20],V[20];
	float x = 0.0;
	float d=0.0,y =0.0,m=0.0,T=0.0; 
	while(nil>>W)
	{      mil>>V;
		x=toString(W);
	if(x<=10)
	{	x=2.1;
		}	
	else if(x<=25)
	{	x=(x*10)/100;
	}
	else{
		x=(x*7)/100;
	}
	
		if(strcmp(V,s)==0)						
		{
			d+=x;
			y+=x;
			m+=x;
			T+=x;
		}
		else if ( V[0]==s[0] && V[1]==s[1] )
		{
			m+=x;
			y+=x;
			T+=x;
		}
		else if( strcmp(V+strlen(V)-4, s+strlen(s)-4) == 0 )
		{
			y+=x;
			T+=x;
		}
    	else{
    		T+=x;
		}
	}
	cout<<"\n\t\t\tProfit:\t";
	cout<<"\n\t\t\tDay:\t\t"<<d;
	cout<<"\n\t\t\tMonth:\t\t"<<m;
	cout<<"\n\t\t\tYear:\t\t"<<y;
	cout<<"\n\t\t\tTotal:\t\t"<<T;
	getche();
}
int main()
{	


   while(1)
   { 
   int N;
   system("cls");
   cout<<"\n\n\t\t1.create list\n\t\t2.Display Menu\n\t\t3.Profit\n\t\t4.exit\n\t\t\t";
   cin>>N;
   		switch(N)
 	  {
   
    		case 1:Create();
  				break; 
	
			case 2: Display();
				Bill();
				break;
    
			case 3: Word();
    			break;
    
			case 4: exit(0);
    
			default:		
				cout<<"";
		}
	}
    return 0;

}
