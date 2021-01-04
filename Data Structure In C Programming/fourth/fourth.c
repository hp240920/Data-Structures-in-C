#include <stdio.h>
#include <stdlib.h>

void printArray(int a, int b, int** arr){
    //printf("hey \n");
    int row = a;
    //printf("Row: %d\n", row);
    int column = b;
    //printf("Column: %d\n", column);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    /*
    int arr1[2][3] = {{1 , 2, 3} , {4, 5, 6}};
    int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int r1 = 2;
    int c1 = 3;
    int r2 = 3;
    int c2 = 2;
    int count = 0;
    int index1 = 0;
    int index2 = 0;
    int product = 0;
    int sum = 0;
    */
    if(argc < 2){
      printf("error\n");
      return 0;
    }
    FILE *textR = fopen(argv[1], "r");
    if(textR == NULL){
      printf("error\n");
      return 0;
    }
    int first;
    int second;
    fscanf(textR, "%d\t%d", &first, &second);
    //printf("%d\t%d\n", first, second);
    //int a1[first][second];
    int **a1 = (int **)malloc(first * sizeof(int *));
    for(int i = 0; i < first; i++){
        a1[i] = (int *)malloc(second * sizeof(int));
    }
    //count = 0;
    for(int i = 0; i < first; i++){
        for(int j =0; j < second; j++){
            int num;
            fscanf(textR, "%d", &num);
            a1[i][j] = num;
        }
    }
    //int row = sizeof(a1)/sizeof(a1[0]);
    //int column = sizeof(a1[0])/sizeof(a1[0][0]);
    // printArray(first, second, a1);

    int first2;
    int second2;
    fscanf(textR, "%d\t%d", &first2, &second2);
    //printf("%d\t%d\n", first2, second2);
    //int a2[first2][second2];
    int **a2 = (int **)malloc(first2 * sizeof(int *));
    //printf("HEY");
    for(int i = 0; i < first2; i++){
        a2[i] = (int *)malloc(second2 * sizeof(int));
    }
    for(int i = 0; i < first2; i++){
        for(int j =0; j < second2; j++){
            int num;
            fscanf(textR, "%d", &num);
            a2[i][j] = num;
        }
    }
    fclose(textR);
    //printArray(first2, second2, a2);
// when you take a address of int* gives you int**
// input file is done here. Multiplication starts here...............................
    if(second != first2){
        printf("bad-matrices\n");
        //return 0;
    }else{
      int **returnArray = (int **)malloc(first * sizeof(int *));
    for(int i = 0; i < first; i++){
        returnArray[i] = (int *)malloc(second2 * sizeof(int));
    }
    //int returnArray[first][second2];
    for(int i = 0 ; i < first; i++){
      //printf("First\n");
        for(int j = 0; j < second2; j++){ // second
	  //printf("Second\n");
            returnArray[i][j] = 0;
            for(int c = 0; c < first2; c++){
	      //    printf("Third\n");
                returnArray[i][j] += a1[i][c]*a2[c][j];
                // i remain constant until the outer loop increment
                // c goes on until number of columns in first matrix and number of rows in second matrix
                // returnArray solve 00 01 10 11...
            }
	    // printf("Hey: %d\n", returnArray[i][j]);
        }
    }
    printArray(first, second2, returnArray);
    for(int i = 0; i < first; i++){
        free(returnArray[i]);
    }
    free(returnArray);
    }
    
    /*
    while(count < 4){
        for(int i = 0; i < c1; i++){
            product = arr1[i][index1]*arr2[index2][i];
            sum += product;
        }
        returnArray[index1][index2] = sum;
        if(index2 < c2){
            index2++;
        }
        if(index2 == (c2 - 1)){
            index1++;
            index2 = 0;
        }
        count++;
    }*/
    for(int i = 0; i < first; i++){
        free(a1[i]);
    }
    free(a1);
    for(int i = 0; i < first2; i++){
        free(a2[i]);
    }
    free(a2);
    return 0;
}

