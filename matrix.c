/// Matrix calculator
#include <stdio.h>
#include <stdlib.h>

int determinant(){
    return 0;
}

int getMatrix()
{
	printf("What is your matrix size? Enter two numbers n x m. \nFor example a 2x2 matrix can be entered as 2 2.");
	int m = 0;
	int n = 0;
	scanf("%d, %d", n, m);
	int matrixArray[n][m];


int main()
{

	int choice = 0;
	printf("What would you like to do?\n1.Determinant\n\n");
	switch(choice)
	{
		case 1:
		{
			getMatrix();
			determinant();
			break;
		}
		case 2:
		{
			printf("Not yet complete")
		}
	}

	


	return 0;
}

