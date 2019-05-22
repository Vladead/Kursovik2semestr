//
// Created by deadj on 15.05.2019.
//
#include <fstream>
#include "JobInfo.h"
#include "Processing.h"

using namespace std;

JobInfo::JobInfo() = default;

JobInfo::~JobInfo() {
    deleteList(address);
    deleteList(education);
    deleteList(fieldOfActivity);
    deleteList(patronymic);
    deleteList(phoneNumber);
    deleteList(position);
    deleteList(salary);
    deleteList(schedule);
    deleteList(surname);
    deleteList(title);
    deleteList(workExperience);
    deleteList(name);
}

void JobInfo::fillJobInfo() {
    fstream input_file;
    input_file.open("../cmake-build-debug/Address.txt", ios::in);
    getInfoFromFile(address, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Education.txt", ios::in);
    getInfoFromFile(education, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Field_of_activity.txt", ios::in);
    getInfoFromFile(fieldOfActivity, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Patronymic.txt", ios::in);
    getInfoFromFile(patronymic, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Phone_number.txt", ios::in);
    getInfoFromFile(phoneNumber, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Position.txt", ios::in);
    getInfoFromFile(position, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Salary.txt", ios::in);
    getInfoFromFile(salary, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Schedule.txt", ios::in);
    getInfoFromFile(schedule, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Surname.txt", ios::in);
    getInfoFromFile(surname, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Title.txt", ios::in);
    getInfoFromFile(title, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Work_experience.txt", ios::in);
    getInfoFromFile(workExperience, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Name.txt", ios::in);
    getInfoFromFile(name, input_file);
    input_file.close();
}