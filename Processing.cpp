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
                   Vacancy &listOfSatisfiedVacancy, fstream &outputFile) {
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/JobSeekerMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int position = 0;

    add(jobInfo, jobSeeker, inputFile);
    jobSeeker.current = jobSeeker.last;

    outputFile << "Работа режима соискателя: " << endl;
    findRequiredVacancy(jobSeeker.current, vacancy, listOfSatisfiedVacancy, outputFile);
    outputFile << endl;
    outputFile << endl;

    inputFile.setf(ios::skipws);
    inputFile.close();
}

void findRequiredVacancy(NodeJobSeeker *currentJobSeeker, Vacancy &vacancy, Vacancy &listOfSatisfiedVacancy,
                         fstream &outputFile) {
    char temp = 0;
    int k = 1; // Для счетчиа вакансий
    NodeVacancy *previousVacancy = nullptr;
    vacancy.current = vacancy.head;
    while (vacancy.current != nullptr) {
        if (currentJobSeeker->fieldOfActivity == vacancy.current->fieldOfActivity &&
            currentJobSeeker->workExperience == vacancy.current->workExperience &&
            currentJobSeeker->position == vacancy.current->position &&
            currentJobSeeker->schedule == vacancy.current->schedule &&
            currentJobSeeker->salary == vacancy.current->salary &&
            currentJobSeeker->education == vacancy.current->education) {

            outputFile << "Подошела вакансия" << endl;
            vacancy.printVacancy(k, outputFile);
            outputFile << endl;

            if (listOfSatisfiedVacancy.head != nullptr) {
                listOfSatisfiedVacancy.last->next = vacancy.current;
                listOfSatisfiedVacancy.last->next->vacant = 'n'; // 'n' значит занята, свободна 'y'
                listOfSatisfiedVacancy.last = vacancy.current;
                listOfSatisfiedVacancy.last->next = nullptr;
            } else {
                listOfSatisfiedVacancy.head = listOfSatisfiedVacancy.last = vacancy.current;
                listOfSatisfiedVacancy.head->vacant = 'n'; // 'n' значит занята, свободна 'y'
            }

            if (vacancy.current == vacancy.last) {
                vacancy.last = previousVacancy;
                previousVacancy->next = nullptr;
                break;
            } else if (previousVacancy != nullptr) {
                previousVacancy->next = vacancy.current->next;
                vacancy.current->next = nullptr;
                vacancy.current = previousVacancy->next;
                continue;
            } else {
                vacancy.head = vacancy.current->next;
                vacancy.current->next = nullptr;
                continue;
            }
        } else if (currentJobSeeker->fieldOfActivity == vacancy.current->fieldOfActivity &&
                   currentJobSeeker->workExperience == vacancy.current->workExperience &&
                   currentJobSeeker->position == vacancy.current->position) {

            cout << "Найдена вакансия, которая практически вам подходит. Желаете ее занять? y/n" << endl;
            cin >> temp;
            vacancy.current->vacant = (temp = 'y') ? 'n' : 'y';
            if (vacancy.current->vacant == 'n') {

                outputFile << "Подошела вакансия" << endl;
                vacancy.printVacancy(k, outputFile);
                outputFile << endl;

                if (listOfSatisfiedVacancy.head != nullptr) {
                    listOfSatisfiedVacancy.last->next = vacancy.current;
                    listOfSatisfiedVacancy.last = vacancy.current;
                    listOfSatisfiedVacancy.last->next = nullptr;
                } else {
                    listOfSatisfiedVacancy.head = listOfSatisfiedVacancy.last = vacancy.current;
                }

                if (vacancy.current == vacancy.last) {
                    vacancy.last = previousVacancy;
                    previousVacancy->next = nullptr;
                    k++;
                    break;
                } else if (previousVacancy != nullptr) {
                    previousVacancy->next = vacancy.current->next;
                    vacancy.current->next = nullptr;
                    vacancy.current = previousVacancy->next;
                    k++;
                    continue;
                } else {
                    vacancy.head = vacancy.current->next;
                    vacancy.current->next = nullptr;
                    k++;
                    continue;
                }
            }
        }
        previousVacancy = vacancy.current; // Хранит адрес предыдущего элемента
        vacancy.current = previousVacancy->next;
        k++;
    }
}

