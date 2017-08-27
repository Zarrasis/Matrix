/// Matrix calculator
/// Matthew Taubler
#include <stdio.h>
#include <stdlib.h>

// n is size of current matrix, m is matrix, i is a counter for row expansion position
int determinant(int n, int m[10][10], int i){
	//printf("%d", m[0][0]);
	if(n==1)
		return m[0][0];
	if(n==2)
		return m[0][0]*m[1][1] - m[1][0]*m[0][1];
	if(i < n)
		return m[0][i]*reduceMatrix(m,i,0,n) + determinant(n,m,i+1);
	return;
}


int reduceMatrix(int m[10][10], int col, int row, int n){
	removeCol(m, col, n, n);
	removeRow(m, row, n);
	return determinant(n-1,m,0); 
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

int add(int m[10][10], int m2[10][10], int w, int h)
{	
	int i = 0, j = 0; 
	for(i = 0; i < w; i++)
	{
		for(j = 0; j < h; j++)
		{
			m[i][j] += m2[i][j];
		}
	}
	return m; 
}

int sub(int m[10][10], int m2[10][10], int w, int h)
{	
	int i = 0, j = 0; 
	for(i = 0; i < w; i++)
	{
		for(j = 0; j < h; j++)
		{
			m[i][j] -= m2[i][j];
		}
	}
	return m; 
}

void getMatrix(){

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

	// TODO add check
	printf("\nIs this matrix correct? Enter yes/no\n");
        printMatrix(n,matrixArray);

    return m; 
    
}

// void getRotMatrix(){

// 	int i = 0;
// 	int matrix[3]
// 	printf("Your matrix should be a 1x3 matrix, please enter it now. \n");
// 	for(i = 0; i < 3; i++)
// 		scanf("%d", &matrix[i]);
// 	rotate(matrix);
// 	printMatrix(3, matrix);
// }

// void rotate(int** matrix){
	
// 	// inc
// 	return;
// }


int main(){
	int m[10][10] = {0};
	int det = 0;
	int choice = 0;
	printf("What would you like to do?\n1.Determinant\n2.Rotation About Z for pi/4\n3.Add Matrix\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
		{
			m = getMatrix();
			det = determinant(m);
			printf("%d", det);
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

