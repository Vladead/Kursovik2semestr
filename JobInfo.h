//
// Created by deadj on 15.05.2019.
//

#ifndef KURSOVIK_JOBINFO_H
#define KURSOVIK_JOBINFO_H


#include "Form.h"

#pragma pack(push, 1)

class JobInfo {
public:
    Form address, education, fieldOfActivity, patronymic, phoneNumber, position, salary, schedule, surname, title,
            workExperience, name;

    JobInfo();

    ~JobInfo();

    void fillJobInfo();
};

#pragma pack(pop)


#endif //KURSOVIK_JOBINFO_H
