#include <stdio.h>

#define MAX 100

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int co_bhyt[MAX];
    int phi_kham[MAX];

    int n = 0;
    
    printf("Nh?p s? lu?ng b?nh nhân ban d?u (0 < n <= 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("S? lu?ng b?nh nhân không h?p l?!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        ma_so[i] = 202600 + i + 1; 
        
        do {
            printf("Nh?p tu?i b?nh nhân th? %d (1-120): ", i + 1);
            scanf("%d", &tuoi[i]);
            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tu?i không h?p l?. Vui lòng nh?p l?i!\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Nh?p tr?ng thái BHYT c?a b?nh nhân th? %d (0: Không, 1: Có): ", i + 1);
            scanf("%d", &co_bhyt[i]);
            if (co_bhyt[i] != 0 && co_bhyt[i] != 1) {
                printf("Tr?ng thái BHYT ch? nh?n 0 ho?c 1. Vui lòng nh?p l?i!\n");
            }
        } while (co_bhyt[i] != 0 && co_bhyt[i] != 1);

        if (co_bhyt[i] == 1) {
            phi_kham[i] = 30000;
        } else {
            phi_kham[i] = 150000;
        }
    }

    long tong_doanh_thu = 0;
    int tong_uu_tien = 0;

    printf("\n================ DANH SÁCH HÀNG CH? BAN Ð?U ================\n");
    printf("%-10s | %-8s | %-10s | %-12s | %-10s\n", "Mã s?", "Tu?i", "BHYT", "Phí khám", "Phân lo?i");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        tong_doanh_thu += phi_kham[i];
        char* phan_loai = "THU?NG";
        if (tuoi[i] >= 70) {
            tong_uu_tien++;
            phan_loai = "UU TIÊN";
        }
        printf("%-10d | %-8d | %-10d | %-12d | %-10s\n", ma_so[i], tuoi[i], co_bhyt[i], phi_kham[i], phan_loai);
    }
    printf("-------------------------------------------------------------\n");
    printf("T?ng doanh thu d? ki?n: %ld VNÐ\n", tong_doanh_thu);
    printf("T?ng s? b?nh nhân uu tiên: %d\n", tong_uu_tien);

    int k;
    printf("\nNh?p ch? s? (index) K c?a b?nh nhân mu?n h?y lu?t khám (0 d?n %d): ", n - 1);
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("L?i: V? trí K không h?p l? ho?c hàng ch? tr?ng!\n");
        return 1;
    }

    for (int i = k; i < n - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        tuoi[i] = tuoi[i + 1];
        co_bhyt[i] = co_bhyt[i + 1];
        phi_kham[i] = phi_kham[i + 1];
    }
    n--; 

    long tong_doanh_thu_moi = 0;
    int tong_uu_tien_moi = 0;

    printf("\n============ DANH SÁCH HÀNG CH? SAU KHI H?Y LU?T ============\n");
    printf("%-10s | %-8s | %-10s | %-12s | %-10s\n", "Mã s?", "Tu?i", "BHYT", "Phí khám", "Phân lo?i");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        tong_doanh_thu_moi += phi_kham[i];
        char* phan_loai = "THU?NG";
        if (tuoi[i] >= 70) {
            tong_uu_tien_moi++;
            phan_loai = "UU TIÊN";
        }
        printf("%-10d | %-8d | %-10d | %-12d | %-10s\n", ma_so[i], tuoi[i], co_bhyt[i], phi_kham[i], phan_loai);
    }
    printf("-------------------------------------------------------------\n");
    printf("T?ng doanh thu c?p nh?t m?i: %ld VNÐ\n", tong_doanh_thu_moi);
    printf("T?ng s? b?nh nhân uu tiên c?p nh?t m?i: %d\n", tong_uu_tien_moi);

    return 0;
}
