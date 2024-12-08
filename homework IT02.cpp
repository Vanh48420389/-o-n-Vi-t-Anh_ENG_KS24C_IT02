#include<stdio.h>
int main() {
    int arr[100];
    int Index = 0;
    int choice;
	int demHoanHao = 0;
	int demNguyenTo = 0;
	int docNhat[100], docNhatSoLuong = 0, trungLap = 0;
	int foundIndex;
	int found = 0;
	int left = 0;
	int right =0; 
    int mid; 
    int chan[100], le[100], soChan = 0, soLe = 0;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang (mang[0]=..., mang[1]=...)\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (Khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (Khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Moi ban nhap lua chon : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong phan tu (toi da 100): ");
                scanf("%d", &Index);
                if (Index <= 0 || Index > 100) {
                    printf("So luong khong hop le!\n");
                    Index = 0;
                } else {
                    for (int i = 0; i < Index; i++) {
                        printf("Nhap gia tri cho mang[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;

            case 2:
                if (Index == 0) {
                    printf("Mang dang khong co phan tu!\n");
                } else {
                    printf("Mang hien tai: ");
                    for (int i = 0; i < Index; i++) {
                        printf("mang[%d]=%d ", i, arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                for (int i = 0; i < Index; i++) {
                    int tongUoc = 0;
                    for (int j = 1; j <= arr[i] / 2; j++) {
                        if (arr[i] % j == 0) tongUoc += j;
                    }
                    if (tongUoc == arr[i]) demHoanHao++;
                }
                printf("So luong so hoan hao: %d\n", demHoanHao);
                break;

            case 4:
                
                for (int i = 0; i < Index; i++) {
                    int nguyenTo = arr[i] > 1;
                    for (int j = 2; j * j <= arr[i] && nguyenTo; j++) {
                        if (arr[i] % j == 0) nguyenTo = 0;
                    }
                    if (nguyenTo) demNguyenTo++;
                }
                printf("So luong so nguyen to: %d\n", demNguyenTo);
                break;

            case 5:
                if (Index < 2) {
                    printf("Mang phai tu 2 phan tu tro len!\n");
                } else {
                    int big_1 = arr[0], big_2 = -2147483647;
                    for (int i = 1; i < Index; i++) {
                        if (arr[i] > big_1) {
                            big_2 = big_1;
                            big_1 = arr[i];
                        } else if (arr[i] > big_2 && arr[i] < big_1) {
                            big_2 = arr[i];
                        }
                    }
                    printf("Gia tri lon thu hai: %d\n", big_2);
                }
                break;

            case 6:
                if (Index < 2) {
                    printf("Mang phai tu 2 phan tu tro len\n");
                } else {
                    int small_1 = arr[0], small_2 = 2147483647;
                    for (int i = 1; i < Index; i++) {
                        if (arr[i] < small_1) {
                            small_2 = small_1;
                            small_1 = arr[i];
                        } else if (arr[i] < small_2 && arr[i] > small_1) {
                            small_2 = arr[i];
                        }
                    }
                    printf("Gia tri nho thu hai la: %d\n", small_2);
                }
                break;

            case 7:
                if (Index >= 100) {
                    printf("Mang da day khong the them phan tu\n");
                } else {
                    int n, location;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &n);
                    printf("Nhap vi tri can them (0-%d): ", Index);
                    scanf("%d", &location);
                    if (location < 0 || location > Index) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = Index; i > location; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[location] = n;
                        Index++;
                        printf("Da them %d vao vi tri %d.\n",n, location);
                    }
                }
                break;

            case 8:
                if (Index == 0) {
                    printf("Mang dang khong co phan tu\n");
                } else {
                    int viTriXoa;
                    printf("Nhap vi tri can xoa (0-%d): ", Index - 1);
                    scanf("%d", &viTriXoa);
                    if (viTriXoa < 0 || viTriXoa >= Index) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = viTriXoa; i < Index - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        Index--;
                        printf("Da xoa phan tu tai vi tri %d.\n", viTriXoa);
                    }
                }
                break;

            case 9:
                for (int i = 1; i < Index; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep tang dan.\n");
                break;

            case 10:
                for (int i = 1; i < Index; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep giam dan.\n");
                break;

            case 11:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &foundIndex);
                right = Index - 1;
                while ( left <= right) {
                    mid = (left + right) / 2;
                    if (arr[mid] == foundIndex) {
                        printf("Tim thay %d tai vi tri %d.\n",foundIndex, mid);
                        found = 1;
                        break;
                    }
                    if (arr[mid] <foundIndex) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("%d khong ton tai trong mang.\n",foundIndex);
                }
                break;

            case 12:
                for (int i = 0; i < Index; i++) {
                    for (int j = 0; j < docNhatSoLuong; j++) {
                        if (arr[i] == docNhat[j]) {
                            trungLap = 1;
                            break;
                        }
                    }
                    if (!trungLap) {
                        docNhat[docNhatSoLuong++] = arr[i];
                    }
                }
                Index = docNhatSoLuong;
                printf("Mang sau khi xoa phan tu trung lap: ");
                for (int i = 0; i < Index; i++) {
                    printf("%d ", docNhat[i]);
                }
                printf("\n");
                break;

            case 13:
                for (int i = 0; i < Index; i++) {
                    if (arr[i] % 2 == 0) {
                        chan[soChan++] = arr[i];
                    } else {
                        le[soLe++] = arr[i];
                    }
                }
                for (int i = 0; i < soChan; i++) {
                    arr[i] = chan[i];
                }
                for (int i = 0; i < soLe; i++) {
                    arr[soChan + i] = le[i];
                }
                printf("Mang sau khi sap xep so chan truoc, so le sau: ");
                for (int i = 0; i < Index; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 14:
                for (int i = 0, j = Index - 1; i < j; i++, j--) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < Index; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 15:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 15);

    return 0;
}
