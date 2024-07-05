#include <iostream>
#include <map>
#include <cmath>
#include "note.h"

// 12 notes basic frequencies in the 0 octave
std::map<std::string, float> frequencies = {
    {"C", 16.35},
    {"C#", 17.32},
    {"D", 18.35},
    {"D#", 19.45},
    {"E", 20.60},
    {"F", 21.83},
    {"F#", 23.12},
    {"G", 24.50},
    {"G#", 25.96},
    {"A", 27.50},
    {"A#", 29.14},
    {"B", 30.87}
};


Note::Note(const std::string &repr) {
        std::string note;
        std::string nums;
        int octave = 0;

        for (int i = 0; i < repr.length(); i++) {
            if (const char current = repr[i]; !std::isdigit(current)) {
                note += std::toupper(current, std::locale(""));
            }
            else {
                nums += current;
            }
        }
        if (!nums.empty()) {
            octave = std::stoi(nums);
        }
        const float frequency  =  std::get<1>(getOctave(note, octave));

        this->frequency = frequency;
        this->name = note;
        this->octave = octave;
}

std::tuple<std::string, float> Note::getOctave(const std::string &note, const int octave) {
    float baseFrequency = frequencies[note];
    if (octave == 0) {
        return make_tuple(note+"0", baseFrequency);
    }
    return make_tuple(note+std::to_string(octave), baseFrequency*pow(2, octave));
}
