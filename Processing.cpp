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

void jobSeekerMode(JobInfo &jobInfo, JobSeeker &jobSeeker) { //TODO добавить заполнение списка, поменять файл
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.surname, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.surname, symbolsCount, blocksCount, transitLine);
        jobInfo.surname.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.surname, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.name, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.name, symbolsCount, blocksCount, transitLine);
        jobInfo.name.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.name, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.patronymic, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.patronymic, symbolsCount, blocksCount, transitLine);
        jobInfo.patronymic.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.patronymic, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.position, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.position, symbolsCount, blocksCount, transitLine);
        jobInfo.position.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.position, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.fieldOfActivity, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.workExperience, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.workExperience, symbolsCount, blocksCount, transitLine);
        jobInfo.workExperience.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.workExperience, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.education, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.education, symbolsCount, blocksCount, transitLine);
        jobInfo.education.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.education, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.schedule, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transitLine);
        jobInfo.schedule.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.schedule, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.salary, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.salary, symbolsCount, blocksCount, transitLine);
        jobInfo.salary.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.salary, transitLine, symbolsCount);
    delete[] transitLine;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void employerMode(JobInfo &jobInfo, Employer &employer) { //TODO добавить заполнение списка
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0;
    inputFile.open("../cmake-build-debug/EmployerMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.title, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.title, symbolsCount, blocksCount, transitLine);
        jobInfo.title.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.address, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.address, symbolsCount, blocksCount, transitLine);
        jobInfo.address.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.phoneNumber, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.phoneNumber, symbolsCount, blocksCount, transitLine);
        jobInfo.phoneNumber.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.position, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.position, symbolsCount, blocksCount, transitLine);
        jobInfo.position.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.schedule, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transitLine);
        jobInfo.schedule.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.salary, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.salary, symbolsCount, blocksCount, transitLine);
        jobInfo.salary.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.education, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.education, symbolsCount, blocksCount, transitLine);
        jobInfo.education.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.workExperience, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.workExperience, symbolsCount, blocksCount, transitLine);
        jobInfo.workExperience.last->symbolsInLine = symbolsCount;
    }
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.title, transitLine, symbolsCount)) {
        cout << "Такой компании нет в базе данных" << endl; //TODO довести до ума
    }
    delete[] transitLine;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void addingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy) {
    int way = 0;
    cout << "1 - Соискателя\n"
         << "2 - Работодателя\n"
         << "3 - Вакансии\n"
         << endl;
    cin >> way;
    switch (way) {
        case 1:
            add(jobInfo, jobSeeker);
            cout << "Соискатель добавлен" << endl;
            break;
        case 2:
            add(jobInfo, employer);
            cout << "Работодатель добавлен" << endl;
            break;
        case 3:
            add(jobInfo, vacancy);
            cout << "Вакансия добавлена" << endl;
            break;
        default:
            cout << "Неправильный ввод" << endl;
    }
}

void satisfiedVacancyMode(Vacancy &satisfiedVacancy) {

}

void add(JobInfo &jobInfo, JobSeeker &jobSeeker) { //TODO добавить заполнение списка
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    jobSeeker.makeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.surname, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.surname, symbolsCount, blocksCount, transitLine);
        jobInfo.surname.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.surname, transitLine, symbolsCount);
    jobSeeker.last->surname = returnPointToRequiredInfo(jobInfo.surname, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.name, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.name, symbolsCount, blocksCount, transitLine);
        jobInfo.name.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.name, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.patronymic, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.patronymic, symbolsCount, blocksCount, transitLine);
        jobInfo.patronymic.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.patronymic, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.position, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.position, symbolsCount, blocksCount, transitLine);
        jobInfo.position.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.position, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.fieldOfActivity, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.workExperience, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.workExperience, symbolsCount, blocksCount, transitLine);
        jobInfo.workExperience.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.workExperience, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.education, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.education, symbolsCount, blocksCount, transitLine);
        jobInfo.education.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.education, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.schedule, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transitLine);
        jobInfo.schedule.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.schedule, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.salary, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.salary, symbolsCount, blocksCount, transitLine);
        jobInfo.salary.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.salary, transitLine, symbolsCount);
    delete[] transitLine;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void add(JobInfo &jobInfo, Employer &employer) { //TODO добавить заполнение списка
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    employer.MakeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.title, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.title, symbolsCount, blocksCount, transitLine);
        jobInfo.title.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.title, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.fieldOfActivity, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.address, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.address, symbolsCount, blocksCount, transitLine);
        jobInfo.address.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.address, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.phoneNumber, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.phoneNumber, symbolsCount, blocksCount, transitLine);
        jobInfo.phoneNumber.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.phoneNumber, transitLine, symbolsCount);
    delete[] transitLine;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void add(JobInfo &jobInfo, Vacancy &vacancy) { //TODO добавить заполнение списка
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    vacancy.makeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.position, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.position, symbolsCount, blocksCount, transitLine);
        jobInfo.position.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.position, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.schedule, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transitLine);
        jobInfo.schedule.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.schedule, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.salary, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.salary, symbolsCount, blocksCount, transitLine);
        jobInfo.salary.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.salary, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.education, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.education, symbolsCount, blocksCount, transitLine);
        jobInfo.education.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.education, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.fieldOfActivity, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.workExperience, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.workExperience, symbolsCount, blocksCount, transitLine);
        jobInfo.workExperience.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.workExperience, transitLine, symbolsCount);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile, temp);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    inputFile >> temp;
    if (!wordIsInList(jobInfo.title, transitLine, symbolsCount)) {
        cout << "Такой компании нет в базе данных" << endl;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.title, transitLine, symbolsCount);
    delete[] transitLine;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

