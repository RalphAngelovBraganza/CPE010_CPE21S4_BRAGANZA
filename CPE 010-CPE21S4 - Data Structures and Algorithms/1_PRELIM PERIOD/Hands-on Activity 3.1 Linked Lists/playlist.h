#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

class Song{
public:
    std::string title;
    Song* next;
};

// Create a new song node
Song* createSong(std::string songTitle){

    // Allocate memory for a new node
    Song* newSong = new Song;
    // Store the song title
    newSong->title = songTitle;
    newSong->next = newSong;

    return newSong;
}

// Add song
void insertSong(std::string songTitle, Song** head){

    // Create a new song
    Song* newSong = createSong(songTitle);
    // Check if the playlist is empty
    if(*head == nullptr){
        *head = newSong;
        return;
    }

    Song* current = *head;
    while(current->next != *head){
        current = current->next;
    }

    // Connect the new song
    current->next = newSong;
    newSong->next = *head;
}

// Display the playlist
void displayPlaylist(Song* head){

    if(head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    Song* current = head;
    int number = 1;

    do{
        std::cout << number << ". " << current->title << std::endl;
        current = current->next;
        number++;
    }while(current != head);
}

// Play all songs once
void playPlaylist(Song* head){

    if(head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    Song* current = head;
    std::cout << "\nNow Playing:" << std::endl;

    do{
        std::cout << current->title << std::endl;
        current = current->next;
    }while(current != head);
}

// Remove/delete song
void deleteSong(int position, Song** head){

    if(*head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    if(position <= 0){
        std::cout << "Invalid song number." << std::endl;
        return;
    }

    Song* current = *head;
    Song* previous = nullptr;

    // Delete the first song
    if(position == 1){

        if(current->next == *head){
            delete current;
            *head = nullptr;
            return;
        }

        Song* last = *head;

        while(last->next != *head){
            last = last->next;
        }

        *head = current->next;
        last->next = *head;

        delete current;
        return;
    }

    int count = 1;

    previous = current;
    current = current->next;

    while(current != *head && count < position - 1){
        previous = current;
        current = current->next;
        count++;
    }

    if(current == *head){
        std::cout << "Invalid song number." << std::endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

// Play next song
void nextSong(Song** current){

    if(*current == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    *current = (*current)->next;
}

// Delete the entire playlist and free all the memory
void deletePlaylist(Song** head){

    if(*head == nullptr){
        return;
    }

    Song* current = (*head)->next;

    while(current != *head){
        Song* temp = current;
        current = current->next;
        delete temp;
    }

    delete *head;
    *head = nullptr;
}

#endif