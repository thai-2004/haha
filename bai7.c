#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void nhapmang(int *pa, int n){
    for(int i = 0; i < n; i ++){
        scanf("%d", pa + i);
    }
}
void hienthi(int *pa, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(pa + i));
    }
}

void in(int *pa, int n){
    for(int i = 0; i < n; i ++){
        if(*(pa + i) % 3 == 0 && *(pa + i) < 50){
            printf("%d ", *(pa + i));
        }
    }
}

void them(int *pa, int n, int x, int k){
    int *newpa = (int*)mahlloc((n+1)*sizeof(int));
    for(int i = 0; i < k; i ++){
        newpa[i] = (*pa + i);
    }
    newpa[k] = x;
    for(int i = k; i < n; i ++){
        newpa[i + i] = *(pa + i);
    }
    free(*newpa);
    *pa = newpa;
    (*pa)++;
}
int main(){
    int *pa, n, a[1000];
    scanf("%d", &n);
    pa = (int*)malloc(n*sizeof(int));

}