void employerMode(JobInfo &jobInfo, Employer &employer, JobSeeker &jobSeeker, Vacancy &vacancy,
                  Vacancy &listOfSatisfiedVacancy, fstream &outputFile) {
    fstream inputFile;
    char temp = 0;
    int blocksCount = 0, symbolsCount = 0, nodeNumber = 0;
    inputFile.open("../cmake-build-debug/EmployerMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);

    add(jobInfo, employer, inputFile);
    inputFile >> temp;
    if (temp == '\r') {
        inputFile >> temp;
    }
    vacancy.current = vacancy.last; //Для того, чтобы сохранить предыдущий элемент, после добавления вакансии
    add(jobInfo, vacancy, inputFile);
    inputFile.setf(ios::skipws);
    inputFile.close();

    outputFile << "Работа режима работодателя: " << endl;
    findRequiredJobSeeker(vacancy, jobSeeker, listOfSatisfiedVacancy, outputFile);
    outputFile << endl;
    outputFile << endl;
}

void
findRequiredJobSeeker(Vacancy &vacancy, JobSeeker &jobSeeker, Vacancy &listOfSatisfiedVacancy, fstream &outputFile) {
    char temp = 0;
    int k = 1; // Для счетчика соискателей
    NodeVacancy *previousVacancy = vacancy.current;
    vacancy.current = vacancy.last;
    jobSeeker.current = jobSeeker.head;
    while (jobSeeker.current != nullptr) {
        if (vacancy.current->fieldOfActivity == jobSeeker.current->fieldOfActivity &&
            vacancy.current->workExperience == jobSeeker.current->workExperience &&
            vacancy.current->position == jobSeeker.current->position &&
            vacancy.current->schedule == jobSeeker.current->schedule &&
            vacancy.current->salary == jobSeeker.current->salary &&
            vacancy.current->education == jobSeeker.current->education) {

            outputFile << "Подошел соискатель " << endl;
            jobSeeker.printJobSeeker(k, outputFile);
            outputFile << endl;

            if (vacancy.current->vacant == 'y') {
                if (listOfSatisfiedVacancy.head != nullptr) {
                    listOfSatisfiedVacancy.last->next = vacancy.current;
                    listOfSatisfiedVacancy.last->next->vacant = 'n'; // 'n' значит занята, свободна 'y'
                    listOfSatisfiedVacancy.last = vacancy.current;
                    listOfSatisfiedVacancy.last->next = nullptr;
                } else {
                    listOfSatisfiedVacancy.head = listOfSatisfiedVacancy.last = vacancy.current;
                    listOfSatisfiedVacancy.head->vacant = 'n'; // 'n' значит занята, свободна 'y'
                }
                vacancy.last = previousVacancy;
                previousVacancy->next = nullptr;
            }

        } else if (vacancy.current->fieldOfActivity == jobSeeker.current->fieldOfActivity &&
                   vacancy.current->workExperience == jobSeeker.current->workExperience &&
                   vacancy.current->position == jobSeeker.current->position) {

            cout << "Найден соискатель, который практически вам подходит. Желаете занять его? y/n" << endl;
            cin >> temp;

            if (temp == 'y') {
                outputFile << "Подошел соискатель " << endl;
                jobSeeker.printJobSeeker(k, outputFile);
                outputFile << endl;

                if (vacancy.current->vacant == 'y') {
                    if (listOfSatisfiedVacancy.head != nullptr) {
                        listOfSatisfiedVacancy.last->next = vacancy.current;
                        listOfSatisfiedVacancy.last->next->vacant = 'n'; // 'n' значит занята, свободна 'y'
                        listOfSatisfiedVacancy.last = vacancy.current;
                        listOfSatisfiedVacancy.last->next = nullptr;
                    } else {
                        listOfSatisfiedVacancy.head = listOfSatisfiedVacancy.last = vacancy.current;
                        listOfSatisfiedVacancy.head->vacant = 'n'; // 'n' значит занята, свободна 'y'
                    }
                    vacancy.last = previousVacancy;
                    previousVacancy->next = nullptr;
                }
            }
        }
        jobSeeker.current = jobSeeker.current->next;
        k++;
    }

    if (vacancy.current->vacant == 'y') {
        outputFile << "К сожалению, по вашему запросу нет подходящих соискателей" << endl;
    }
}

void addingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy) {
    //-----------------------------------------------------------------Режим добавления соискателя/работодателя/вакансии
    fstream inputFile;
    inputFile.open("../cmake-build-debug/AddingMode.txt", ios::in);
    inputFile.unsetf(ios::skipws);
    int way = 0;
    bool stop = false;

    while (!stop) {
        cout << "1 - Соискателя\n"
             << "2 - Работодателя\n"
             << "3 - Вакансии\n"
             << "4 - Выход\n"
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
                stop = true;
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
                stop = true;
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
                stop = true;
                break;
            case 4:
                cout << "Выход" << endl;
                stop = true;
                break;
            default:
                cout << "Попробуйте снова" << endl;
                continue;
        }
    }
    inputFile.setf(ios::skipws);
    inputFile.close();
}