List1 *returnPointToRequiredInfo(Form &inJobInfo, int nodeNumber) {
    inJobInfo.current = inJobInfo.head;
    for (int i = 0; i < nodeNumber; i++) {
        if (i == nodeNumber - 1) {
            break;
        }
        inJobInfo.current = inJobInfo.current->next;
    }
    return inJobInfo.current;
}

int findNumberOfNecessaryNode(Form &inJobInfo, const char *tempLine, int sizeOfTemp) {
    //---------------------------------------------------------------------Находит номер узла, в котором лежит tempLine
    FormBlock tempFormBlock;
    inJobInfo.current = inJobInfo.head;
    tempFormBlock.current = inJobInfo.current->line;
    int nodeNumber = 0;
    bool wordIsAlreadyInList = false, wordFits = true;
    int k = 0;
    while (inJobInfo.current != nullptr) {
        if (inJobInfo.current->symbolsInLine == sizeOfTemp) {
            nodeNumber++;
            for (int i = 0; i < sizeOfTemp; i++, k++) {
                if (tempFormBlock.current->block->symbols[k] != tempLine[i]) {
                    inJobInfo.current = inJobInfo.current->next;
                    tempFormBlock.current = inJobInfo.current->line;
                    wordFits = false;
                    break;
                }
                if ((k + 1) % 5 == 0) {
                    tempFormBlock.current = tempFormBlock.current->next;
                    k = -1; // Из за инкрементирования в начале каждой итерации
                }
            }
            if (wordFits) {
                wordIsAlreadyInList = true;
                break;
            }
            wordFits = true;
            k = 0;
        } else {
            inJobInfo.current = inJobInfo.current->next;
            if (inJobInfo.current == nullptr)
                break;
            tempFormBlock.current = inJobInfo.current->line;
            nodeNumber++;
        }
    }
    return nodeNumber;
}

bool wordIsInList(Form &inJobInfo, const char *tempLine, int sizeOfTemp) {
    //-------------------------------------------------------------------Проверяет, есть ли в inJobInfo строка tempLine
    FormBlock tempFormBlock;
    inJobInfo.current = inJobInfo.head;
    tempFormBlock.current = inJobInfo.current->line;
    bool wordIsAlreadyInList = false, wordFits = true;
    int k = 0;
    while (inJobInfo.current != nullptr) {
        if (inJobInfo.current->symbolsInLine == sizeOfTemp) {
            for (int i = 0; i < sizeOfTemp; i++, k++) {
                if (tempFormBlock.current->block->symbols[k] != tempLine[i]) {
                    inJobInfo.current = inJobInfo.current->next;
                    tempFormBlock.current = inJobInfo.current->line;
                    wordFits = false;
                    break;
                }
                if ((k + 1) % 5 == 0) {
                    tempFormBlock.current = tempFormBlock.current->next;
                    k = -1; // Из за инкрементирования в начале каждой итерации
                }
            }
            if (wordFits) {
                wordIsAlreadyInList = true;
                break;
            }
            wordFits = true;
            k = 0;
        } else {
            inJobInfo.current = inJobInfo.current->next;
            if (inJobInfo.current == nullptr)
                break;
            tempFormBlock.current = inJobInfo.current->line;
        }
    }
    return wordIsAlreadyInList;
}

