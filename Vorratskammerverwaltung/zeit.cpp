#include <iostream>
#include <vector>
#include <ctime>

int main() {
  std::vector<std::tm> dates;
  int year, day, month;

  std::cout << "Enter a date (YYYY DD MM): ";
  std::cin >> year >> day >> month;

  std::tm date = {0};
  date.tm_year = year - 1900;  // tm_year is years since 1900
  date.tm_mon = month - 1;     // tm_mon is 0-based
  date.tm_mday = day;

  dates.push_back(date);

  std::cout << "The date is: " << std::asctime(&dates.back());

  return 0;
}