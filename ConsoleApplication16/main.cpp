#include "Date.h"

int main()
{
    Date defaultDate;
    std::cout << defaultDate << "\n";

    const std::size_t FIVE_WEEKS = 35;

    for (std::size_t i = 0; i < FIVE_WEEKS; ++i)
    {
        defaultDate.increase();
        std::cout << defaultDate << "\n";
    }

    Date today(2017, 8, 27);
    std::cout << "\n\n" << today << "\n";

    for (std::size_t i = 0; i < FIVE_WEEKS; ++i)
    {
        today.increase();
        std::cout << today << "\n";
    }

    Date leapYearDate(2020, 11, 23, "ddmmyyyy", "-");
    std::cout
        << "\nTest for is_leap_year() function."
        << "\n2020 year is leap year (true or false?): "
        << std::boolalpha << leapYearDate.is_leap_year()
        << "\n";

    Date notLeapYearDate;
    for (std::size_t year = 1700; year <= 1900; year += 100)
    {
        notLeapYearDate.set_year(year);
        std::cout
            << year
            << " is leap year (true or false?): "
            << std::boolalpha << notLeapYearDate.is_leap_year()
            << "\n";
    }

    std::cout
        << "\nEnter your birthday date (use yyyymmdd format)."
        << "\nPress <Enter> key after each token of date."
        << "\nFor example: 1980<Enter>12<Enter>24<Enter>):\n";
    Date yourBirthdayDate;
    std::cin >> yourBirthdayDate;
    std::cout << "You was born in " << yourBirthdayDate << "\n\n";
}