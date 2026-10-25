#include <iostream>
#include <limits>
#include <string>
#include "playlist.h"

int main(){

    Song* head = nullptr;
    Song* current = nullptr;

    int choice, songNumber;
    std::string songName;

    do{


        std::cout << "\n⋆.˚✮🎧✮˚.⋆ Ralph's Playlist Menu⋆.˚✮🎧✮˚.⋆" << std::endl;
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Next Song\n";
        std::cout << "4. Play All Songs\n";
        std::cout << "5. Quit\n";

        if(current == nullptr)
            std::cout << "Current Song: None" << std::endl;
        else
            std::cout << "Currently Playing: " << current->title << std::endl;

        std::cout << "\nEnter choice: ";

        while(!(std::cin >> choice)){
            std::cout << "Invalid input. Please enter a number (1-5): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){

        case 1:
            std::cout << "Enter song name: ";
            std::getline(std::cin, songName);

            insertSong(songName, &head);

            if(current == nullptr){
                current = head;
                std::cout << "\n\nNow Playing: " << current->title << std::endl;
            }

            std::cout << "\nSong has been added to the playlist." << std::endl;
                break;

        case 2:
            if(head == nullptr){
                std::cout << "Playlist is empty." << std::endl;
                break;
            }

            std::cout << "\nCurrent Playlist\n";
            displayPlaylist(head);

            std::cout << "\nEnter song number to remove: ";

            while(!(std::cin >> songNumber)){
                std::cout << "Invalid input. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            deleteSong(songNumber, &head);

            if(head == nullptr)
                current = nullptr;
            else
                current = head;

            std::cout << "\nSong deleted..." << std::endl;
            break;

        case 3:
        if(current == nullptr){
            std::cout << "Playlist is empty." << std::endl;
        }
        else{
            nextSong(&current);

        }
        break;

        case 4:
            playPlaylist(head);
            break;

        case 5:
            std::cout << "\n\nEXITING..." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        }

    }while(choice != 5);

    deletePlaylist(&head);

    return 0;
}
