#include "music.h"

Playlist playlist;
FavoriteList favoriteList;

void menuAdmin() {
    int pilih;
    string id;

    while (true) {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Lihat Library\n";
        cout << "3. Edit Lagu\n";
        cout << "4. Hapus Lagu\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string id, judul, artist, genre;
            int durasi;
            cout << "ID: "; cin >> id;
            if (findSong(libraryHead, id) != nullptr) {
                cout << "ID sudah digunakan! Gunakan ID lain.\n";
                continue;
            }
            cout << "Judul: ";
            cin.ignore();
            getline(cin, judul);

            cout << "Artist: ";
            getline(cin, artist);

            cout << "Genre: ";
            getline(cin, genre);

            cout << "Durasi: "; cin >> durasi;

            addSong(libraryHead, createSong(id, judul, artist, genre, durasi));
        }
        else if (pilih == 2)
            printLibrary(libraryHead);

        else if (pilih == 3) {
            cout << "Masukkan ID lagu: ";
            cin >> id;
            editSong(libraryHead, id);
        }
        else if (pilih == 4) {
            cout << "Masukkan ID lagu: ";
            cin >> id;

            SongNode* target = findSong(libraryHead, id);

            if (target) {
                removeFromPlaylist(playlist, target);
                removeFromFavorite(favoriteList, target);
                deleteSong(libraryHead, id);
                cout << "Lagu berhasil dihapus dari library, playlist, dan favorit!\n";
            } else {
                cout << "Lagu tidak ditemukan!\n";
            }
        }
        else break;
    }
}

void menuUser() {
    int pilih;
    string id;

    SongNode* current = libraryHead;

    while (true) {
        cout << "\n=== MENU USER ===\n";
        cout << "1. Cari Lagu\n";
        cout << "2. Play Lagu\n";
        cout << "3. Stop Lagu\n";
        cout << "4. Next Lagu\n";
        cout << "5. Prev Lagu\n";
        cout << "6. Tambah ke Playlist\n";
        cout << "7. Lihat Playlist\n";
        cout << "8. Hapus dari Playlist \n";
        cout << "9. Tambah ke Favorit \n";
        cout << "10. Lihat Favorit \n";
        cout << "11. Hapus dari Favorit \n";
        cout << "12. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int pilihCari;
            cout << "Cari berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> pilihCari;

            if (pilihCari == 1) {
                string id;
                cout << "Masukkan ID: ";
                cin >> id;
                SongNode* s = findSong(libraryHead, id);
                if (s)
                    cout << "Ditemukan: " << s->judul << " - " << s->artist << endl;
                else
                    cout << "Lagu tidak ditemukan!\n";
            }
            else if (pilihCari == 2) {
                string title;
                cout << "Masukkan Judul: ";
                cin.ignore();
                getline(cin, title);

                SongNode* s = findSongByTitle(libraryHead, title);
                if (s)
                    cout << "Ditemukan: " << s->judul << " - " << s->artist << endl;
                else
                    cout << "Lagu tidak ditemukan!\n";
            }
        }
        else if (pilih == 2) {
        int pilihPlay;
            cout << "Play berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> pilihPlay;

            if (pilihPlay == 1) {
                string id;
                cout << "Masukkan ID lagu: ";
                cin >> id;
                SongNode* s = findSong(libraryHead, id);
                if (s) playSong(s);
                else cout << "Lagu tidak ditemukan!\n";
            }
            else if (pilihPlay == 2) {
                string title;
                cout << "Masukkan Judul lagu: ";
                cin.ignore();
                getline(cin, title);

                SongNode* s = findSongByTitle(libraryHead, title);
                if (s) playSong(s);
                else cout << "Lagu tidak ditemukan!\n";
            }
        }
        else if (pilih == 3) stopSong();
        else if (pilih == 4) {
            current = nextSong(current);
            if (current != nullptr)
                cout << "Next Lagu: " << current->judul << " - " << current->artist << endl;
            else
                cout << "Tidak ada lagu selanjutnya.\n";
        }

        else if (pilih == 5) {
            current = prevSong(libraryHead, current);
            if (current != nullptr)
                cout << "Prev Lagu: " << current->judul << " - " << current->artist << endl;
            else
                cout << "Tidak ada lagu sebelumnya.\n";
        }
        else if (pilih == 6) {
            int tipe;
            cout << "Tambah berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> tipe;

            SongNode* target = nullptr;

            if (tipe == 1) {
                string id;
                cout << "Masukkan ID lagu: ";
                cin >> id;
                target = findSong(libraryHead, id);
            } else {
                string title;
                cout << "Masukkan Judul lagu: ";
                cin.ignore();
                getline(cin, title);
                target = findSongByTitle(libraryHead, title);
            }

            if (target)
                addToPlaylist(playlist, target);
            else
                cout << "Lagu tidak ditemukan!\n";
        }

        else if (pilih == 7) printPlaylist(playlist);
        else if (pilih == 8) {
            int tipe;
            cout << "Hapus lagu berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> tipe;

            SongNode* target = nullptr;

            if (tipe == 1) {
                string id;
                cout << "Masukkan ID lagu: ";
                cin >> id;
                target = findSong(libraryHead, id);
            } else {
                string title;
                cout << "Masukkan Judul lagu: ";
                cin.ignore();
                getline(cin, title);
                target = findSongByTitle(libraryHead, title);
            }

            removeFromPlaylist(playlist, target);
        }
        else if (pilih == 9) {
            int tipe;
            cout << "Tambah Favorit berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> tipe;

            SongNode* target = nullptr;

            if (tipe == 1) {
                string id;
                cout << "Masukkan ID lagu: ";
                cin >> id;
                target = findSong(libraryHead, id);
            } else {
                string title;
                cout << "Masukkan Judul lagu: ";
                cin.ignore();
                getline(cin, title);
                target = findSongByTitle(libraryHead, title);
            }

            if (target)
                addFavorite(favoriteList, target);
            else
                cout << "Lagu tidak ditemukan!\n";
        }

        else if (pilih == 10) printFavorite(favoriteList);
        else if (pilih == 11) {
            int tipe;
            cout << "Hapus favorit berdasarkan:\n";
            cout << "1. ID Lagu\n";
            cout << "2. Judul Lagu\n";
            cout << "Pilih: ";
            cin >> tipe;

            SongNode* target = nullptr;

            if (tipe == 1) {
                string id;
                cout << "Masukkan ID lagu: ";
                cin >> id;
                target = findSong(libraryHead, id);
            } else {
                string title;
                cout << "Masukkan Judul lagu: ";
                cin.ignore();
                getline(cin, title);
                target = findSongByTitle(libraryHead, title);
            }

            removeFromFavorite(favoriteList, target);
        }
        else if (pilih == 12) {
            cout << "Kembali ke menu utama...\n";
            break;
        }
        else {
            cout << "tidak ada pilihan Menu! \n";
        }
    }
}

int main() {
    initLibrary(libraryHead);
    initPlaylist(playlist);
    initFavorite(favoriteList);

    while (true) {
        int pilih;
        string pass;

        cout << "\n=== MUSIKIN PLAYER ===\n";
        cout << "1. Login Admin\n";
        cout << "2. Login User\n";
        cout << "3. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Password Admin: ";
            cin >> pass;

            if (pass == "kelompok12cihuy")
                menuAdmin();
            else
                cout << "Lu Bukan Admin Woi!\n";
        }
        else if (pilih == 2){
            menuUser();
        }
        else if (pilih == 3){
            break;
        }
        else {
            cout << "Nomor tidak valid";
        }
    }
}