void getInfoFromFile(Form &form, fstream &inputFile) {
    //--------------------------------------------------------------------------------------------Чтение данных из файла
    char temp = 0;
    int symbolsCount = 0, blocksCount = 0, lineCountFromInput = 0;
    if (!checkFile(inputFile)) {
        inputFile.close();
        exit(1);
    }

    inputFile.unsetf(ios::skipws);
    int position = 0;
    lineCountFromInput = lineCount(inputFile);
    for (int i = 0; i < lineCountFromInput; i++) {
        position = inputFile.tellg();
        symbolsCount = countSymbols(inputFile, temp);
        blocksCount = countBlocksInLine(symbolsCount);
        auto transitLine = new char[symbolsCount + 1];
        for (int j = 0; j < symbolsCount + 1; j++)
            transitLine[j] = 0;
        inputFile.clear();
        inputFile.seekg(position);
        for (int j = 0; j < symbolsCount; j++)
            inputFile >> transitLine[j];
        inputFile >> temp;
        inputOneLine(form, symbolsCount, blocksCount, transitLine);
        form.last->symbolsInLine = symbolsCount;
        delete[] transitLine;
    }

    inputFile.setf(ios::skipws);
}

void inputOneLine(Form &form, int symbolsCount, int blocksCount, const char *transitLine) {
    //--------------------------------------------------------------------------Записывает в список одну строку из файла
    FormBlock formBlock;
    auto *temp = new List1;

    int j = 0;
    int k = 0;
    for (int i = 0; i < blocksCount; i++) {
        auto *temp1 = new BlocksList;
        temp1->block = new LineWithMarker;
        temp1->block->symbols = new char[temp1->max_symbols_in_block];
        for (int b = 0; b < temp1->max_symbols_in_block + 1; b++)
            temp1->block->symbols[b] = 0;
        k = 0;
        if (symbolsCount - j == 1 && symbolsCount % 5 == 0) { // Для записи толлько одного маркер
            j += 2;
        }
        for (; k < temp1->max_symbols_in_block && j < symbolsCount; j++) {
            temp1->block->symbols[k] = transitLine[j];
            k++;
            if (j + 1 >= symbolsCount) {
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
    formBlock.last->block->symbols[k] = formBlock.last->block->marker;
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

int lineCount(fstream &inputFile) {
    //----------------------------------------------------------------------------------Находит количество строк в файле
    char trash = 0;
    int lineCount = 0, position = 0;
    position = inputFile.tellg();

    while (!inputFile.eof()) {
        inputFile >> trash;
        if (trash == '\n')
            lineCount++;
    }
    lineCount++;
    inputFile.clear();
    inputFile.seekg(position);

    return lineCount;
}

int countBlocksInLine(int symbolsCount) {
    //------------------------------------------------------------Находит количество блоков, в которое поместится строка
    int shouldBeBlocks = 0;
    bool isOdd = false;
    const unsigned sizeOfBlock = 5;
    symbolsCount++;
    if (symbolsCount % 5 != 0) {
        isOdd = true;
    }
    shouldBeBlocks = symbolsCount / sizeOfBlock;
    if (isOdd) {
        shouldBeBlocks++;
    }

    return shouldBeBlocks;
}

int countSymbols(fstream &inputFile, char temp) {
    //------------------------------------------------------------------------Находит количество символов в строке файла
    int symbolsCount = 0;
    do {
        inputFile >> temp;
        if (inputFile.eof() || (temp == '\n'))
            break;
        if (temp == '\r')
            symbolsCount--;
        symbolsCount++;
    } while (true);

    return symbolsCount;
}

bool checkFile(fstream &inputFile) {
    //----------------------------------------------------------------------------------------------------Проверяет файл
    int position = 0;
    position = inputFile.tellg();

    if (!inputFile.is_open()) {
        cout << "Произошла ошибка открытия файла" << endl;
        return false;
    } else {
        long file_size;
        inputFile.seekg(0, ios::end);
        file_size = inputFile.tellg();
        if (file_size == 0) {
            cout << "А файл то пуст :D" << endl;
            return false;
        }
    }
    inputFile.clear();
    inputFile.seekg(position);
    return true;
}

void printForm(Form &form) { // Надо дописать
    fstream outputFile;
    outputFile.open("output_file.txt", std::ios::out);

    auto temp = form.head;
    auto temp1 = form.head->line;
    outputFile << "Первый список: " << endl;
    while (temp != nullptr) {
        for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
            outputFile << temp1->block->symbols[i];
            if (i == 4) {
                temp1 = temp1->next;
                i = -1;
            }
        }
        outputFile << endl;
        temp = temp->next;
        if (temp != nullptr)
            temp1 = temp->line;
    }

    outputFile.close();
}

void deleteList(Form &form) {
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
