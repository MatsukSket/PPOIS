#pragma once

#include <vector>
#include <string>
#include "Employee.h"
#include "../events/Workshop.h"
#include "../people/Visitor.h"
#include "../exhibits/Exhibit.h"

class Guide : public Employee {
public:
    explicit Guide(std::string name,
                   std::string employeeId,
                   short age = 0,
                   char gender = 'U');

    std::string conductTour(const std::vector<Visitor*>& visitors, const Exhibit& exhibit) const;
};