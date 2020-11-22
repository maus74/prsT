//
// Created by maus on 22.11.20.
//

#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H
#include <nlohmann/json.hpp>
#include<any>
using nlohmann::json;

struct Student {
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

void from_json(const json& j, Student& s);

#endif //TEMPLATE_STUDENT_H
