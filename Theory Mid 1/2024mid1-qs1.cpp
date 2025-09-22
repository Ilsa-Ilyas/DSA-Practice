#include <iostream>
using namespace std;

// Node class represents one song in the playlist
class Node {
public:
    string song;   // song name
    Node* next;    // pointer to next song
    Node* prev;    // pointer to previous song
    
    // constructor to initialize a new Node with song name
    Node(const string& s) {
        song = s;
        next = nullptr;
        prev = nullptr;
    }
};


class Playlist {
    Node* head;     // first song
    Node* tail;     // last song
    Node* current;  // currently playing song
    int size;       // number of songs in playlist
    
public:
    // constructor: initialize empty playlist
    Playlist () : head(nullptr), tail(nullptr), current(nullptr), size(0) {}
    
    // destructor: free all nodes
    ~Playlist() {
        Node* playlist = head;
        while (playlist) {
            Node* nextt = playlist -> next;  // save next before deleting
            delete playlist;
            playlist = nextt;                // move forward
        }
    }
    
    // ADD SONG AT THE END OF THE PLAYLIST (2 MARKS)	
    void insertatend (const string& name) {
        Node* node = new Node(name);  // create new node with song name
        
        if(!head) {
            // if playlist empty, first song becomes head, tail, current
            head = tail = current = node;
        }
        else {
            // attach new node after tail
            tail -> next = node;
            node -> prev = tail;
            tail = node;		 
        }
        
        size++;  // increase playlist size
    }

    // REMOVE A SONG FROM THE PLAYLIST (2 MARKS)
    void removeSong(const string& name) {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* playlist = head;
        while (playlist != NULL) {
            if (playlist -> song == name) {
                // fix previous link
                if (playlist-> prev != NULL) {
                    playlist -> prev -> next = playlist -> next;
                }
                else 
                    head = playlist -> next;  // if removing head
                
                // fix next link
                if (playlist->next != NULL ) {
                    playlist -> next -> prev = playlist -> prev;
                }
                else 
                    tail = playlist -> prev;  // if removing tail
                
                // adjust current pointer
                if (current == playlist) {
                    if (playlist-> next != NULL) {
                        current = playlist -> next;
                    }
                    else
                        current = playlist -> prev;
                }
                
                delete playlist;
                size --;
                
                if (size == 0) {
                    head = tail = current = NULL;
                }
                
                cout << "Song has been successfully removed by ilsa lol hehe :)" << endl;
                return;
            }
            
            playlist = playlist -> next;
        }
    }
    
    // move to the next song in the playlist (2 marks)
    void move () {
        if (current == NULL) {  // FIX: use == not =
            cout << "i fw empty playlist harddd LOLOL" << endl;
            return; // FIX: semicolon
        }
        
        if (current -> next != NULL ) {
            current = current -> next; 	
        }
        else 
            cout << "Last song pe hain na kidher jana hai" << endl;
    }
        
    // move to a specific location in the playlist
    void movesp (const string& name) {
        if (head == NULL) {
            cout << "abay khali hai gadhe" << endl;
            return;
        }
        
        Node* p = head;
        while (p != NULL) {
            if (p-> song == name) {
                current = p;
                cout << "song: " << name << endl;
                return;   // FIX: semicolon
            }
            
            p = p -> next;
        }
        cout << "nhi mila chupp bas" << endl;
    }

    // print current song
    void printc() {
        if (current == NULL) {
            cout << "empty babe" << endl;
            return;
        }
        cout << "Current song: " << current->song << endl;
    }   
};
