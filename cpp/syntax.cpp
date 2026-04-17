
// this is a .cpp file, which is just a file for C++ source code

// header: functions, classes, and objects included from either from connected
// programs, or declared in a separate file for convenience
#include <stdio.h>          // this is needed for output to terminal ("printf")
#include "syntax.h"

// this is a syntactical program for C++, which should stand as a standalone
// cheatsheet for programming in C++ for experienced programmers
int main() {

  // prints output to screen
  printf("Hello, world!\n\n");

  // FUNDAMENTAL VARIABLE TYPES

  bool boolean= false;              // this type will store true or false values

  char character_letter= 'a';       // this type will store either a "character"
  char character_number= 48;        // or an integer of most efficient size
  unsigned char character_unsigned= 21;     // it can be either signed
  signed char character_signed= -21;        // or unsigned

  int integer= 2;                   // this type will store a 2+ byte integer
  // this can also have both signed and unsigned variants
  short int integer_short= 1000;    // short is guaranteed to have 2 bytes
  long int integer_long= 100000;    // long is guaranteed to have 4 bytes
  // long long also possible for 64 bit integers!

  float floatingpoint_single= 0.5;  // this type is a single-precision "decimal"
  double floatingpoint_double= 0.25;// this type is a double-precision "decimal"
  // long double is also possible!

  // there is also a "void type", which is a type with an empty set of values.
  // it is an "incomplete type" and cannot be completed- so void objects are not
  // allowed. no void arrays, no void references. pointers to void and functions
  // that return void are allowed, and quite useful!

  // ARRAYS

  // an array is an object that consists of N contiguously allocated objects of
  // a given type T. below, we take T to be double, but double could easily be
  // replaced below with any of the fundamental variables types (excl. void),
  // pointers, pointers to memebers, classes, enumerations, etc.
  int N= 5;

  double array[N];

  double array_onconstruction[N]= {1.0, 0.5, 0.25, 0.125, 0.0625};

  // CONTROL STATEMENTS

  // if statement
  bool should_do= true;
  bool otherwise_todo= true;
  if (!should_do) {
    printf("I should not have done this.\n\n");
  } else if(otherwise_todo) {
    printf("If I should do this thing only if I didn't do the "
        "first and you also told me to do this one as well.\n\n");
  }
  else {
    printf("I only do this if I didn't do any of the other things.\n\n");
  }

  // for statement does something:
  //    for(some variable, initialized; while some condition holds;
  //    changing some variable at the end of each iteration)
  for (int k= 0; k < N; k++) {
    printf("%f\t", array_onconstruction[k]);
  }
  printf("\n\n");

  // while statement does something while a statement is true
  int counter= 2;
  while (counter < 1000) {
    counter= counter*counter;
    printf("%d, ", counter);
  }
  printf("\n\n");

  // switch/case statements take some condition
  int switch_variable= 2;
  switch (switch_variable) {
    case 1:     // jumps here if switch_variable == 1 and continues til break
      printf("ah yes. ");
      break;    // leaves switch/case statment
    case 2:     // jumps here if switch_variable == 2 and continues
      printf("oh, no! ");
    case 3:     // jumps here if switch_variable == 3 and continues
      printf("nope. nope. nope. ");
    default:    // runs if it gets here
      printf("this is very bad indeed.\n\n");
  }
  // note that, in the absence of break statements, switch/case will continue to
  // run through all of the options

  // CLASSES

  // we can declare a class here, which is defined in the header file
  aClass cls= aClass();
  // you can interact with the public members of a class, but not private ones
  int x_cls= 4;
  double c_cls= 5.2;

  cls.setX(x_cls);
  cls.zEqualsProduct(c_cls);
  printf("z= %f.\n", cls.getZ());

  // each instance of a class has a separate set of variables so we can
  // instantiate a second and see a completely secondary result!
  aClass cls2= aClass();
  int x_cls2= 8;
  double c_cls2= 1.703333;
  cls2.setX(x_cls2);
  cls2.zEqualsProduct(c_cls2);
  printf("z= %f.\tz2= %f!\n\n", cls.getZ(), cls2.getZ());

  // the next thing you can do is derive classes. we have in the header file a
  // sample class that holds two values and can perform an operation on them.
  // class derivation allows us to use the same "base class"

  operation op= operation();
  summer smr= summer();
  multiplier mlt= multiplier();

  printf("summer gives: %f\nmultiplier gives: %f\n\n",
      smr.getSum(), mlt.getProd());

  // typedefs are aliases that can be used anywhere in place of type names,
  // which can frequently get annoyingly complex; they're also useful when the
  // type of something is passed as an input enum, for example. we create a
  // typedef for an unsigned int here:
  typedef unsigned int unsgn;

  // now we can create an unsigned int this way:
  unsgn xTD= 5;

  printf("%d\n\n", xTD);

  // function pointers are particularly useful too.
  // let's make a function in the header file

  // we create a typedef for integer-returning function pointers with
  // one parameter of type character with:
  typedef int (* funcptr)(double);

  // now we create a function pointer!!!
  funcptr fpt= function;      // note that CPP compilers will implicitly convert
                              // function names to function pointers!

  // now call function via the pointer!
  double pi= 3.1415926535;
  printf("%f is approximated by %d.\n\n", pi, (*fpt)(pi));

  // last but not least, we can use class templates to build generic classes. in
  // the header file, we make a template to find y= m*x + b, regardless of the
  // type that is used for x, y, m, and b.
  line<double> pointslopedouble= line<double>(2*pi, 1.0);
  line<int> pointslopeinteger= line<int>(2*pi, 1.0);

  printf("(x, y)= (%f, %f)\n", 1.0, pointslopedouble.compute(1.0));
  printf("(x, y)= (%d, %d)\n", 1, pointslopeinteger.compute(1.0));

  // every function has to return something unless it is a void function
  // this function returns an integer and standard practice for a main is to
  // return zero if everything went to plan
  return 0;

}
