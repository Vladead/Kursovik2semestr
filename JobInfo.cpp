//
// Created by deadj on 15.05.2019.
//
#include <fstream>
#include "JobInfo.h"
#include "Processing.h"

using namespace std;

JobInfo::JobInfo() = default;

JobInfo::~JobInfo() {
    DeleteList(address);
    DeleteList(education);
    DeleteList(field_of_activity);
    DeleteList(patronymic);
    DeleteList(phone_number);
    DeleteList(position);
    DeleteList(salary);
    DeleteList(schedule);
    DeleteList(surname);
    DeleteList(title);
    DeleteList(work_experience);
    DeleteList(name);
}

void JobInfo::FillJobInfo() {
    fstream input_file;
    input_file.open("../cmake-build-debug/Address.txt", ios::in);
    getting_info_from_file(address, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Education.txt", ios::in);
    getting_info_from_file(education, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Field_of_activity.txt", ios::in);
    getting_info_from_file(field_of_activity, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Patronymic.txt", ios::in);
    getting_info_from_file(patronymic, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Phone_number.txt", ios::in);
    getting_info_from_file(phone_number, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Position.txt", ios::in);
    getting_info_from_file(position, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Salary.txt", ios::in);
    getting_info_from_file(salary, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Schedule.txt", ios::in);
    getting_info_from_file(schedule, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Surname.txt", ios::in);
    getting_info_from_file(surname, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Title.txt", ios::in);
    getting_info_from_file(title, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Work_experience.txt", ios::in);
    getting_info_from_file(work_experience, input_file);
    input_file.close();

    input_file.open("../cmake-build-debug/Name.txt", ios::in);
    getting_info_from_file(name, input_file);
    input_file.close();
}