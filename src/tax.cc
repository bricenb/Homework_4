/* Copyright 2020 Bricen Bennett CSCE240 */
#include "inc/tax.h"
using std::istream;
using std::ostream;
using std::string;

Tax::Tax(const string& code, double percent) : code_(code), percent_(percent) {
  if (percent_ < 0) {
    percent_ *= -1;
  }
}

const string& Tax::code() const {
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

ostream& Tax::Extract(ostream* out) const {
  *out << code_ << ':' << percent_;
  return *out;
}

istream& Tax::Insert(istream* in) {
  char white_space;
  *in >> code_ >> white_space >> percent_;
  return *in;
}
