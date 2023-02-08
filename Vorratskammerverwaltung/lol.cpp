#include <iostream>
#include <ctime>

int main() {
  std::time_t t1 = std::time(nullptr);
  std::time_t t2 = t1 + 60 * 60 * 24 * 8;  // 60 seconds later

  std::tm *time1 = std::localtime(&t1);
  std::tm *time2 = std::localtime(&t2);

  std::cout << "Time 1: " << std::asctime(time1);
  std::cout << "Time 2: " << std::asctime(time2);

  std::cout << "Difference in seconds: " << difftime(t2, t1) << '\n';

  double diff = std::difftime(t2, t1);
  if (diff < 60 * 60 * 24 * 7) {
    std::cout << "The difference is less than 7 days." << std::endl;
  } else {
    std::cout << "The difference is greater than or equal to 7 days." << std::endl;
  }
  return 0;
}