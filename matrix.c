/// Matrix calculator
#include <stdio.h>
#include <stdlib.h>

int determinant(int matrixArray[10][10]){
	//
    return 0;
}

void printMatrix(int row, int col, int matrixArray[10][10])
{

	int i = 0;
	int rowCount = 0;
	for(i = 0; i < row*col; i++)
	{
		if(i%row == 0)
			rowCount++;
        if(i%row == 0 && i != 0)
            printf("\n");
		printf("%d ", matrixArray[i][rowCount]);

	}
	return;
}

int getMatrix()
{
	int m = 0, n = 0, i = 0, rowCount = 0;
	int matrixArray[10][10] = {0};

	printf("What is your matrix size? Enter two numbers n x m. \nFor example a 2 x 2 matrix can be entered as 2 2.");
	scanf("%d %d", &n, &m);

	printf("Please enter your matrix\n");

	for(i = 0; i < n*m; i++)
	{
		if(i%n == 0)
			rowCount++;
		scanf("%d", &matrixArray[i][rowCount]);
		printMatrix(n,m, matrixArray);
	}

	printf("\nIs this matrix correct? Enter yes/no\n");
        printMatrix(n,m,matrixArray);
    char choice = "";
    scanf("%d",choice);
    if(choice == "yes")
        determinant();
    else
    {
        printf("\nPlease re-enter Matrix");
        //clear matrix
        getMatrix();
    }

	return 0;
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
			printf("Not yet complete");
			break;
		}
	}

	return 0;
}

