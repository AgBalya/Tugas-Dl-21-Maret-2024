#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_swaps_to_sort(char *cards, int n) {
    // Mengonversi nilai-nilai kartu ke dalam bentuk numerik
    int card_values[128];
    card_values['1'] = 1;
    card_values['2'] = 2;
    card_values['3'] = 3;
    card_values['4'] = 4;
    card_values['5'] = 5;
    card_values['6'] = 6;
    card_values['7'] = 7;
    card_values['8'] = 8;
    card_values['9'] = 9;
    card_values['J'] = 11;
    card_values['Q'] = 12;
    card_values['K'] = 13;

    // Membuat salinan kartu yang belum diurutkan
    char *sorted_cards = malloc(n * sizeof(char));
    memcpy(sorted_cards, cards, n * sizeof(char));

    // Mengurutkan kartu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (card_values[sorted_cards[j]] > card_values[sorted_cards[j + 1]]) {
                char temp = sorted_cards[j];
                sorted_cards[j] = sorted_cards[j + 1];
                sorted_cards[j + 1] = temp;

                // Menampilkan urutan kartu setiap terjadi pertukaran
                printf("Urutan kartu setelah pertukaran ke-%d: %s\n", (i * (n - 1)) + j + 1, sorted_cards);
            }
        }
    }

    // Menghitung jumlah langkah pertukaran
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (cards[i] != sorted_cards[i]) {
            swaps++;
        }
    }

    // Karena setiap pertukaran membutuhkan dua langkah
    int min_swaps = swaps / 2;

    free(sorted_cards);
    return min_swaps;
}

int main() {
    int n;
    scanf("%d", &n); // Input jumlah kartu
    char cards[n + 1];
    scanf("%s", cards); // Input nilai kartu

    // Hitung dan cetak jumlah minimal langkah pertukaran
    printf("Jumlah minimal langkah pertukaran: %d\n", min_swaps_to_sort(cards, n));

    return 0;
}
