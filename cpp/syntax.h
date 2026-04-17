#ifndef SYNTAX_PROGRAM_CPP_SYNTAX_H_
#define SYNTAX_PROGRAM_CPP_SYNTAX_H_

#include <string>

// This class demonstrates private data with public setter/getter methods.
class AClass {
 private:
  int x_;
  double z_;

 public:
  AClass() : x_(0), z_(0.0) {}
  void SetX(int x_in) { x_ = x_in; }
  void SetZAsProduct(double c) { z_ = c * x_; }
  double GetZ() const { return z_; }
};

// This base class demonstrates constructors and protected members.
class Operation {
 protected:
  double x_;
  double y_;

 public:
  Operation() : x_(0.0), y_(0.0) {}
  Operation(double x_in, double y_in) : x_(x_in), y_(y_in) {}
  virtual ~Operation() = default;
};

// This derived class demonstrates inheritance and overriding behavior.
class Summer : public Operation {
 public:
  Summer() : Operation(1.0, 2.0) {}
  double GetSum() const { return x_ + y_; }
};

// This derived class demonstrates another implementation over same base.
class Multiplier : public Operation {
 public:
  Multiplier() : Operation(3.0, 4.0) {}
  double GetProduct() const { return x_ * y_; }
};

// This function is used to demonstrate function pointers.
int TruncateDouble(double x);

// This template demonstrates generic programming over many types.
template <typename T>
class Line {
 private:
  T m_;
  T b_;

 public:
  Line() : m_(1), b_(1) {}
  Line(T m_in, T b_in) : m_(m_in), b_(b_in) {}
  T Compute(T x) const { return m_ * x + b_; }
};

#endif  // SYNTAX_PROGRAM_CPP_SYNTAX_H_
