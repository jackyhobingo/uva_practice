#include <iostream>
#include <cstring>
#define MAX_SIZE 201
using namespace std;

char buffer[2];
char music[MAX_SIZE];
int fingerOfNotes[15][10] = {
    {0,1,1,0,0,0,0,0,0,0}, // a
    {0,1,0,0,0,0,0,0,0,0}, // b
    {0,1,1,1,0,0,1,1,1,1}, // c 
    {0,1,1,1,0,0,1,1,1,0}, // d
    {0,1,1,1,0,0,1,1,0,0}, // e
    {0,1,1,1,0,0,1,0,0,0}, // f
    {0,1,1,1,0,0,0,0,0,0}, // g
    {1,1,1,0,0,0,0,0,0,0}, // A
    {1,1,0,0,0,0,0,0,0,0}, // B
    {0,0,1,0,0,0,0,0,0,0}, // C
    {1,1,1,1,0,0,1,1,1,0}, // D
    {1,1,1,1,0,0,1,1,0,0}, // E
    {1,1,1,1,0,0,1,0,0,0}, // F
    {1,1,1,1,0,0,0,0,0,0}, // G
    {0,0,0,0,0,0,0,0,0,0}  // initial
};

void play_music(int* note_past_addr, char note_new, int finger_sum[]);


int main()
{   
    int n;
    cin >> n;
    cin.getline(buffer, 2); // "\n"
    
    int finger_sum[10];
    while(n--)
    {
        int note = 14;
        cin.getline(music, MAX_SIZE);
        int len = strlen(music);
       
        for (int i = 0; i < 10; i++) {
            finger_sum[i] = 0;
        }

        for (int i = 0; i < len; i++) {
            play_music(&note, music[i], finger_sum);
        }
        
        
        for (int i = 0; i < 10; i++) {
           
            cout << finger_sum[i];
            if(i < 10 - 1) {
                cout << " ";
            } else {
                cout << endl;
            }   
        }
    }
    return 0;
}

void play_music(int* note_past_addr, char note_new, int finger_sum[]) {
    int addr, change[10];
    if(note_new <= 'g' && note_new >= 'a') {
        addr = (int)note_new - 'a';
    } else {
        addr = (int)note_new - 'A' + 7;
    }
    for (int i = 0; i < 10; i++) {
        finger_sum[i] += fingerOfNotes[addr][i] - fingerOfNotes[*note_past_addr][i] > 0 ? 1 : 0; 
    }
    *note_past_addr = addr;
}
