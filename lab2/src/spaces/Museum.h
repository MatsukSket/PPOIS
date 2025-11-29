#pragma once

#include <vector>
#include <string>
#include <memory>
#include "../people/Employee.h"
#include "../people/Visitor.h"
#include "../exhibits/Exhibit.h"
#include "Room.h"

class Museum {
public:
    explicit Museum(std::string name);

    const std::string& name() const noexcept { return name_; }

    void hireEmployee(Employee&& emp);
    size_t getStaffCount() const noexcept { return staff_.size(); }
    std::vector<std::string> listStaff() const; 

    void admitVisitor(Visitor&& visitor);
    void admitVisitorToExhibit(Visitor&& visitor, const std::string& exhibitName);
    size_t getVisitorCount() const noexcept { return visitors_.size(); }
    std::vector<std::string> listVisitors() const; 
    
    void addExhibit(Exhibit&& exhibit);
    const Exhibit* findExhibit(const std::string& name) const;
    size_t getExhibitCount() const noexcept { return exhibits_.size(); }

    void addRoom(std::unique_ptr<Room> room);

private:
    std::string name_;
    std::vector<Employee> staff_;
    std::vector<Visitor> visitors_;
    std::vector<Exhibit> exhibits_;
    std::vector<std::unique_ptr<Room>> rooms_;
    std::string foundingYear_;
};