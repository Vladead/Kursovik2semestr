#include <iostream>
#include <fstream>
#include "Form.h"
#include "Processing.h"
#include "Vacancy.h"
#include "JobSeeker.h"
#include "JobInfo.h"
#include "Employer.h"

using namespace std;

int main() {
    fstream protocolFile, outputFile;
    Vacancy listOfVacancy, listOfSatisfiedVacancy;
    Employer listOfEmployers;
    JobSeeker listOfJobSeekers;
    JobInfo jobInfo;
    jobInfo.fillJobInfo();
    int way = 0;
    bool stop = false;
    protocolFile.open("protocolFile.txt", ios::out);
    addFirstInfo(listOfVacancy, listOfEmployers, listOfJobSeekers, jobInfo, protocolFile);
    outputFile.open("outputFile.txt", ios::out);
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
                jobSeekerMode(jobInfo, listOfJobSeekers, listOfVacancy, listOfSatisfiedVacancy, outputFile);
                break;
            case 2:
                cout << "Режим работодателя" << endl;
                employerMode(jobInfo, listOfEmployers, listOfJobSeekers, listOfVacancy, listOfSatisfiedVacancy,
                             outputFile);
                break;
            case 3:
                cout << "Режим добавления" << endl;
                addingMode(jobInfo, listOfJobSeekers, listOfEmployers, listOfVacancy);
                break;
            case 4:
                cout << "Режим списка удовлетворенных вакансий" << endl;
                satisfiedVacancyMode(listOfSatisfiedVacancy);
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

    outputFile.close();
    outputProtocol(jobInfo, listOfVacancy, listOfJobSeekers, listOfEmployers, protocolFile);
    protocolFile.close();
    return 0;
}