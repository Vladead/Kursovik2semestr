//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_PROCESSING_H
#define KURSOVIK_PROCESSING_H


#include <fstream>

#include "Form.h"
#include "FormBlock.h"
#include "Vacancy.h"
#include "JobInfo.h"
#include "JobSeeker.h"
#include "Employer.h"

void JobSeekerMode(JobInfo &jobInfo, JobSeeker &jobSeeker);

void EmployerMode(JobInfo &jobInfo, Employer &employer);

void AddingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy);

void Add(JobInfo &jobInfo, JobSeeker &jobSeeker);

void Add(JobInfo &jobInfo, Employer &employer);

void Add(JobInfo &jobInfo, Vacancy &vacancy);

bool WordIsInList(Form &InJobInfo, const char *temp_line, int symbols_count_of_temp);

void CopyNodeFromList(Form &list_where_copy, Form &list_form_file);

void getting_info_from_file(Form &form, std::fstream &input_file);

void InputOneLine(Form &form, int symbols_count, int blocks_count, const char *transit_line);

int LineCount(std::fstream &input_file);

int BlocksInLine(int symbols_count);

int SymbolsCount(std::fstream &input_file, char temp);

bool CheckFile(std::fstream &input_file);

void PrintForm(Form &form1);

void DeleteList(Form &form);


#endif //KURSOVIK_PROCESSING_H
