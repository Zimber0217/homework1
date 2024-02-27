#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool hasOption(const string& option, const vector<string>& args) {
    for (const string& arg : args) {
        if (arg == option) {
            return true;
        }
    }
    return false;
}

int countLines(const string& filename) {
    ifstream file(filename);
    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }
    return count;
}

int countWords(const string& filename) {
    ifstream file(filename);
    int count = 0;
    string word;
    while (file >> word) {
        count++;
    }
    return count;
}

int countBytes(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}

int main(int argc, char* argv[]) {
    vector<string> args(argv + 1, argv + argc);
    bool showLines = hasOption("-l", args) || hasOption("--lines", args);
    bool showWords = hasOption("-w", args) || hasOption("--words", args);
    bool showBytes = hasOption("-c", args) || hasOption("--bytes", args);

    vector<string> filenames;
    for (const string& arg : args) {
        if (arg != "-l" && arg != "-c" && arg != "-w" && arg != "--lines" && arg != "--bytes" && arg != "--words") {
            filenames.push_back(arg);
        }
    }

    for (const string& filename : filenames) {
        int lines = showLines ? countLines(filename) : 0;
        int words = showWords ? countWords(filename) : 0;
        int bytes = showBytes ? countBytes(filename) : 0;

        cout << lines << " " << words << " " << bytes << " " << filename << endl;
    }

    return 0;
}