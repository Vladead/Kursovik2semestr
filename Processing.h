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

void
addFirstInfo(Vacancy &vacancy, Employer &employer, JobSeeker &jobSeeker, JobInfo &jobInfo, std::fstream &protocolFile);

void jobSeekerMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Vacancy &vacancy, Vacancy &listOfSatisfiedVacancy);

void findRequiredVacancy(NodeJobSeeker *currentJobSeeker, Vacancy &vacancy, Vacancy &listOfSatisfiedVacancy);

void employerMode(JobInfo &jobInfo, Employer &employer, JobSeeker &jobSeeker, Vacancy &vacancy,
                  Vacancy &listOfSatisfiedVacancy);

void findRequiredJobSeeker(NodeVacancy *currentVacancy, JobSeeker &jobSeeker, Vacancy &listOfSatisfiedVacancy);

void addingMode(JobInfo &jobInfo, JobSeeker &jobSeeker, Employer &employer, Vacancy &vacancy);

void satisfiedVacancyMode(Vacancy &satisfiedVacancy);

void add(JobInfo &jobInfo, JobSeeker &jobSeeker, std::fstream &inputFile);

void add(JobInfo &jobInfo, Employer &employer, std::fstream &inputFile);

void add(JobInfo &jobInfo, Vacancy &vacancy, std::fstream &inputFile);

List1 *returnPointToRequiredInfo(Form &inJobInfo, int nodeNumber);

int findNumberOfNecessaryNode(Form &inJobInfo, const char *tempLine, int sizeOfTemp);

bool wordIsInList(Form &inJobInfo, const char *tempLine, int sizeOfTemp);

void getInfoFromFile(Form &form, std::fstream &inputFile);

void inputOneLine(Form &form, int symbolsCount, int blocksCount, const char *transitLine);

int lineCount(std::fstream &inputFile);

int countBlocksInLine(int symbolsCount);

int countSymbols(std::fstream &inputFile);

bool checkFile(std::fstream &inputFile);

void printForm(Form &form, std::fstream &outputFile);

void deleteList(Form &form);


#endif //KURSOVIK_PROCESSING_H
