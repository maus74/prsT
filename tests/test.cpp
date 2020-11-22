// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "../sources/student.h"

using json = nlohmann::json;

using json = nlohmann::json;
json j2 = {
        {"name", "Ivanov Petr"},
        {"group", "1"},
        {"avg", "Niels"},
        {"debt", "C++"}

};

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Test1, Test1_T_Test)
{
    auto item = j2;
    Student student_data;
    from_json(item, student_data);
    EXPECT_EQ(student_data.name, "Ivanov Petr");
    EXPECT_EQ(std::any_cast<std::string>(student_data.group), "1");
    EXPECT_EQ(std::any_cast<std::string>(student_data.avg), "Niels");
}
