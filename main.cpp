#include <iostream>
#include <fstream>
#include <cstring>

int countLines(std::ifstream& file) {
    int lines = 0;
    std::string line;
    while (std::getline(file, line)) {
        lines++;
    }
    return lines;
}

int countWords(std::ifstream& file) {
    int words = 0;
    std::string word;
    while (file >> word) {
        words++;
    }
    return words;
}

int countBytes(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    return file.tellg();
}

int main(int argc, char* argv[]) {
    int lines = 0;
    int words = 0;
    int bytes = 0;

    bool countLinesOption = false;
    bool countWordsOption = false;
    bool countBytesOption = false;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            countLinesOption = true;
        } else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            countWordsOption = true;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            countBytesOption = true;
        } else {
            std::ifstream file(argv[i]);
            if (!file.is_open()) {
                std::cerr << "Error: Unable to open file " << argv[i] << std::endl;
                return 1;
            }
            if (countLinesOption) {
                lines = countLines(file);
            }
            if (countWordsOption) {
                words = countWords(file);
            }
            if (countBytesOption) {
                bytes = countBytes(file);
            }
            file.close();
        }
    }

    std::cout << lines << " " << words << " " << bytes;