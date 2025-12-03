#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk Tempat Tanggal Lahir
struct TTL {
    char tempatLahir[51];
    int tanggalLahir;
    char bulanLahir[11];
    int tahunLahir;
    int usia;
};

// Struktur untuk Alamat
struct ALAMAT {
    char namaJalan[101];
    char namaKota[51];
    char kodePos[11];
    char provinsi[31];
};

// Struktur utama Mahasiswa
struct infoMhs {
    char nimMhs[11];
    char namaMhs[41];
    char genderMhs[21];
    struct TTL ttl;
    struct ALAMAT alamat;
    float gpaMhs;
};

// Variabel global untuk array dinamis mahasiswa
struct infoMhs *mahasiswa = NULL;
int storage = 2;   // kapasitas awal
int idx = 0;       // jumlah data mahasiswa saat ini

// 1. Fungsi untuk menambah data mahasiswa
void tambahMhs() {
    // Jika belum ada alokasi, buat array awal
    if (mahasiswa == NULL) {
        mahasiswa = malloc(storage * sizeof(struct infoMhs));
    } 
    // Jika penuh, gandakan kapasitas
    else if (idx == storage) {
        storage *= 2;
        mahasiswa = realloc(mahasiswa, storage * sizeof(struct infoMhs));
    }

    // Input data mahasiswa
    printf("\n===== MENU TAMBAH DATA MAHASISWA =====\n");
    printf("Masukkan NIM: ");
    scanf("%s", mahasiswa[idx].nimMhs);

    printf("Masukkan Nama: ");
    scanf(" %[^\n]", mahasiswa[idx].namaMhs);

    printf("Masukkan Jenis Kelamin: ");
    scanf(" %[^\n]", mahasiswa[idx].genderMhs);

    printf("Tempat Lahir: ");
    scanf(" %[^\n]", mahasiswa[idx].ttl.tempatLahir);
    printf("Tanggal Lahir (Angka): ");
    scanf("%d", &mahasiswa[idx].ttl.tanggalLahir);
    printf("Bulan Lahir (Huruf): ");
    scanf(" %[^\n]", mahasiswa[idx].ttl.bulanLahir);
    printf("Tahun Lahir (Angka): ");
    scanf("%d", &mahasiswa[idx].ttl.tahunLahir);
    printf("Usia Saat Ini: ");
    scanf("%d", &mahasiswa[idx].ttl.usia);

    printf("Nama Jalan: ");
    scanf(" %[^\n]", mahasiswa[idx].alamat.namaJalan);
    printf("Nama Kota: ");
    scanf(" %[^\n]", mahasiswa[idx].alamat.namaKota);
    printf("Kode Pos: ");
    scanf("%s", mahasiswa[idx].alamat.kodePos);
    printf("Provinsi: ");
    scanf(" %[^\n]", mahasiswa[idx].alamat.provinsi);

    printf("GPA Mahasiswa: ");
    scanf("%f", &mahasiswa[idx].gpaMhs);

    idx++; // Tambah jumlah data
    printf("DATA TELAH BERHASIL DITAMBAHKAN!\n\n");
}

// 2. Fungsi untuk mengupdate data mahasiswa
void updateMhs() {
    if (idx == 0) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }

    int updateData;
    printf("Data mahasiswa keberapa yang ingin diubah (1-%d)? ", idx);
    scanf("%d", &updateData);
    updateData--;

    // Validasi input
    if (updateData < 0 || updateData >= idx) {
        printf("Nomor data tidak valid.\n");
        return;
    }

    // Input data baru
    printf("\n===== MASUKKAN DATA BARU =====\n");
    printf("Masukkan NIM: ");
    scanf("%s", mahasiswa[updateData].nimMhs);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", mahasiswa[updateData].namaMhs);
    printf("Masukkan Jenis Kelamin: ");
    scanf(" %[^\n]", mahasiswa[updateData].genderMhs);

    printf("Tempat Lahir: ");
    scanf(" %[^\n]", mahasiswa[updateData].ttl.tempatLahir);
    printf("Tanggal Lahir: ");
    scanf("%d", &mahasiswa[updateData].ttl.tanggalLahir);
    printf("Bulan Lahir: ");
    scanf(" %[^\n]", mahasiswa[updateData].ttl.bulanLahir);
    printf("Tahun Lahir: ");
    scanf("%d", &mahasiswa[updateData].ttl.tahunLahir);
    printf("Usia: ");
    scanf("%d", &mahasiswa[updateData].ttl.usia);

    printf("Nama Jalan: ");
    scanf(" %[^\n]", mahasiswa[updateData].alamat.namaJalan);
    printf("Nama Kota: ");
    scanf(" %[^\n]", mahasiswa[updateData].alamat.namaKota);
    printf("Kode Pos: ");
    scanf("%s", mahasiswa[updateData].alamat.kodePos);
    printf("Provinsi: ");
    scanf(" %[^\n]", mahasiswa[updateData].alamat.provinsi);

    printf("GPA: ");
    scanf("%f", &mahasiswa[updateData].gpaMhs);

    printf("DATA MAHASISWA KE-%d BERHASIL DIUPDATE!\n\n", updateData + 1);
}

// 3. Fungsi untuk menampilkan semua data mahasiswa
void listMhs() {
    if (idx == 0) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }
    for (int i = 0; i < idx; i++) {
        printf("\nDATA MAHASISWA-%d\n", i + 1);
        printf("NIM: %s\n", mahasiswa[i].nimMhs);
        printf("Nama: %s\n", mahasiswa[i].namaMhs);
        printf("Gender: %s\n", mahasiswa[i].genderMhs);
        printf("TTL: %d %s %d, %s\n", mahasiswa[i].ttl.tanggalLahir,
               mahasiswa[i].ttl.bulanLahir, mahasiswa[i].ttl.tahunLahir,
               mahasiswa[i].ttl.tempatLahir);
        printf("Usia: %d\n", mahasiswa[i].ttl.usia);
        printf("Alamat: %s, %s, %s, %s\n", mahasiswa[i].alamat.namaJalan,
               mahasiswa[i].alamat.namaKota, mahasiswa[i].alamat.kodePos,
               mahasiswa[i].alamat.provinsi);
        printf("GPA: %.2f\n", mahasiswa[i].gpaMhs);
    }
}

// 4. Fungsi untuk menghapus data mahasiswa
void deleteMhs() {
    if (idx == 0) {
        printf("Tidak ada data untuk dihapus.\n");
        return;
    }

    int num;
    printf("Data mahasiswa keberapa yang ingin dihapus (1-%d)? ", idx);
    scanf("%d", &num);
    num--;

    if (num < 0 || num >= idx) {
        printf("Nomor data tidak valid.\n");
        return;
    }

    // Geser data ke kiri untuk menimpa data yang dihapus
    memmove(&mahasiswa[num], &mahasiswa[num + 1], (idx - num - 1) * sizeof(struct infoMhs));
    idx--;
    printf("Data mahasiswa ke-%d berhasil dihapus!\n\n", num + 1);
}

// 5. Fungsi utama (main program)
int main() {
    int choice;
    do {
        printf("\n===== MENU DATA MAHASISWA =====\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Update Mahasiswa\n");
        printf("3. List Mahasiswa\n");
        printf("4. Delete Mahasiswa\n");
        printf("5. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: tambahMhs(); break;
            case 2: updateMhs(); break;
            case 3: listMhs(); break;
            case 4: deleteMhs(); break;
            case 5: printf("Bye...\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (choice != 5);

    free(mahasiswa); // bebaskan memori
    return 0;
}
