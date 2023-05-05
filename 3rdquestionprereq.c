#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 1000

void bubble_sort(int arr[], int n) {
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i,j;
    for (i = 0; i < n-1; i++) {
        int min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}



int main() {
    int n, P, Q,i,num[size],temp;
    FILE *fp1,*fp2,*fp3,*fp4;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    printf("Enter the range of numbers (P and Q): ");
    scanf("%d %d", &P, &Q);

    Q=Q-P;

    printf("\n");
    fp1=fopen("Input.txt","w");

    for(i=0;i<n;i++)
    {
        temp=(rand()%Q);
        temp=temp+P;
        printf("%d\n",temp);
        fprintf(fp1,"%d\n",temp);
    }
    Q=P+Q;
    fclose(fp1);

    printf("%d random numbers between %d and %d written to Input.txt.\n", n, P, Q);

    clock_t start, end;
    long double time;

    fp4=fopen("log.txt","r+");
    fp2=fopen("Input.txt","r");

    for(i=0;i<n;i++)
    {
        fscanf(fp2, "%d/n", &num[i]) ;
    }
    fclose(fp2);
    fp3=fopen("Output.txt","w");
    start=clock();
    printf("After sorting\n");
    bubble_sort(num,n);
    end=clock();
    time=end-start;
    printf("time=%.20Lf\n",time);
    fprintf(fp4,"Bubble sort:       %lf\n",time);
    for(i=0;i<n;i++)
    {
        printf("%d\n",num[i]);
        fprintf(fp3,"%d\n",num[i]);
    }
    fclose(fp3);
    printf("%d random numbers between %d and %d sorted to Output.txt.\n", n, P, Q);
    start=clock();
    selection_sort(num,n);
    end=clock();
    time=end-start;
    printf("time=%.20Lf\n",time);
    fprintf(fp4,"Selection sort:       %lf\n",time);
    char buffer[100];
    fgets(buffer, 100, fp4);
    printf("File contents:\n %s", buffer);
    return 0;
}
