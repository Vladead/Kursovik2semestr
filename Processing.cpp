//
// Created by vladead on 08.05.19.
//

#include <iostream>
#include <fstream>
#include "Processing.h"
#include "List1.h"
#include "BlocksList.h"
#include "LineWithMarker.h"
#include "Form.h"
#include "FormBlock.h"
#include "JobInfo.h"
#include "Vacancy.h"
#include "Employer.h"
#include "JobSeeker.h"

using namespace std;

void JobSeekerMode(JobInfo &jobInfo, JobSeeker &jobSeeker) {
    fstream input_file;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    input_file.open("../cmake-build-debug/AddingMode.txt", ios::in);
    input_file.unsetf(ios::skipws);
    int position = 0;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    auto transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.surname, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.surname, symbolsCount, blocksCount, transit_line);
        jobInfo.surname.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.name, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.name, symbolsCount, blocksCount, transit_line);
        jobInfo.name.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.patronymic, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.patronymic, symbolsCount, blocksCount, transit_line);
        jobInfo.patronymic.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.position, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.position, symbolsCount, blocksCount, transit_line);
        jobInfo.position.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.work_experience, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.work_experience, symbolsCount, blocksCount, transit_line);
        jobInfo.work_experience.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.education, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.education, symbolsCount, blocksCount, transit_line);
        jobInfo.education.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.schedule, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transit_line);
        jobInfo.schedule.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.salary, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.salary, symbolsCount, blocksCount, transit_line);
        jobInfo.salary.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    input_file.setf(ios::skipws);
    input_file.close();
}

void EmployerMode(JobInfo &jobInfo, Employer &employer) {
    fstream input_file;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    input_file.open("../cmake-build-debug/EmployerMode.txt", ios::in);
    input_file.unsetf(ios::skipws);
    int position = 0;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    auto transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.title, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.title, symbolsCount, blocksCount, transit_line);
        jobInfo.title.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.address, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.address, symbolsCount, blocksCount, transit_line);
        jobInfo.address.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.phone_number, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.phone_number, symbolsCount, blocksCount, transit_line);
        jobInfo.phone_number.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.position, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.position, symbolsCount, blocksCount, transit_line);
        jobInfo.position.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.schedule, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transit_line);
        jobInfo.schedule.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.salary, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.salary, symbolsCount, blocksCount, transit_line);
        jobInfo.salary.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.education, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.education, symbolsCount, blocksCount, transit_line);
        jobInfo.education.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.work_experience, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.work_experience, symbolsCount, blocksCount, transit_line);
        jobInfo.work_experience.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.title, transit_line, symbolsCount)) {
        cout << "Такой компании нет в базе данных" << endl; //TODO довести до ума
    }
    delete[] transit_line;

    input_file.setf(ios::skipws);
    input_file.close();
}

void AddingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy) {
    int way = 0;
    cout << "1 - Соискателя\n"
         << "2 - Работодателя\n"
         << "3 - Вакансии\n"
         << endl;
    cin >> way;
    switch (way) {
        case 1:
            Add(jobInfo, jobSeeker);
            cout << "Соискатель добавлен" << endl;
            break;
        case 2:
            Add(jobInfo, employer);
            cout << "Работодатель добавлен" << endl;
            break;
        case 3:
            Add(jobInfo, vacancy);
            cout << "Вакансия добавлена" << endl;
            break;
        default:
            cout << "Неправильный ввод" << endl;
    }
}

void SatisfiedVacancyMode() {

}

void Add(JobInfo &jobInfo, JobSeeker &jobSeeker) {
    fstream input_file;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    input_file.open("../cmake-build-debug/AddingMode.txt", ios::in);
    input_file.unsetf(ios::skipws);
    int position = 0;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    auto transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.surname, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.surname, symbolsCount, blocksCount, transit_line);
        jobInfo.surname.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.name, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.name, symbolsCount, blocksCount, transit_line);
        jobInfo.name.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.patronymic, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.patronymic, symbolsCount, blocksCount, transit_line);
        jobInfo.patronymic.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.position, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.position, symbolsCount, blocksCount, transit_line);
        jobInfo.position.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.work_experience, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.work_experience, symbolsCount, blocksCount, transit_line);
        jobInfo.work_experience.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.education, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.education, symbolsCount, blocksCount, transit_line);
        jobInfo.education.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.schedule, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transit_line);
        jobInfo.schedule.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.salary, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.salary, symbolsCount, blocksCount, transit_line);
        jobInfo.salary.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    input_file.setf(ios::skipws);
    input_file.close();
}

