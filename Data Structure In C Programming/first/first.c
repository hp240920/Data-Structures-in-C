
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size)
{

    int start;
    int current;
    int temp;

    for(start = 1; start < size; start++){ // 10 4 2
        temp = arr[start];
        //printf("Temp %d\n", temp);
        for(current = start - 1; current >= 0 && temp < arr[current]; current--){
            //printf("%d I am in %d\n", arr[current + 1], arr[current]);
            arr[current + 1] = arr[current];
            //printf("%d switch to %d\n", arr[current + 1], arr[current]);
        }
        arr[current + 1] = temp; // plus 1 because after for loop current is decrease by 1
        /*
        printf("Print  %d\n", current);
        for(int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        */
        //break;
    }
}

void reverseArray(int arr[], int size){
    int temp;
    for(int i = 0; i < size/2; i++){
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main(int argc, char* argv[])
{
    FILE *txtReader = fopen(argv[1], "r");
    if (txtReader == NULL) {
        printf("error\n");
        return 0;
    }
    int sizeArr;
    fscanf(txtReader, "%d", &sizeArr);
    //printf("%d\n", sizeArr);

    int arr[sizeArr];

    for(int i = 0; i < sizeArr; i++){
        fscanf(txtReader, "%d", &arr[i]); // at the address of arr[i] put the value of d.
    }

    fclose(txtReader);
    /*
    while (fscanf(txtReader, "%d", &x) == 1) {
        printf("Got value %d\n", x);
    }
    */
    //int arr[] = {5, 4, 3, 2, 1};
    int evenCounter = 0;
    int oddCounter = 0;
    for (size_t i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        if (arr[i]%2 == 0){
            evenCounter++;
            continue;
        }
        oddCounter++;
    }

    //printf("Number of even numbers is %d.\n", evenCounter);
    //printf("Number of odd numbers is %d.\n", oddCounter);

    int arrE[evenCounter];
    int trackE = 0;
    int arrO[oddCounter];
    int trackO = 0;

    for (size_t i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        if(arr[i]%2 == 0){
            arrE[trackE] = arr[i];
            trackE++;
            continue;
        }
        if(arr[i]%2 != 0){
            arrO[trackO] = arr[i];
            trackO++;
        }
    }
    /*
    printf("Even Numbers: ");
    for (size_t i = 0; i < (sizeof(arrE)/sizeof(arrE[0])); i++){
        printf("%d ", arrE[i]);
    }
    printf("\n\n");
    printf("Odd Numbers: ");
    for (size_t i = 0; i < (sizeof(arrO)/sizeof(arrO[0])); i++){
        printf("%d ", arrO[i]);
    }
    printf("\n\n");
    */
    sort(arrE, (sizeof(arrE)/sizeof(arrE[0])));
    sort(arrO, (sizeof(arrO)/sizeof(arrO[0])));
    reverseArray(arrO, (sizeof(arrO)/sizeof(arrO[0])));
    /*
    printf("Final: ");
    for (size_t i = 0; i < (sizeof(arrE)/sizeof(arrE[0])); i++){
        printf("%d ", arrE[i]);
    }
    for (size_t i = 0; i < (sizeof(arrO)/sizeof(arrO[0])); i++){
        printf("%d ", arrO[i]);
    }
    printf("\n");
    */
    int sizeE = sizeof(arrE)/sizeof(arrE[0]);
    int sizeO = sizeof(arrO)/sizeof(arrO[0]);
    int sum = sizeE + sizeO;
    int finalArr[sum];

    for(int i = 0; i < sizeE; i++){
        finalArr[i] = arrE[i];
    }
    int counter = 0;
    for(int i = sizeE; i < sum; i++){
        finalArr[i] = arrO[counter];
        counter++;
    }

    //printf("Final: ");
    for(int i = 0; i < sum; i++){
        printf("%d\t", finalArr[i]);
    }
    //printf("2\t4\t5\t3\t1\n");
    //printf("\n");
    //printf("%d\n", finalArr[4]);
    return 0;
}
