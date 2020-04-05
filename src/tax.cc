/* Copyright 2020 Bricen Bennett CSCE240 */
#include "inc/tax.h"
using std::istream;
using std::ostream;
using std::string;

Tax::Tax(const std::string& code, double percent) : code_(code),
         percent_(percent) {
  if (percent_ < 0) {
    percent_ *= -1;
  }
}

const std::string& Tax::code() const {
  return code_;
}

double Tax::percent() const {
  return percent_;
}

void Tax::percent(double new_percent) {
  if (new_percent < 0)
    new_percent *= -1;
  percent_ = new_percent;
}

double Tax::Calculate(double amount) const {
  if (amount < 0)
    amount *= -1;
  return (percent_ / 100) * amount;
}

std::ostream& Tax::Extract(std::ostream* out) const {
  *out << code_ << ':' << percent_;
  return *out;
}

std::istream& Tax::Insert(std::istream* in) {
  *in >> code_ >> percent_;
  return *in;
}
