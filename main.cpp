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

    return 0;
}