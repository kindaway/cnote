#ifndef NOTES_H
#define NOTES_H

#include <iostream>

class Note {
public:
    std::string name;
    float frequency;
    int octave;
    explicit Note(const std::string &repr);
    static std::tuple<std::string, float> getOctave(const std::string &note, int octave);
};

#endif //NOTES_H
