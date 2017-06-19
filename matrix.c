/// Matrix calculator
/// Matthew Taubler
#include <stdio.h>
#include <stdlib.h>

int determinant(int n, int m[10][10])
{
	printf("Thanks\n");
	return 0; 
}


void printMatrix(int n, int matrixArray[10][10])
{

	int i = 0, j= 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d ", matrixArray[i][j]);
		printf("\n");
	}
	return;
}


int getMatrix()
{
	int n = 0, i = 0, j = 0, rowCount = 0;
	int matrixArray[10][10] = {0};
	char choice = "";

	printf("What is your matrix size? Enter a number n x n.\nFor example a 3 x 3 matrix can be entered as 3.\n");
	scanf("%d", &n);
	if(n > 10)
	{
		printf("Enter a maximum of size 10.\n");
		getMatrix();
	}

	printf("Please enter your matrix\n");

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n;j++)
		scanf("%d", &matrixArray[i][j]);
		printMatrix(n,matrixArray);
	}

	printf("\nIs this matrix correct? Enter yes/no\n");
        printMatrix(n,matrixArray);
    
    scanf("%s",choice);

    if(choice == "yes")
        determinant(n,matrixArray);
    else
    {
        printf("\nPlease re-enter Matrix\n");
        //clear matrix
    }

	return -1;
}


int main()
{

	int choice = 0;
	printf("What would you like to do?\n1.Determinant\n\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
		{
			getMatrix();
			break;
		}
		case 2:
		{
			printf("Not yet complete");
			break;
		}

		default:
		{
			printf("Please select");
			break;
		}
	}

	return 0;
}

