#include <stdio.h>
#include <stdlib.h>

int nhapMaTran(int arr[100][100], int *n, int *m) {
    printf("Nhap so hang: ");
    scanf("%d", n);
    printf("Nhap so cot: ");
    scanf("%d", m);
    printf("Nhap gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}

int inMaTran(int arr[100][100], int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int inDuongBienVaTinhTich(int arr[100][100], int n, int m) {
    int tich = 1;
    printf("Phan tu tren duong bien:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                printf("%d ", arr[i][j]);
                tich *= arr[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %d\n", tich);
    return 0;
}

int inDuongCheoChinh(int arr[100][100], int n, int m) {
    if (n != m) {
        printf("Ma tran khong phai la ma tran vuong.\n");
        return 0;
    }
    printf("Phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
    return 0;
}

int inDuongCheoPhu(int arr[100][100], int n, int m) {
    if (n != m) {
        printf("Ma tran khong phai la ma tran vuong.\n");
        return 0;
    }
    printf("Phan tu tren duong cheo phu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][m-i-1]);
    }
    printf("\n");
    return 0;
}

int sapXepDuongCheoChinh(int arr[100][100], int n, int m) {
    if (n != m) {
        printf("Ma tran khong phai la ma tran vuong.\n");
        return 0;
    }
    int temp[100], size = n;
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i][i];
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i][i] = temp[i];
    }
    printf("Duong cheo chinh sau khi sap xep tang dan:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
    return 0;
}

int timKiemPhanTu(int arr[100][100], int n, int m) {
    int x, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    printf("Phan tu %d xuat hien tai cac vi tri: ", x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == x) {
                printf("(%d, %d) ", i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong tim thay.\n");
    } else {
        printf("\n");
    }
    return 0;
}

int main() {
    int arr[100][100], n = 0, m = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMaTran(arr, &n, &m);
                break;
            case 2:
                inMaTran(arr, n, m);
                break;
            case 3:
                inDuongBienVaTinhTich(arr, n, m);
                break;
            case 4:
                inDuongCheoChinh(arr, n, m);
                break;
            case 5:
                inDuongCheoPhu(arr, n, m);
                break;
            case 6:
                sapXepDuongCheoChinh(arr, n, m);
                break;
            case 7:
                timKiemPhanTu(arr, n, m);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}

