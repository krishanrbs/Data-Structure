/* DELETING  FROM A LINEAR ARRAY AT SPECIFIED POSITION */
/*Program Created by Dr. K. K. Goyal (Associate Professor and Dean, Faculty of Computer Application, RBSMTC, Agra.)*/
/* ARRAY_D.C */

# include<stdio.h>

# define s 20 // DEFINE FOR SIZE OF ARRAY

char employ[s][s];
int delete_array(char employ[s][s], int, int, char *);
void input(char emply[s][s], int );
void display(char employ[s][s], int );

/* Definition of the function */

int delete_array(char employ[s][s], int number, int position, char element[])
{
	int temp = position,i;
	element = employ[position];
       printf("\n Information which we have to delete: %s", element);
     while( temp <= number-1)
	{
	        for(i=0;i<s;i++)
		        employ [temp][i] = employ[temp+1][i];
                    temp ++;
	}
	number = number - 1 ;

	return(number);

}

void input(char employ[s][s], int number)
{
	int i;
	for(i = 1; i<= number ; i++)
	{
		fflush(stdin);
		printf("\n Input value for: %d: ", i);
		gets(employ[i]);
	}
}

void display(char employ[s][s], int number)
{ 
	int i;
	for(i = 1; i<= number; i++)
	{
		printf("\n Value at the position: %d: %s", i, employ[i]);
	}
}

/* main function */

main()
{
	
	int number;
	int position;
	char element[s];

	printf("\n Input the number of elements in the array:");
	scanf("%d", &number);
	fflush(stdin);
	input(employ, number);
	printf("\n Entered list is as follows:\n");

	display(employ, number);
	fflush(stdin);
	printf("\n Input the position from where you want delete an element:");
	scanf("%d", &position);

	number = delete_array(employ, number, position, element);
	display(employ,number);
	getch();
}