void Add(JobInfo &jobInfo, Employer &employer) {
    fstream input_file;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    input_file.open("../cmake-build-debug/AddingMode.txt", ios::in);
    input_file.unsetf(ios::skipws);
    int position = 0;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    auto transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.title, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.title, symbolsCount, blocksCount, transit_line);
        jobInfo.title.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.address, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.address, symbolsCount, blocksCount, transit_line);
        jobInfo.address.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.phone_number, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.phone_number, symbolsCount, blocksCount, transit_line);
        jobInfo.phone_number.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    input_file.setf(ios::skipws);
    input_file.close();
}

void Add(JobInfo &jobInfo, Vacancy &vacancy) {
    fstream input_file;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    input_file.open("../cmake-build-debug/AddingMode.txt", ios::in);
    input_file.unsetf(ios::skipws);
    int position = 0;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    auto transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.position, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.position, symbolsCount, blocksCount, transit_line);
        jobInfo.position.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.schedule, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transit_line);
        jobInfo.schedule.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.salary, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.salary, symbolsCount, blocksCount, transit_line);
        jobInfo.salary.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.education, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.education, symbolsCount, blocksCount, transit_line);
        jobInfo.education.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.field_of_activity, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.field_of_activity, symbolsCount, blocksCount, transit_line);
        jobInfo.field_of_activity.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.work_experience, transit_line, symbolsCount)) {
        InputOneLine(jobInfo.work_experience, symbolsCount, blocksCount, transit_line);
        jobInfo.work_experience.last->symbols_in_line = symbolsCount;
    }
    delete[] transit_line;

    position = input_file.tellg();
    symbolsCount = SymbolsCount(input_file, temp);
    blocksCount = BlocksInLine(symbolsCount);
    transit_line = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transit_line[j] = 0;
    input_file.clear();
    input_file.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        input_file >> transit_line[j];
    input_file >> temp;
    input_file >> temp;
    if (!WordIsInList(jobInfo.title, transit_line, symbolsCount)) {
        cout << "Такой компании нет в базе данных" << endl;
    }
    delete[] transit_line;

    input_file.setf(ios::skipws);
    input_file.close();
}

bool WordIsInList(Form &InJobInfo, const char *temp_line, int symbols_count_of_temp) {
    FormBlock tempFormBlock;
    InJobInfo.current = InJobInfo.head;
    tempFormBlock.current = InJobInfo.current->line;
    bool word_is_already_in_list = false, word_fits = true;
    int k = 0;
    while (InJobInfo.current != nullptr) {
        if (InJobInfo.current->symbols_in_line == symbols_count_of_temp) {
            for (int i = 0; i < symbols_count_of_temp; i++, k++) {
                if (tempFormBlock.current->block->symbols[k] != temp_line[i]) {
                    InJobInfo.current = InJobInfo.current->next;
                    tempFormBlock.current = InJobInfo.current->line;
                    word_fits = false;
                    break;
                }
                if ((k + 1) % 5 == 0) {
                    tempFormBlock.current = tempFormBlock.current->next;
                    k = -1; // Из за инкрементирования в начале каждой итерации
                }
            }
            if (word_fits) {
                word_is_already_in_list = true;
                break;
            }
            word_fits = true;
            k = 0;
        } else {
            InJobInfo.current = InJobInfo.current->next;
            if (InJobInfo.current == nullptr)
                break;
            tempFormBlock.current = InJobInfo.current->line;
        }
    }
    return word_is_already_in_list;
}

void getting_info_from_file(Form &form, fstream &input_file) {
    //--------------------------------------------------------------------------------------------Чтение данных из файла
    char temp = 0;
    int symbols_count = 0, blocks_count = 0, lineCountFromInput = 0;
    if (!CheckFile(input_file)) {
        input_file.close();
        exit(1);
    }

    input_file.unsetf(ios::skipws);
    int position = 0;
    lineCountFromInput = LineCount(input_file);
    for (int i = 0; i < lineCountFromInput; i++) {
        position = input_file.tellg();
        symbols_count = SymbolsCount(input_file, temp);
        blocks_count = BlocksInLine(symbols_count);
        auto transit_line = new char[symbols_count + 1];
        for (int j = 0; j < symbols_count + 1; j++)
            transit_line[j] = 0;
        input_file.clear();
        input_file.seekg(position);
        for (int j = 0; j < symbols_count; j++)
            input_file >> transit_line[j];
        input_file >> temp;
        InputOneLine(form, symbols_count, blocks_count, transit_line);
        form.last->symbols_in_line = symbols_count;
        delete[] transit_line;
    }

    input_file.setf(ios::skipws);
}

