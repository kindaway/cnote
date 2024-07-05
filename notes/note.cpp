#include <iostream>
#include <map>
#include <cmath>

// 12 notes basic frequencies in the 0 octave
std::map<std::string, float> frequencies = {
    {"c", 16.35},
    {"c#", 17.32},
    {"d", 18.35},
    {"d#", 19.45},
    {"e", 20.60},
    {"f", 21.83},
    {"f#", 23.12},
    {"g", 24.50},
    {"g#", 25.96},
    {"a", 27.50},
    {"a#", 29.14},
    {"b", 30.87}
};


class Note {
public:
    std::string name;
    float frequency;
    int octave;
    explicit Note(const std::string &repr) {
        std::string note;
        std::string nums;
        int octave = 0;

        for (int i = 0; i < repr.length(); i++) {
            if (const char current = repr[i]; !std::isdigit(current)) {
                note += std::tolower(current, std::locale(""));
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
private:
    static std::tuple<std::string, float> getOctave(const std::string &note, const int octave) {
        float baseFrequency = frequencies[note];
        if (octave == 0) {
            return make_tuple(note+"0", baseFrequency);
        }
        return make_tuple(note+std::to_string(octave), baseFrequency*pow(2, octave));
    }
};