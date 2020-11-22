//
// Created by maus on 22.11.20.
//

#include "student.h"
#include<any>

using nlohmann::json;

auto get_name(const json& j) -> std::string {
    return j.get<std::string>();
}

auto get_debt(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else
        return j.get<std::vector<std::string> >();
}

auto get_avg(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else if (j.is_number_float())
        return j.get<double>();
    else
        return j.get<std::size_t>();
}

auto get_group(const json& j) -> std::any {
    if (j.is_string())
        return j.get<std::string>();
    else
    return j.get<std::size_t>();
}

void from_json(const json& j, Student& s) {

    s.name = get_name(j.at("name"));
    s.group = get_group(j.at("group"));
    s.avg = get_avg(j.at("avg"));
    s.debt = get_group(j.at("debt"));
}

