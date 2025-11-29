#include "people/Employee.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Employee_ValidConstruction) {
    Employee e("Dr. Smith", "EMP123", "Curator", 45, 'M');
    CHECK_EQUAL("Dr. Smith", e.name());
    CHECK_EQUAL("EMP123", e.employeeId());
    CHECK_EQUAL("Curator", e.position());
}

TEST(Employee_EmptyEmployeeId_Throws) {
    CHECK_THROW(
        Employee("Name", "", "Position", 30, 'F'),
        InvalidEmployeeIdException
    );
}