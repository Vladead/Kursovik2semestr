//
// Created by deadj on 15.05.2019.
//

#ifndef KURSOVIK_JOBINFO_H
#define KURSOVIK_JOBINFO_H

#include "Form.h"

class JobInfo {
public:
    Form address, education, field_of_activity, patronymic, phone_number, position, salary, schedule, surname, title,
            work_experience, name;

    JobInfo();

    ~JobInfo();

    void FillJobInfo();
};


#endif //KURSOVIK_JOBINFO_H
