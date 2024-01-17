#include <stdio.h>
#include <stdlib.h>

void nhapmt(int *p, int m, int n);
void inmt(int *p, int m, int n);
float tinhsole(int *p, int m, int n);
int GTLN(int *p, int m, int n);
void ghivaotep(int *p, int m, int n);
void docvaghi(int *p, int m, int n);

int main() {
    int *p;
    int m, n;
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("\nNhap so cot: ");
    scanf("%d", &n);

    p = (int *)malloc(n * m * sizeof(int));

    nhapmt(p, m, n);
    inmt(p, m, n);

    // Thêm các chức năng khác tại đây
    float trungBinhLe = tinhsole(p, m, n);
    printf("Trung binh cong cac so le cua ma tran: %.2f\n", trungBinhLe);

    int maxCot0 = GTLN(p, m, n);
    printf("Gia tri lon nhat tren cot 0 cua ma tran: %d\n", maxCot0);

    ghivaotep(p, m, n);

    printf("Du lieu tu tep matran.txt:\n");
    docvaghi(p, m, n);

    free(p);

    return 0;
}

void nhapmt(int *p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("p[%d][%d] = ", i, j);
            scanf("%d", (p + i * n + j));
        }
    }
}

void inmt(int *p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
}

float tinhsole(int *p, int m, int n) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(p + i * n + j) % 2 != 0) {
                sum += *(p + i * n + j);
                cnt += 1;
            }
        }
    }
    if (cnt > 0) {
        return (float)sum / cnt;
    } else {
        return 0.0;
    }
}

int GTLN(int *p, int m, int n) {
    int max = *(p);
    for (int i = 0; i < m; i++) {
        if (*(p + i * n) > max) {
            max = *(p + i * n);
        }
    }
    return max;
}

void ghivaotep(int *p, int m, int n) {
    FILE *file = fopen("matran.txt", "w");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(p + i * n + j) < 100) {
                fprintf(file, "%d ", *(p + i * n + j));
            }
        }
    }
    fclose(file);
}

void docvaghi(int *p, int m, int n) {
    FILE *file = fopen("matran.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep matran.txt\n");
        return;
    }
    int value;
    printf("Du lieu tep matran.txt:\n");
    while (fscanf(file, "%d", &value) != EOF) {
        printf("%d ", value);
    }
    fclose(file);
}
