#include <iostream>
#include "notes/note.h"
using namespace std;

int main(int argc, char *argv[]) {
    while (true) {
        string input;
        cout << "> ";
        cin >> input;
        Note note {input};
        cout << "| Note name: " << note.name << endl;
        cout << "| Octave: " << note.octave << endl;
        cout << "| Frequency: " << note.frequency << endl;
    }
    return 0;
}
