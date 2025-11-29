#pragma once

#include <stdexcept>
#include <string>

class TicketExpiredException : public std::runtime_error {
public:
    TicketExpiredException() : std::runtime_error("Ticket has expired") {}
};

class ExhibitNotFoundException : public std::runtime_error {
public:
    explicit ExhibitNotFoundException(const std::string& name)
        : std::runtime_error("Exhibit not found: " + name) {}
};

class InvalidEmployeeIdException : public std::invalid_argument {
public:
    InvalidEmployeeIdException() : std::invalid_argument("Employee ID must not be empty") {}
};

class ItemNotFoundException : public std::runtime_error {
public:
    explicit ItemNotFoundException(const std::string& name)
        : std::runtime_error("Item not found: " + name) {}
};

class HallOvercrowdedException : public std::runtime_error {
public:
    HallOvercrowdedException() : std::runtime_error("Hall capacity exceeded") {}
};

class InvalidAgeException : public std::invalid_argument {
public:
    InvalidAgeException() : std::invalid_argument("Age must be non-negative") {}
};

class InvalidNameException : public std::invalid_argument {
public:
    InvalidNameException() : std::invalid_argument("Name must not be empty") {}
};

class InvalidHallCapacityException : public std::invalid_argument {
public:
    InvalidHallCapacityException() : std::invalid_argument("Hall capacity must be positive") {}
};

class HallIsDirtyException : public std::runtime_error {
public:
    HallIsDirtyException() : std::runtime_error("Hall is dirty") {}
};

class HallIsSmallException : public std::runtime_error {
public:
    HallIsSmallException() : std::runtime_error("Hall is too small") {}
};

class InvalidMembershipException : public std::invalid_argument {
public:
    InvalidMembershipException() : std::invalid_argument("Invalid membership level") {}
};

class EventHasNoLocationException : public std::runtime_error {
public:
    EventHasNoLocationException() : std::runtime_error("Event has no location") {}
};