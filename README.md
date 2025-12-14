# 🎵 Musikin Player - Tugas Besar Struktur Data

> **Kelompok 12** > Repository ini berisi source code untuk Tugas Besar mata kuliah Struktur Data. Aplikasi ini adalah simulasi pemutar musik berbasis CLI (Command Line Interface) yang menerapkan berbagai manipulasi struktur data.

## 👥 Anggota Kelompok
* **[Fembiana Dika Saputri]** - [103132400026]
* **[Nur Tsalits Alwan Mubarok]** - [103132400039]
* **[Abdullah Ahmad Izzah]** - [103132430024]
  
## 🛠️ Struktur Data yang Digunakan
Inti dari proyek ini adalah implementasi manual (tanpa STL container) dari:
* **Doubly Linked List:** Digunakan pada **Library Utama Lagu**. Memungkinkan navigasi dua arah (*Next* dan *Previous* song).
* **Singly Linked List:** Digunakan pada **Playlist** dan **Daftar Favorit**. Menggunakan pointer reference ke node lagu asli untuk efisiensi memori.
* **Pointer Manipulation:** Digunakan untuk fitur *Play*, *Next*, *Prev*, dan penghapusan data yang saling berelasi (Library ke Playlist).

## 🚀 Fitur Aplikasi

### 👨‍💻 Mode Admin
* **Login Authentication** (Password Protected).
* **CRUD Lagu:** Menambah, melihat, mengedit, dan menghapus lagu dari Library.
* **Smart Delete:** Saat lagu dihapus dari Library, lagu tersebut otomatis terhapus dari semua Playlist user untuk mencegah error (*dangling pointer*).

### 🎧 Mode User
* **Search Engine:** Pencarian lagu berdasarkan **ID** atau **Judul**.
* **Playback Control:** Play, Stop, Next, Previous.
* **Playlist Management:** Menambahkan lagu ke playlist pribadi.
* **Favorites:** Menandai lagu yang disukai.

## 🔑 Akun Demo
Untuk pengujian fitur Admin, gunakan kredensial berikut:
* **Role:** Admin
* **Password:** `kelompok12cihuy`

## 💻 Cara Menjalankan (How to Run)
1.  Clone repository ini:
    ```bash
    git clone [https://github.com/alwansoleh/TUBES_STRUKTUR-DATA_KELOMPOK-12.git](https://github.com/alwansoleh/TUBES_STRUKTUR-DATA_KELOMPOK-12.git)
    ```
2.  Buka terminal di folder project.
3.  Compile file `main.cpp` dan `music.cpp`:
    ```bash
    g++ main.cpp music.cpp -o musikin
    ```
4.  Jalankan aplikasi:
    * Windows: `musikin`
    * Mac/Linux: `./musikin`

---
*Dibuat untuk memenuhi Tugas Besar Struktur Data Semester 3.*
