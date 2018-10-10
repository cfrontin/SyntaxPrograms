
// this declares a class
class aClass {
private:	// private members are only accessible by other members of this class
  int x;
  double z;
public:   // public members are globally accessible!
  void zEqualsProduct(double c) {
    z= c*x;
  }
  double getZ() {
    return z;
  }
  void setX(int xIn) {
    x= xIn;
  }
};

// this declares a base class
class operation {
private:		// private members can't be accessed by derived classes
	void print() {
		printf("this does an operation f(x, y), where f and x are doubles.\n\n");
	}
protected:	// protected members, are only accessible from other members of this
						// class OR by members of derived classes!
	double x;
	double y;
public:
	operation() {
		x= 0;
		y= 0;
	}
	operation(double xi, double yi) {
		x= xi;
		y= yi;
	}
};

// this declares a derived class
class summer : public operation {
public:
	// while we are here, we'll also go ahead and do a default constructor here.
	summer() {
		x= 1;
		y= 2;
	}
	double getSum() {
		return x*y;
	}
};

// we can derive a multiplication class from operation, like addition, such that
class multiplier : public operation {
public:
	multiplier() {
		x= 3;
		y= 4;
	}
	double getProd() {
		return x*y;
	}
};

// let's make a function that converts doubles to ints
int function(double x) {
	return (int) x;
};

// let's make a function that computes y= m*x + b where each of x, y, m, and b
// aren't of a defined type, but of a type to be later determined...
template <typename T>
class line {
private:
	T m;
	T b;
public:
	line() {
		m= 1;
		b= 1;
	}
	line(T mIn, T bIn) {
		m= mIn;
		b= bIn;
	}
	T compute(T x) {
		return m*x + b;
	}
};
