#include<stdio.h>

void create_array(int n, int A[n]){
    for(int i=0;i<n;i++){
        printf("Enter the %d element of array: ",i+1);
        scanf("%d",&A[i]);
    }
}

void print_array(int n, int A[n]){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubbleSort(int n, int A[n]){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}



int main(){
    int n;
    printf("Enter the number of elementS: ");
    scanf("%d",&n);
    int A[n];
    create_array(n,A);
    print_array(n,A);
    bubbleSort(n,A);
    print_array(n,A);
    return 0;
}