void InputOneLine(Form &form, int symbols_count, int blocks_count, const char *transit_line) {
    //--------------------------------------------------------------------------Записывает в список одну строку из файла
    FormBlock formBlock;
    auto *temp = new List1;

    int j = 0;
    int k = 0;
    for (int i = 0; i < blocks_count; i++) {
        auto *temp1 = new BlocksList;
        temp1->block = new LineWithMarker;
        temp1->block->symbols = new char[temp1->max_symbols_in_block];
        for (int b = 0; b < temp1->max_symbols_in_block + 1; b++)
            temp1->block->symbols[b] = 0;
        k = 0;
        if (symbols_count - j == 1 && symbols_count % 5 == 0) { // Для записи толлько одного маркер
            j += 2;
        }
        for (; k < temp1->max_symbols_in_block && j < symbols_count; j++) {
            temp1->block->symbols[k] = transit_line[j];
            k++;
            if (j + 1 >= symbols_count) {
                break;
            }
        }
        if (formBlock.head != nullptr) {
            formBlock.last->next = temp1;
            formBlock.last = formBlock.last->next;
        } else {
            formBlock.head = temp1;
            temp->line = temp1;
            formBlock.last = formBlock.head;
        }

    }
    formBlock.last->block->symbols[k] = formBlock.last->block->Marker;
    formBlock.head = nullptr;
    formBlock.last = nullptr;

    if (form.head != nullptr) {
        form.last->next = temp;
        form.last = form.last->next;
    } else {
        form.head = temp;
        form.last = form.head;
    }
}

int LineCount(fstream &input_file) {
    //----------------------------------------------------------------------------------Находит количество строк в файле
    char trash = 0;
    int line_count = 0, position = 0;
    position = input_file.tellg();

    while (!input_file.eof()) {
        input_file >> trash;
        if (trash == '\n')
            line_count++;
    }
    line_count++;
    input_file.clear();
    input_file.seekg(position);

    return line_count;
}

int BlocksInLine(int symbols_count) {
    //------------------------------------------------------------Находит количество блоков, в которое поместится строка
    int should_be_blocks = 0;
    bool is_odd = false;
    const unsigned size_of_block = 5;
    symbols_count++;
    if (symbols_count % 5 != 0) {
        is_odd = true;
    }
    should_be_blocks = symbols_count / size_of_block;
    if (is_odd) {
        should_be_blocks++;
    }

    return should_be_blocks;
}

int SymbolsCount(fstream &input_file, char temp) {
    //------------------------------------------------------------------------Находит количество символов в строке файла
    int symbols_count = 0;
    do {
        input_file >> temp;
        if (input_file.eof() || (temp == '\n'))
            break;
        if (temp == '\r')
            symbols_count--;
        symbols_count++;
    } while (true);

    return symbols_count;
}

bool CheckFile(fstream &input_file) {
    //----------------------------------------------------------------------------------------------------Проверка файла
    int position = 0;
    position = input_file.tellg();

    if (!input_file.is_open()) {
        cout << "Произошла ошибка открытия файла" << endl;
        return false;
    } else {
        long file_size;
        input_file.seekg(0, ios::end);
        file_size = input_file.tellg();
        if (file_size == 0) {
            cout << "А файл то пуст :D" << endl;
            return false;
        }
    }
    input_file.clear();
    input_file.seekg(position);
    return true;
}

void PrintForm(Form &form1) { // Надо дописать
    fstream output_file;
    output_file.open("output_file.txt", std::ios::out);

    auto temp = form1.head;
    auto temp1 = form1.head->line;
    output_file << "Первый список: " << endl;
    while (temp != nullptr) {
        for (int i = 0; temp1->block->symbols[i] != temp1->block->Marker; i++) {
            output_file << temp1->block->symbols[i];
            if (i == 4) {
                temp1 = temp1->next;
                i = -1;
            }
        }
        output_file << endl;
        temp = temp->next;
        if (temp != nullptr)
            temp1 = temp->line;
    }

    output_file.close();
}

void DeleteList(Form &form) {
    //-----------------------------------------------------------------------------------------------------Удаляет спиок
    while (form.head != nullptr) {
        form.current = form.head->next;
        delete form.head;
        form.head = form.current;
    }
    delete form.head;
    delete form.current;
    form.last = nullptr;
}
