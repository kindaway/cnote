#include <iostream>
#include "notes/note.h"
using namespace std;

int main(int argc, char *argv[]) {
    while (true) {
        string input;
        cout << "> ";
        cin >> input;
        if (input == "q") {
            exit(0);
        }
        Note note {input};
        cout << "| Note name: " << note.name << endl;
        cout << "| Octave: " << note.octave << endl;
        cout << "| Frequency: " << note.frequency << endl;
    }
}
