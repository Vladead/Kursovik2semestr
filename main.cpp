#include <iostream>
#include <fstream>
#include "Form.h"
#include "Processing.h"
#include "Vacancy.h"
#include "JobSeeker.h"
#include "JobInfo.h"

using namespace std;

int main() {
    JobInfo jobInfo;
    jobInfo.FillJobInfo();
    int way = 0;
    bool stop = false;
    while (!stop) {
        cout << "1 - Соискатель\n"
             << "2 - Работодатель\n"
             << "3 - Добавить Работодателя/Соискателя/Вакансию\n"
             << "4 - Список удовлетворенных вакансий\n"
             << "5 - Выход" << endl;
        cin >> way;
        switch (way) {
            case 1:
                cout << "Режим соискателя" << endl;
                break;
            case 2:
                cout << "Режим работодателя" << endl;
                break;
            case 3:
                cout << "Режим добавления" << endl;
                break;
            case 4:
                cout << "Режим списка удовлетворенных вакансий" << endl;
                break;
            case 5:
                cout << "Выход" << endl;
                stop = true;
                break;
            default:
                cout << "Попробуйте снова" << endl;
                continue;
        }
    }
//    fstream f;
//    char temp = 0;
//    bool way1 = true;
//    int lineCount = 0, blocksCount = 0, symbolsCount = 0;
//    f.open("../cmake-build-debug/VacancyMode.txt", ios::in);
//    f.unsetf(ios::skipws);
//    int position = 0;
//    lineCount = LineCount(f);
//    for (int i = 0; i < lineCount; i++) {
//        position = f.tellg();
//        symbolsCount = SymbolsCount(f, temp);
//        blocksCount = BlocksInLine(symbolsCount);
//        auto transit_line = new char[symbolsCount + 1];
//        for (int j = 0; j < symbolsCount + 1; j++)
//            transit_line[j] = 0;
//        f.clear();
//        f.seekg(position);
//        for (int j = 0; j < symbolsCount; j++)
//            f >> transit_line[j];
//        f >> temp;
//        way1 = CompareLine(jobInfo.position, transit_line, symbolsCount);
//        InputOneLine(jobInfo.position, symbolsCount, blocksCount, transit_line);
//        jobInfo.position.last->symbols_in_line = symbolsCount;
//        delete[] transit_line;
//    }
//    f.setf(ios::skipws);
//    f.close();

    return 0;
}