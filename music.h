#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>
using namespace std;

// =======================
// STRUCT DATA LAGU
// =======================

struct SongNode {
    string id;
    string judul;
    string artist;
    string genre;
    int duration;
    SongNode* next;
    SongNode* prev;
};


// =======================
// PLAYLIST STRUCT
// =======================
struct PlaylistNode {
    SongNode* songRef;
    PlaylistNode* next;
};

struct Playlist {
    PlaylistNode* head;
};

// =======================
// FAVORITE STRUCT
// =======================
struct FavoriteNode {
    SongNode* songRef;
    FavoriteNode* next;
};

struct FavoriteList {
    FavoriteNode* head;
};

// =======================
// FUNCTION PROTOTYPE
// =======================

// library
void initLibrary(SongNode*& head);
SongNode* createSong(string id, string judul, string artist, string genre, int duration);
void addSong(SongNode*& head, SongNode* newSong);
void printLibrary(SongNode* head);
SongNode* findSong(SongNode* head, string id);
SongNode* findSongByTitle(SongNode* head, string title);
void editSong(SongNode*& head, string id);
void deleteSong(SongNode*& head, string id);

// playlist
void initPlaylist(Playlist& pl);
void addToPlaylist(Playlist& pl, SongNode* song);
void printPlaylist(Playlist pl);
void removeFromPlaylist(Playlist& PL, SongNode* target);


// favorite
void initFavorite(FavoriteList& fav);
void addFavorite(FavoriteList& fav, SongNode* song);
void printFavorite(FavoriteList fav);
void removeFromFavorite(FavoriteList& FL, SongNode* target);


// player
void playSong(SongNode* song);
void stopSong();
SongNode* nextSong(SongNode* current);
SongNode* prevSong(SongNode* head, SongNode* current);
extern SongNode* currentSong;
extern SongNode* libraryHead;


#endif
