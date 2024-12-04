#include <stdio.h>

int main() {
    int arr[100], n = 0, choice, value, i, j;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. In ra gia tri lon nhat\n");
        printf("4. Them mot phan tu\n");
        printf("5. Xoa mot phan tu\n");
        printf("6. Sap xep mang\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Nhap gia tri phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        } 
        else if (choice == 2) {
            printf("Gia tri cac phan tu: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (choice == 3) {
            int max = arr[0];
            for (i = 1; i < n; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            printf("Gia tri lon nhat la: %d\n", max);
        } 
        else if (choice == 4) {
            printf("Nhap gia tri phan tu can them: ");
            scanf("%d", &value);
            arr[n] = value;
            n++;
            printf("Phan tu %d da duoc them.\n", value);
        } 
        else if (choice == 5) {
            printf("Nhap gia tri phan tu can xoa: ");
            scanf("%d", &value);
            int found = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] == value) {
                    for (j = i; j < n - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    n--;
                    found = 1;
                    printf("Phan tu %d da duoc xoa.\n", value);
                    break;
                }
            }
            if (!found) {
                printf("Phan tu khong tim thay.\n");
            }
        } 
        else if (choice == 6) {
            for (i = 0; i < n - 1; i++) {
                for (j = i + 1; j < n; j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Mang sau khi sap xep: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (choice == 7) {
            printf("Nhap gia tri phan tu can tim: ");
            scanf("%d", &value);
            int found = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] == value) {
                    printf("Phan tu %d tim thay tai vi tri %d\n", value, i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Khong tim thay phan tu %d.\n", value);
            }
        } 
        else if (choice == 8) {
            printf("Thoat chuong trinh.\n");
            break;
        } 
        else {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

