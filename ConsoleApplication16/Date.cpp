#include "Date.h"

#include "Date.h"

Date::Date()
{
    reset_to_defaults();
}

Date::Date(
    const std::size_t year,
    const std::size_t month,
    const std::size_t day)
{
    m_year = year;
    m_month = month;
    m_day = day;
    m_format = DEFAULT_FORMAT;
    m_delimiter = DEFAULT_DELIMITER;

    if (!is_valid_date())
    {
        reset_to_defaults();
    }
}

Date::Date(
    const std::size_t year,
    const std::size_t month,
    const std::size_t day,
    const std::string format)
{
    m_year = year;
    m_month = month;
    m_day = day;
    m_format = format;
    m_delimiter = DEFAULT_DELIMITER;

    if (!is_valid_date())
    {
        reset_to_defaults();
    }
}

Date::Date(
    const std::size_t year,
    const std::size_t month,
    const std::size_t day,
    const std::string format,
    const std::string delimiter)
{
    m_year = year;
    m_month = month;
    m_day = day;
    m_format = format;
    m_delimiter = delimiter;

    if (!is_valid_date())
    {
        reset_to_defaults();
    }
}

void Date::increase()
{
    if (is_last_day_of_the_year())
    {
        ++m_year;
        m_month = 1;
        m_day = 1;
    }
    else if (is_last_day_of_the_month())
    {
        ++m_month;
        m_day = 1;
    }
    else
    {
        ++m_day;
    }
}

void Date::reset_to_defaults()
{
    m_year = DEFAULT_YEAR;
    m_month = DEFAULT_MONTH;
    m_day = DEFAULT_DAY;
    m_format = DEFAULT_FORMAT;
    m_delimiter = DEFAULT_DELIMITER;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    if (d.m_format == "ddmmyyyy")
    {
        os << d.m_day << d.m_delimiter << d.m_month << d.m_delimiter << d.m_year;
    }
    else if (d.m_format == "mmddyyyy")
    {
        os << d.m_month << d.m_delimiter << d.m_day << d.m_delimiter << d.m_year;
    }
    else if (d.m_format == "yyyyddmm")
    {
        os << d.m_year << d.m_delimiter << d.m_day << d.m_delimiter << d.m_month;
    }
    else
    {
        os << d.m_year << d.m_delimiter << d.m_month << d.m_delimiter << d.m_day;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Date& d)
{
    is >> d.m_year >> d.m_month >> d.m_day;
    if (!d.is_valid_date())
    {
        d.reset_to_defaults();
    }
    return is;
}

bool Date::is_leap_year() const
{
    return ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0);
}

bool Date::is_february() const
{
    return m_month == FEB;
}

bool Date::is_28day_february() const
{
    return m_month == FEB && !is_leap_year();
}

bool Date::is_29day_february() const
{
    return m_month == FEB && is_leap_year();
}

bool Date::is_30day_month() const
{
    return m_month == APR || m_month == JUN || m_month == SEP || m_month == NOV;
}

bool Date::is_31day_month() const
{
    return !is_february() && !is_30day_month();
}

bool Date::is_valid_date() const
{
    bool result = true;

    if (m_day > 31)
    {
        result = false;
    }

    if (m_month > 12)
    {
        result = false;
    }

    if (is_28day_february() && m_day > 28)
    {
        result = false;
    }

    if (is_29day_february() && m_day > 29)
    {
        result = false;
    }

    if (is_30day_month() && m_day > 30)
    {
        result = false;
    }

    return result;
}

bool Date::is_last_day_of_the_year() const
{
    return m_month == DEC && m_day == 31;
}

bool Date::is_last_day_of_the_month() const
{
    bool result = true;

    if (
        (is_28day_february() && m_day != 28) ||
        (is_29day_february() && m_day != 29) ||
        (is_30day_month() && m_day != 30) ||
        (is_31day_month() && m_day != 31)
        )
    {
        result = false;
    }

    return result;
}