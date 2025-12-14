#include "music.h"

// ==========================
// LIBRARY IMPLEMENTATION
// ==========================

void initLibrary(SongNode*& head) {
    head = nullptr;
}

SongNode* createSong(string id, string judul, string artist, string genre, int duration) {
    SongNode* newNode = new SongNode;
    newNode->id = id;
    newNode->judul = judul;
    newNode->artist = artist;
    newNode->genre = genre;
    newNode->duration = duration;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void addSong(SongNode*& head, SongNode* newSong) {
    if (head == nullptr) {
        head = newSong;
    } else {
        SongNode* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;   // <── tambah ini
    }
    cout << "Lagu berhasil ditambahkan!\n";
}

void printLibrary(SongNode* head) {
    if (head == nullptr) {
        cout << "\n=== DAFTAR LAGU ===\n";
        cout << "Belum ada lagu yang ditambahkan.\n";
        return;
    }

    cout << "\n=== DAFTAR LAGU ===\n";
    SongNode* temp = head;
    while (temp != nullptr) {
        cout << temp->id << " - " << temp->judul
             << " | " << temp->artist << " | " << temp->genre << endl;
        temp = temp->next;
    }
}

SongNode* findSong(SongNode* head, string id) {
    SongNode* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

SongNode* findSongByTitle(SongNode* head, string title) {
    SongNode* temp = head;
    while (temp != nullptr) {
        if (temp->judul == title) return temp;
        temp = temp->next;
    }
    return nullptr;
}


void editSong(SongNode*& head, string id) {
    SongNode* s = findSong(head, id);
    if (s == nullptr) {
        cout << "Lagu tidak ditemukan!\n";
        return;
    }
    cout << "Edit judul: "; cin >> s->judul;
    cout << "Edit artist: "; cin >> s->artist;
    cout << "Edit genre: "; cin >> s->genre;
    cout << "Edit durasi: "; cin >> s->duration;
    cout << "Data lagu berhasil diubah!\n";
}

void deleteSong(SongNode*& head, string id) {
    if (head == nullptr) return;

    SongNode* temp = head;
    SongNode* prev = nullptr;

    while (temp != nullptr) {
        if (temp->id == id) {

            // hapus dari library saja
            if (prev == nullptr) head = temp->next;
            else prev->next = temp->next;

            delete temp;
            cout << "Lagu dihapus dari library!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Lagu tidak ditemukan!\n";
}


// ==========================
// PLAYLIST IMPLEMENTATION
// ==========================

void initPlaylist(Playlist& pl) {
    pl.head = nullptr;
}

void addToPlaylist(Playlist& pl, SongNode* song) {
    PlaylistNode* newNode = new PlaylistNode;
    newNode->songRef = song;
    newNode->next = nullptr;

    if (pl.head == nullptr) pl.head = newNode;
    else {
        PlaylistNode* temp = pl.head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Lagu ditambahkan ke playlist!\n";
}

void printPlaylist(Playlist pl) {
    if (pl.head == nullptr) {
        cout << "\nPlaylist masih kosong.\n";
        return;
    }

    cout << "\n=== PLAYLIST ===\n";
    PlaylistNode* temp = pl.head;
    while (temp != nullptr) {
        cout << temp->songRef->id << " - " << temp->songRef->judul << endl;
        temp = temp->next;
    }
}

void removeFromPlaylist(Playlist& PL, SongNode* target) {
    if (PL.head == nullptr || target == nullptr) {
        cout << "Playlist kosong atau lagu tidak ditemukan.\n";
        return;
    }

    PlaylistNode* temp = PL.head;

    // Jika yang dihapus adalah head
    if (temp->songRef == target) {
        PL.head = temp->next;
        delete temp;
        cout << "Lagu berhasil dihapus dari playlist.\n";
        return;
    }

    // Cari yang bukan head
    PlaylistNode* prev = nullptr;
    while (temp != nullptr && temp->songRef != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Lagu tidak ditemukan dalam playlist.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Lagu berhasil dihapus dari playlist.\n";
}


// ==========================
// FAVORITE IMPLEMENTATION
// ==========================

void initFavorite(FavoriteList& fav) {
    fav.head = nullptr;
}

void addFavorite(FavoriteList& fav, SongNode* song) {
    FavoriteNode* newNode = new FavoriteNode;
    newNode->songRef = song;
    newNode->next = nullptr;

    if (fav.head == nullptr) fav.head = newNode;
    else {
        FavoriteNode* temp = fav.head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Lagu ditambahkan ke favorit!\n";
}

void printFavorite(FavoriteList fav) {
    if (fav.head == nullptr) {
        cout << "\nFavorite List masih kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR FAVORIT ===\n";
    FavoriteNode* temp = fav.head;
    while (temp != nullptr) {
        cout << temp->songRef->judul << " - "
             << temp->songRef->artist << endl;
        temp = temp->next;
    }
}

void removeFromFavorite(FavoriteList& FL, SongNode* target) {
    if (FL.head == nullptr || target == nullptr) {
        cout << "Daftar favorit kosong atau lagu tidak ditemukan.\n";
        return;
    }

    FavoriteNode* temp = FL.head;

    // Jika head yang dihapus
    if (temp->songRef == target) {
        FL.head = temp->next;
        delete temp;
        cout << "Lagu berhasil dihapus dari daftar favorit.\n";
        return;
    }

    FavoriteNode* prev = nullptr;
    while (temp != nullptr && temp->songRef != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Lagu tidak ditemukan dalam daftar favorit.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Lagu berhasil dihapus dari daftar favorit.\n";
}


// ==========================
// PLAYER IMPLEMENTATION
// ==========================

void playSong(SongNode* song) {
    cout << "\n Now Playing: " << song->judul << " - " << song->artist << endl;
}

void stopSong() {
    if (currentSong == nullptr) {
        cout << "Tidak ada lagu yang sedang dimainkan.\n";
    } else {
        cout << "Lagu dihentikan.\n";
        currentSong = nullptr;
    }
}

SongNode* nextSong(SongNode* current) {
    return (current != nullptr) ? current->next : nullptr;
}

SongNode* prevSong(SongNode* head, SongNode* current) {
    if (current == head) return nullptr;

    SongNode* temp = head;
    while (temp != nullptr && temp->next != current) {
        temp = temp->next;
    }
    return temp;
}

SongNode* currentSong = nullptr;
SongNode* libraryHead = nullptr;



void playNext() {
    if (currentSong == nullptr) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if (currentSong->next != nullptr) {
        currentSong = currentSong->next;
        cout << "Next Lagu: " << currentSong->judul << endl;
    } else {
        cout << "Tidak ada lagu selanjutnya.\n";
    }
}

void playPrev() {
    if (currentSong == nullptr) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if (currentSong->prev != nullptr) {
        currentSong = currentSong->prev;
        cout << "Prev Lagu: " << currentSong->judul << endl;
    } else {
        cout << "Tidak ada lagu sebelumnya.\n";
    }
}

