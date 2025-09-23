#pragma once
#include "Parser.h"
#include <fstream>
using namespace std;

class FilesHelper {
public:


    static void ensureFileExists(const string& filename) {
        ifstream in(filename);
        if (!in) {
            ofstream out(filename);
            out.close();
        }
    }

    static void saveLast(const string& fileName, int id) {
        ofstream out(fileName);
        out << id;
    }
    static int getLast(const string& fileName) {
        ensureFileExists(fileName);
        ifstream in(fileName);
        int id = 0;
        if (in >> id) return id;
        return 0;
    }

    static void appendLine(const string& fileName, const string& line) {
        ofstream out(fileName, ios::app);
        out << line << endl;
    }

    static vector<string> readAllLines(const string& fileName) {
        ensureFileExists(fileName);
        vector<string> lines;
        ifstream in(fileName);
        string line;
        while (getline(in, line)) {
            if (!line.empty()) lines.push_back(line);
        }
        return lines;
    }

    static void clearFile(const string& fileName) {
        ofstream out(fileName, ios::trunc);
    }
};
