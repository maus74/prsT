// Copyright 2020 Your Name <your_email>

#include <header.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include<string>
#include <fstream>
#include <any>
#include "student.h"

json j2 = {
        {"", 3.141},
        {"happy", true},
        {"avg", "4.25"},
        {"nothing", nullptr},
        {"answer", {
                     {"everything", 42}
             }},
        {"list", {1, 0, 2}},
        {"object", {
                     {"currency", "USD"},
                     {"value", 42.99}
             }}
};


void print(const Student& student, std::ostream& os) {
    //...
    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type() == typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
                << std::any_cast<std::vector<std::string> >(student.debt).size()
                << " items";
    }
}


void print(const std::vector<Student>& students, std::ostream& os) {

    //...
    for (auto const& student : students) {
        print(student, os);
    }
}


int main() {
    //...
    std::string jsonPath = "/home/maus/iu10/new_labs/lab-01-parser/data_json/students.json";
    std::ifstream file(jsonPath);
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    std::vector<Student> students;
    for (auto const& item : data.at("items")) {
        //auto student = item.get<Student>();
        Student student_data;
        from_json(item, student_data);
        students.push_back(student_data);
    }
    //...
    print(students, std::cout);
}