void satisfiedVacancyMode(Vacancy &satisfiedVacancy) {
    fstream outputFile;
    int k = 1; // Счетчик узлов
    outputFile.open("satisfiedVacancyFile.txt", ios::out);

    satisfiedVacancy.current = satisfiedVacancy.head;
    if (satisfiedVacancy.head == nullptr) {
        cout << "Удовлетворенных вакансий еще нет " << endl;
        outputFile << "Удовлетворенных вакансий еще нет " << endl;
    } else {
        outputFile << "Удовлетворенные вакансии: " << endl;
        while (satisfiedVacancy.current != nullptr) {
            satisfiedVacancy.printVacancy(k, outputFile);
            outputFile << endl;
            k++;
            satisfiedVacancy.current = satisfiedVacancy.current->next;
        }
    }

    outputFile.close();
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

void
outputProtocol(JobInfo &jobInfo, Vacancy &vacancy, JobSeeker &jobSeeker, Employer &employer, fstream &protocolFile) {
    List1 *temp;
    BlocksList *temp1;
    protocolFile << "Данные по работе, добавленые во время работы программы: " << endl;

    protocolFile << "Адреса: " << endl;
    int v = 0;
    jobInfo.address.current = jobInfo.address.head;
    while (v != 10) {
        jobInfo.address.current = jobInfo.address.current->next;
        v++;
    }

    if(jobInfo.address.current != nullptr) {
        temp = jobInfo.address.current;
        temp1 = jobInfo.address.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Образование: " << endl;

    v = 0;
    jobInfo.education.current = jobInfo.education.head;
    while (v != 3) {
        jobInfo.education.current = jobInfo.education.current->next;
        v++;
    }

    if(jobInfo.education.current != nullptr) {
        temp = jobInfo.education.current;
        temp1 = jobInfo.education.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Сферы деятельности: " << endl;

    v = 0;
    jobInfo.fieldOfActivity.current = jobInfo.fieldOfActivity.head;
    while (v != 10) {
        jobInfo.fieldOfActivity.current = jobInfo.fieldOfActivity.current->next;
        v++;
    }

    if(jobInfo.fieldOfActivity.current != nullptr) {
        temp = jobInfo.fieldOfActivity.current;
        temp1 = jobInfo.fieldOfActivity.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Номера телефонов: " << endl;

    v = 0;
    jobInfo.phoneNumber.current = jobInfo.phoneNumber.head;
    while (v != 10) {
        jobInfo.phoneNumber.current = jobInfo.phoneNumber.current->next;
        v++;
    }

    if(jobInfo.phoneNumber.current != nullptr) {
        temp = jobInfo.phoneNumber.current;
        temp1 = jobInfo.phoneNumber.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Должности: " << endl;

    v = 0;
    jobInfo.position.current = jobInfo.position.head;
    while (v != 10) {
        jobInfo.position.current = jobInfo.position.current->next;
        v++;
    }

    if(jobInfo.position.current != nullptr) {
        temp = jobInfo.position.current;
        temp1 = jobInfo.position.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Оклады: " << endl;

    v = 0;
    jobInfo.salary.current = jobInfo.salary.head;
    while (v != 10) {
        jobInfo.salary.current = jobInfo.salary.current->next;
        v++;
    }

    if(jobInfo.salary.current != nullptr) {
        temp = jobInfo.salary.current;
        temp1 = jobInfo.salary.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Графики работы: " << endl;

    v = 0;
    jobInfo.schedule.current = jobInfo.schedule.head;
    while (v != 4) {
        jobInfo.schedule.current = jobInfo.schedule.current->next;
        v++;
    }

    if(jobInfo.schedule.current != nullptr) {
        temp = jobInfo.schedule.current;
        temp1 = jobInfo.schedule.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Названия: " << endl;

    v = 0;
    jobInfo.title.current = jobInfo.title.head;
    while (v != 10) {
        jobInfo.title.current = jobInfo.title.current->next;
        v++;
    }

    if(jobInfo.title.current != nullptr) {
        temp = jobInfo.title.current;
        temp1 = jobInfo.title.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Опыт работы: " << endl;

    v = 0;
    jobInfo.workExperience.current = jobInfo.workExperience.head;
    while (v != 5) {
        jobInfo.workExperience.current = jobInfo.workExperience.current->next;
        v++;
    }

    if(jobInfo.workExperience.current != nullptr) {
        temp = jobInfo.workExperience.current;
        temp1 = jobInfo.workExperience.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Фамилии: " << endl;

    v = 0;
    jobInfo.surname.current = jobInfo.surname.head;
    while (v != 10) {
        jobInfo.surname.current = jobInfo.surname.current->next;
        v++;
    }

    if(jobInfo.surname.current != nullptr) {
        temp = jobInfo.surname.current;
        temp1 = jobInfo.surname.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Имена: " << endl;

    v = 0;
    jobInfo.name.current = jobInfo.name.head;
    while (v != 10) {
        jobInfo.name.current = jobInfo.name.current->next;
        v++;
    }

    if(jobInfo.name.current != nullptr) {
        temp = jobInfo.name.current;
        temp1 = jobInfo.name.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Отчества: " << endl;

    v = 0;
    jobInfo.patronymic.current = jobInfo.patronymic.head;
    while (v != 10) {
        jobInfo.patronymic.current = jobInfo.patronymic.current->next;
        v++;
    }

    if(jobInfo.patronymic.current != nullptr) {
        temp = jobInfo.patronymic.current;
        temp1 = jobInfo.patronymic.current->line;
        while (temp != nullptr) {
            for (int i = 0; temp1->block->symbols[i] != temp1->block->marker; i++) {
                protocolFile << temp1->block->symbols[i];
                if (i == 4) {
                    temp1 = temp1->next;
                    i = -1;
                }
            }
            protocolFile << endl;
            temp = temp->next;
            if (temp != nullptr)
                temp1 = temp->line;
        }
    } else {
        protocolFile << "Не было добавлено новых данных" << endl;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << endl;

    int m = 1;
    protocolFile << "Неудовлетворенные вакансии: " << endl;
    vacancy.current = vacancy.head;
    while (vacancy.current != nullptr) {
        vacancy.printVacancy(m, protocolFile);
        protocolFile << endl;
        m++;
        vacancy.current = vacancy.current->next;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Добавленые работодатели: " << endl;
    m = 0;
    employer.current = employer.head;
    while (m != 10) {
        employer.current = employer.current->next;
        m++;
    }
    m++;
    while (employer.current != nullptr) {
        employer.printEmployer(m, protocolFile);
        protocolFile << endl;
        m++;
        employer.current = employer.current->next;
    }
    protocolFile << endl;
    protocolFile << endl;
    protocolFile << "Добавленые соискатели: " << endl;
    m = 0;
    jobSeeker.current = jobSeeker.head;
    while (m != 10) {
        jobSeeker.current = jobSeeker.current->next;
        m++;
    }
    m++;
    while (jobSeeker.current != nullptr) {
        jobSeeker.printJobSeeker(m, protocolFile);
        protocolFile << endl;
        m++;
        jobSeeker.current = jobSeeker.current->next;
    }
    protocolFile << endl;
    protocolFile << endl;
}