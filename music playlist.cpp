#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Song structure
struct Song {
    string name;
    string artist;
    int duration;

    Song(string n, string a, int d) : name(n), artist(a), duration(d) {}
};

// Node structure for the linked list  
struct Node {
    Song data;
    Node* next;

    Node(Song s) : data(s), next(NULL) {}
};

class MusicPlaylist {
private:
    Node* playlist;

public:
    MusicPlaylist() : playlist(NULL) {}

    // Function to add a new song to the playlist
    void addSong() {
        string name, artist;
        int duration;

        cout << "Enter song name: ";
        cin.ignore(); // Ignore any remaining newline characters in the input buffer
        getline(cin, name);

        cout << "Enter artist name: ";
        getline(cin, artist);

        cout << "Enter song duration (in seconds): ";
        cin >> duration;

        Song newSong(name, artist, duration);
        Node* newNode = new Node(newSong);

        if (playlist == NULL) {
            playlist = newNode;
        } else {
            Node* temp = playlist;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Song added to the playlist: " << name << " by " << artist << endl;
    }

    // Function to delete a song from the playlist
    void deleteSong() {
        if (playlist == NULL) {
            cout << "Playlist is empty. No songs to delete." << endl;
            return;
        }

        cout << "Enter the name of the song to delete: ";
        string name;
        cin.ignore(); // Ignore any remaining newline characters in the input buffer
        getline(cin, name);

        Node* current = playlist;
        Node* previous = NULL;

        while (current != NULL && current->data.name != name) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Song not found in the playlist." << endl;
        } else {
            if (previous == NULL) {
                playlist = current->next;
            } else {
                previous->next = current->next;
            }

            delete current;
            cout << "Song deleted from the playlist: " << name << endl;
        }
    }

    // Function to save the playlist to a file
    void savePlaylist() {
        ofstream file("playlist.txt");
        if (!file.is_open()) {
            cout << "Error opening the file for saving the playlist." << endl;
            return;
        }

        Node* temp = playlist;
            file << ""<<endl;
        	file << "Song Name:  \t\t Artist Name:  \t\t Song Duaration: "<<endl;
        	file << ""<<endl;
        while (temp != NULL) {
            file << temp->data.name << "\t\t\t" << temp->data.artist << "\t\t\t" << temp->data.duration << endl;
            temp = temp->next;
        }

        file.close();
        cout << "Playlist saved to 'playlist.txt'." << endl;
    }

    // Function to display the playlist
    void displayPlaylist() {
        if (playlist == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Playlist:" << endl;
        Node* temp = playlist;
        while (temp != NULL) {
            cout << temp->data.name << " by " << temp->data.artist << " (" << temp->data.duration << " seconds)" << endl;
            temp = temp->next;
        }
    }
};

int main() {

        MusicPlaylist playlist;
  	cout<<"\n\n\t\t\t**\n";
	    cout<<"\t\t\t**                MUSIC PLAYLIST                  **\n";
	    cout<<"\t\t\t**\n";
	      A:
	    cout<<"\n\n\n\t\t\t\t1. Add Song to Playlist.\n";
	    cout<<"\t\t\t\t2. Delete Song from Playlist.\n";
	    cout<<"\t\t\t\t3. Save Playlist to File.\n";
	    cout<<"\t\t\t\t4. Display Playlist.\n";
	    cout<<"\t\t\t\t5. Exit.\n";

	int option,s,id;
	cout<<"\n\n\t\t\tWhich operation you want to perform = ";
	cin>>option;
	switch(option)
	{ case 1:
		   {
			playlist.addSong();
		    	cout<<"\n\n";
       		    cout<<"Press 0 If you want any other operation otherwise exit = ";
       		    cin>>s;
       		    if(s==0)
				  {
				    goto A;
				   } 
				else
			   	{     
				     cout<<"\n\n\t\t\t**YOUR PROGRAM IS EXIT";
	            }
		    break;
			}
	  case 2:
	  	    {
			  playlist.deleteSong();
	  	    	cout<<"\n\n";
       		    cout<<"Press 0 If you want any other operation otherwise exit = ";
       		    cin>>s;
       		    if(s==0)
				  {
				    goto A;
				   } 
				else
			   	{     
				     cout<<"\n\n\t\t\t**YOUR PROGRAM IS EXIT";
	            }
	  	    break;
	     	}
	  case 3:
	    	{
			 playlist.savePlaylist();
	    		cout<<"\n\n";
       		    cout<<"Press 0 If you want any other operation otherwise exit = ";
       		    cin>>s;
       		    if(s==0)
				  {
				    goto A;
				  } 
				else
			   	{     
				     cout<<"\n\n\t\t\t**YOUR PROGRAM IS EXIT";
	            }
	    	break;
	        }   	    	
	  case 4:
	  	{   
                playlist.displayPlaylist();
				cout<<"\n\n";
       		    cout<<"Press 0 If you want any other operation otherwise exit = ";
       		    cin>>s;
       		    if(s==0)
				  {
				    goto A;
				   } 
				else
			   	{     
				     cout<<"\n\n\t\t\t**YOUR PROGRAM IS EXIT";
	            }
			break;
		}
	  case 5:
			cout<<"\t\t\tYour Program is Exit.\n";
			break;
	default:
		{
		cout<<"\t\t\tThis option is not available.\n";
		break;
	    }
	}
	return 0;
}