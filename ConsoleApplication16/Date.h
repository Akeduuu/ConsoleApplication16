#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstddef>
#include <string>

class Date
{
public:
	Date(
		const std::size_t,
		const std::size_t month,
		const std::size_t day);
	Date(
		const std::size_t year,
		const std::size_t month,
		const std::size_t day,
		const std::string format);
	Date(
		const std::size_t year,
		const std::size_t month,
		const std::size_t day,
		const std::string format,
	    const std::string delimiter);
	void set_year(const std::size_t year) { m_year = year; }
	void set_month(const std::size_t month) { m_month = month; }
	void set_day(const std::size_t day) { m_day = day; }
	void set_format(const std::string format) { m_format = format; }
	void set_delimiter(char delimiter) { m_delimiter = delimiter; }

	std::size_t get_year() const { return m_year; }
	std::size_t get_month() const { return m_month; }
	std::size_t get_day() const { return m_day; }
	std::string get_format() const { return m_format; }
	std::string get_delimiter() const { return m_delimiter; }

	void increase();
	void reset_to_defaults();
	bool is_leap_year() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& d);
	friend std::istream& operator>>(std::istream& is, Date& d);
private:
	std::size_t m_year;
	std::size_t m_montg;
	std::size_t m_day;
	std::string m_format;
	std::string m_delimiter;
	
	const std::size_t DEFAULT_YEAD = 1930;
	const std::size_t DEFAULT_MONTH = 1;
	const std::size_t DEFAULT_FORMAT = "WASD";
	const std::size_t DEFAULT_DELIMITER=".";
	enum { JAN = 1; FEB, MAR, APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };
	bool is_february() const;
	bool is_28day_february() const;
	bool is_29day_february() const;
	bool is_30day_month() const;
	bool is_31day_month() const;
	bool is_valid_date() const;

	bool is_last_day_of_the_year() const;
	bool is_last_day_of_the_month() const;



};