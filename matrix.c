/// Matrix calculator
/// Matthew Taubler
#include <stdio.h>
#include <stdlib.h>

int determinant(int n, int m[10][10], int i){
	printf("%d", &m[0][0]);
	if(n==1)
		return m[0][0];
	if(n==2)
		return m[0][0]*m[1][1] - m[1][0]*m[0][1];
	if(i<n)
		return m[0][i]*reduceMatrix(m,i,0,n) + determinant(n,m,i+1);
}


int reduceMatrix(int m[10][10], int col, int row, int n){
	removeCol(m, col, n, n);
	removeRow(m, row, n);
	return m; 
}


void removeCol(int** m, int col, int h, int w){

	w--;
	int i = 0;
	for(i = 0; i < h; i++)
	{
		while(col < w)
		{
			m[i][col] = m[i][col+1];
			col++;
		}
	}
	m[i] = realloc(m[i], sizeof(double)*w);
}

void removeRow(int** m, int row, int h){

	h--;
	free(m[row]);
	while(row<h)
	{
		m[row] = m[row+1];
		row++; 
	}
}

void printMatrix(int n, int matrixArray[10][10]){

	int i = 0, j= 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d ", matrixArray[i][j]);
		printf("\n");
	}
	return;
}


void getMatrix(){

	int n = 0, i = 0, j = 0, rowCount = 0;
	int matrixArray[10][10] = {0};
	int det = 0; 
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
    
    printf("Whatever we are doing it anyways.\n");   
   	det = determinant(n, matrixArray, 0);
   	printf("%d", &det);

    //scanf("%s",choice);

   // if(choice == "yes")
   //{
    	//det = determinant(n,matrixArray,0);
      //  printf("%d", &det);
   // }
   // else
  //  {
   //     printf("\nPlease re-enter Matrix\n");
        //clear matrix
  //  }

	return;
}


int main(){

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

