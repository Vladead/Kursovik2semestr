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

using namespace std;

void JobSeekerMode(const JobInfo &jobInfo) {

}

void EmployerMode(const JobInfo &jobInfo) {

}

void VacancyMode(const JobInfo &jobInfo) {

}

void SatisfiedVacancyMode() {

}

bool CompareLine(Form &InJobInfo, const char *temp_line, int symbols_count_of_temp) {
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
                    k = -1; // Из за инкрементирования вначале каждоой итерации
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
            if(InJobInfo.current == nullptr)
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
