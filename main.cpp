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
    Vacancy list_of_vacancy, list_of_satisfied_vacancy;
    Employer list_of_employers;
    JobSeeker list_of_jobSeekers;
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
                JobSeekerMode(jobInfo, list_of_jobSeekers);
                break;
            case 2:
                cout << "Режим работодателя" << endl;
                EmployerMode(jobInfo, list_of_employers);
                break;
            case 3:
                cout << "Режим добавления" << endl;
                AddingMode(jobInfo, list_of_jobSeekers, list_of_employers, list_of_vacancy);
                break;
            case 4:
                cout << "Режим списка удовлетворенных вакансий" << endl;
                SatisfiedVacancyMode(list_of_satisfied_vacancy);
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