#include <stdio.h>

int main() {
	int rows, cols;
	int outdegree = 0;
	int indegree = 0;
	printf("Enter the rows and cols: ");
	scanf("%d %d",&rows,&cols);

	int arr[rows][cols];

	printf("\n\nInput 2D Matrix Elements\n");
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("Enter elements: %d %d:\t",i,j);
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}

	printf("2D Array Elements:\n");
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nFinding Indegree and Outdegree!\n");
	for(int i =0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			outdegree = outdegree + arr[i][j];
			indegree = indegree + arr[j][i];
		}

		printf("Outdegree: %d, Indegree: %d\n",outdegree,indegree);
	}

	return 0;
}
