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

void addFirstInfo(Vacancy &vacancy, Employer &employer, JobSeeker &jobSeeker, JobInfo &jobInfo, fstream &protocolFile) {
    //----------------------------------------------------------Вносит первоначальные Вакансии/Соискателей/Работодателей
    //-----------------------------------------------------------------Выводит все первоначальные данные в выходной файл
    fstream inputFile;
    char temp = 0;
    inputFile.open("../cmake-build-debug/FirstInfo.txt", ios::in);
    inputFile.unsetf(ios::skipws);

    for (int i = 0; i < 10; i++) {
        add(jobInfo, vacancy, inputFile);
        inputFile >> temp;
        if (temp == '\r') {
            inputFile >> temp;
        }
    }
    inputFile >> temp;
    if (temp == '\r') {
        inputFile >> temp;
    }
    for (int i = 0; i < 10; i++) {
        add(jobInfo, employer, inputFile);
        inputFile >> temp;
        if (temp == '\r') {
            inputFile >> temp;
        }
    }
    inputFile >> temp;
    if (temp == '\r') {
        inputFile >> temp;
    }
    for (int i = 0; i < 10; i++) {
        add(jobInfo, jobSeeker, inputFile);
        inputFile >> temp;
        if (temp == '\r') {
            inputFile >> temp;
        }
    }

    protocolFile << "Исходные данные по работе: " << endl;
    protocolFile << "Адреса: " << endl;
    printForm(jobInfo.address, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Образование: " << endl;
    printForm(jobInfo.education, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Сферы деятельности: " << endl;
    printForm(jobInfo.fieldOfActivity, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Номера телефонов: " << endl;
    printForm(jobInfo.phoneNumber, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Должности: " << endl;
    printForm(jobInfo.position, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Оклады: " << endl;
    printForm(jobInfo.salary, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Графики работы: " << endl;
    printForm(jobInfo.schedule, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Названия: " << endl;
    printForm(jobInfo.title, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Опыт работы: " << endl;
    printForm(jobInfo.workExperience, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Фамилии: " << endl;
    printForm(jobInfo.surname, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Имена: " << endl;
    printForm(jobInfo.name, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Отчества: " << endl;
    printForm(jobInfo.patronymic, protocolFile);
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << endl;

    protocolFile << "Первоначальные вакансии: " << endl;
    for (int k = 1; k <= 10; k++) {
        vacancy.printVacancy(k, protocolFile);
        protocolFile << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Первоначальные работодатели: " << endl;
    for (int k = 1; k <= 10; k++) {
        employer.printEmployer(k, protocolFile);
        protocolFile << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Первоначальные соискатели: " << endl;
    for (int k = 1; k <= 10; k++) {
        jobSeeker.printJobSeeker(k, protocolFile);
        protocolFile << endl;
    }
    protocolFile << endl;
    protocolFile << endl;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void jobSeekerMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Vacancy &vacancy,
                   Vacancy &listOfSatisfiedVacancy) { //TODO добавить поиск нужных вакансий
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/JobSeekerMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    add(jobInfo, jobSeeker, inputFile);
    jobSeeker.current = jobSeeker.last;
    findRequiredVacancy(jobSeeker.current, vacancy, listOfSatisfiedVacancy);

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void findRequiredVacancy(NodeJobSeeker *currentJobSeeker, Vacancy &vacancy, Vacancy &listOfSatisfiedVacancy) {
    cout << "Режим в разработке" << endl;
    vacancy.current = vacancy.head;
    while (vacancy.current != nullptr) {
        if (currentJobSeeker->fieldOfActivity == vacancy.current->fieldOfActivity &&
            currentJobSeeker->workExperience == vacancy.current->workExperience &&
            currentJobSeeker->position == vacancy.current->position &&
            currentJobSeeker->schedule == vacancy.current->schedule &&
            currentJobSeeker->salary == vacancy.current->salary &&
            currentJobSeeker->education == vacancy.current->education) {

            listOfSatisfiedVacancy.makeNewNode();
            listOfSatisfiedVacancy.last = vacancy.current;
            listOfSatisfiedVacancy.last->vacant = 'n'; // 'n' значит занята, когда свободна 'y'
        }
        if (currentJobSeeker->fieldOfActivity == vacancy.current->fieldOfActivity &&
            currentJobSeeker->workExperience == vacancy.current->workExperience &&
            currentJobSeeker->position == vacancy.current->position) {


        }
    }
}

void employerMode(JobInfo &jobInfo, Employer &employer, JobSeeker &jobSeeker, Vacancy &vacancy,
                  Vacancy &listOfSatisfiedVacancy) { //TODO добавить поиск нужных соискателей
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/EmployerMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    add(jobInfo, employer, inputFile);
    inputFile >> temp;
    if (temp == '\r') {
        inputFile >> temp;
    }
    add(jobInfo, vacancy, inputFile);
    vacancy.current = vacancy.last;
    findRequiredJobSeeker(vacancy.current, jobSeeker, listOfSatisfiedVacancy);

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void findRequiredJobSeeker(NodeVacancy *currentVacancy, JobSeeker &jobSeeker, Vacancy &listOfSatisfiedVacancy) {
    cout << "Режим в разработке" << endl;
    jobSeeker.current = jobSeeker.head;
    while (jobSeeker.current != nullptr) {

    }
}

void addingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy) {
    //-----------------------------------------------------------------Режим добавления соискателя/работодателя/вакансии
    fstream inputFile;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int way = 0;
    cout << "1 - Соискателя\n"
         << "2 - Работодателя\n"
         << "3 - Вакансии\n"
         << endl;
    cin >> way;
    switch (way) {
        case 1:
            cout << "Ввод будет осуществлен таким образом: \n"
                 << "Фамилия \n"
                 << "Имя \n"
                 << "Отчество \n"
                 << "Должность \n"
                 << "Область деятельности \n"
                 << "Опыт \n"
                 << "Образование \n"
                 << "График \n"
                 << "Заработная плата \n"
                 << endl;
            add(jobInfo, jobSeeker, inputFile);
            cout << "Соискатель добавлен \n" << endl;
            break;
        case 2:
            cout << "Ввод будет осуществлен таким образом: \n"
                 << "Название \n"
                 << "Область деятельности \n"
                 << "Адресс \n"
                 << "Телефон \n"
                 << endl;
            add(jobInfo, employer, inputFile);
            cout << "Работодатель добавлен \n" << endl;
            break;
        case 3:
            cout << "Ввод будет осуществлен таким образом: \n"
                 << "Должность \n"
                 << "График \n"
                 << "Зарплата \n"
                 << "Образование \n"
                 << "Область деятельности \n"
                 << "Опыт \n"
                 << "Предложения компаний \n"
                 << endl;
            add(jobInfo, vacancy, inputFile);
            cout << "Вакансия добавлена \n" << endl;
            break;
        default:
            cout << "Неправильный ввод \n" << endl;
    }
    inputFile.setf(ios::skipws);
    inputFile.close();
}

void satisfiedVacancyMode(Vacancy &satisfiedVacancy) {

}

void add(JobInfo &jobInfo, JobSeeker &jobSeeker, fstream &inputFile) {
    //----------------------------------------------------------------------Добавляет соискателя из файла AddingMode.txt
    //------------------------------------------------------Если таких данных нет в JobInfo, то они будут туда добавлены
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    int position = 0;

    jobSeeker.makeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->name = returnPointToRequiredInfo(jobInfo.name, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->patronymic = returnPointToRequiredInfo(jobInfo.patronymic, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->position = returnPointToRequiredInfo(jobInfo.position, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->fieldOfActivity = returnPointToRequiredInfo(jobInfo.fieldOfActivity, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->workExperience = returnPointToRequiredInfo(jobInfo.workExperience, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->education = returnPointToRequiredInfo(jobInfo.education, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->schedule = returnPointToRequiredInfo(jobInfo.schedule, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    jobSeeker.last->salary = returnPointToRequiredInfo(jobInfo.salary, nodeNumber);
    delete[] transitLine;
}

void add(JobInfo &jobInfo, Employer &employer, fstream &inputFile) {
    //--------------------------------------------------------------------Добавляет работодателя из файла AddingMode.txt
    //------------------------------------------------------Если таких данных нет в JobInfo, то они будут туда добавлены
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    int position = 0;

    employer.MakeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    employer.last->title = returnPointToRequiredInfo(jobInfo.title, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    employer.last->fieldOfActivity = returnPointToRequiredInfo(jobInfo.fieldOfActivity, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    employer.last->address = returnPointToRequiredInfo(jobInfo.address, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
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
    employer.last->phoneNumber = returnPointToRequiredInfo(jobInfo.phoneNumber, nodeNumber);
    delete[] transitLine;
}

void add(JobInfo &jobInfo, Vacancy &vacancy, fstream &inputFile) {
    //------------------------------------------------------------------------Добавляет вакансию из файла AddingMode.txt
    //------------------------------------------------------Если таких данных нет в JobInfo, то они будут туда добавлены
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    int position = 0;

    vacancy.makeNewNode();
    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    auto transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.position, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.position, symbolsCount, blocksCount, transitLine);
        jobInfo.position.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.position, transitLine, symbolsCount);
    vacancy.last->position = returnPointToRequiredInfo(jobInfo.position, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.schedule, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.schedule, symbolsCount, blocksCount, transitLine);
        jobInfo.schedule.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.schedule, transitLine, symbolsCount);
    vacancy.last->schedule = returnPointToRequiredInfo(jobInfo.schedule, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.salary, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.salary, symbolsCount, blocksCount, transitLine);
        jobInfo.salary.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.salary, transitLine, symbolsCount);
    vacancy.last->salary = returnPointToRequiredInfo(jobInfo.salary, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.education, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.education, symbolsCount, blocksCount, transitLine);
        jobInfo.education.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.education, transitLine, symbolsCount);
    vacancy.last->education = returnPointToRequiredInfo(jobInfo.education, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.fieldOfActivity, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.fieldOfActivity, symbolsCount, blocksCount, transitLine);
        jobInfo.fieldOfActivity.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.fieldOfActivity, transitLine, symbolsCount);
    vacancy.last->fieldOfActivity = returnPointToRequiredInfo(jobInfo.fieldOfActivity, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.workExperience, transitLine, symbolsCount)) {
        inputOneLine(jobInfo.workExperience, symbolsCount, blocksCount, transitLine);
        jobInfo.workExperience.last->symbolsInLine = symbolsCount;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.workExperience, transitLine, symbolsCount);
    vacancy.last->workExperience = returnPointToRequiredInfo(jobInfo.workExperience, nodeNumber);
    delete[] transitLine;

    position = inputFile.tellg();
    symbolsCount = countSymbols(inputFile);
    blocksCount = countBlocksInLine(symbolsCount);
    transitLine = new char[symbolsCount + 1];
    for (int j = 0; j < symbolsCount + 1; j++)
        transitLine[j] = 0;
    inputFile.clear();
    inputFile.seekg(position);
    for (int j = 0; j < symbolsCount; j++)
        inputFile >> transitLine[j];
    inputFile >> temp;
    if (temp == '\r')
        inputFile >> temp;
    if (!wordIsInList(jobInfo.title, transitLine, symbolsCount)) {
        cout << "Такой компании нет в базе данных" << endl;
    }
    nodeNumber = findNumberOfNecessaryNode(jobInfo.title, transitLine, symbolsCount);
    //-----------------------TODO добавить возможность в вакансии ссылаться на нескольких работодателей. Доп. функционал
    vacancy.last->employerApplications = returnPointToRequiredInfo(jobInfo.title, nodeNumber);
    delete[] transitLine;
}

List1 *returnPointToRequiredInfo(Form &inJobInfo, int nodeNumber) {
    //-----------------------------------------------------------------Возвращает указатель на узел с номером nodeNumber
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
    //----------------------------------------------------------------------Находит номер узла, в котором лежит tempLine
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
                if (tempFormBlock.current->block->symbols[k] != tempLine[i] && inJobInfo.current->next != nullptr) {
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
    //--------------------------------------------------------------------Проверяет, есть ли в inJobInfo строка tempLine
    FormBlock tempFormBlock;
    inJobInfo.current = inJobInfo.head;
    tempFormBlock.current = inJobInfo.current->line;
    bool wordIsAlreadyInList = false, wordFits = true;
    int k = 0;
    while (inJobInfo.current != nullptr) {
        if (inJobInfo.current->symbolsInLine == sizeOfTemp) {
            for (int i = 0; i < sizeOfTemp; i++, k++) {
                if (tempFormBlock.current->block->symbols[k] != tempLine[i] && inJobInfo.current->next != nullptr) {
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
        symbolsCount = countSymbols(inputFile);
        blocksCount = countBlocksInLine(symbolsCount);
        auto transitLine = new char[symbolsCount + 1];
        for (int j = 0; j < symbolsCount + 1; j++)
            transitLine[j] = 0;
        inputFile.clear();
        inputFile.seekg(position);
        for (int j = 0; j < symbolsCount; j++)
            inputFile >> transitLine[j];
        inputFile >> temp;
        if (temp == '\r') {
            inputFile >> temp;
        }
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

int countSymbols(fstream &inputFile) {
    //------------------------------------------------------------------------Находит количество символов в строке файла
    char temp = 0;
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

void printForm(Form &form, fstream &outputFile) {
    auto temp = form.head;
    auto temp1 = form.head->line;
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
