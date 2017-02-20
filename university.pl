/*A student achieves a grade in a course.*/
grade(student, course).

/*Departments to be offered: Computer Science, Math, and Physics.*/
department(cs).
department(math).
department(physics).

/*Courses offered in CS: CS111, CS211, CS311, CS315, CS421, CS436.*/
course(cs, cs111).
course(cs, cs211).
course(cs, cs311).
course(cs, cs315).
course(cs, cs421).
course(cs, cs436).

/*Courses offered in Math: MATH270, MATH242, MATH372, MATH480.*/
course(math, math270).
course(math, math242).
course(math, math372).
course(math, math480).

/*Courses offered in Physics: PHYS201, PHYS301.*/
course(physics, physics201).
course(physics, physics301).

/*Students in the university: Newton, Galileo, Lovelace, Turing.*/
student(newton).
student(galileo).
student(lovelace).
student(turing).

/*Newton is enrolled in CS311, CS421, and MATH372.*/
enroll(newton, cs311).
enroll(newton, cs421).
enroll(newton, math372).

/*Turing is enrolled in MATH480, CS421, and PHYS301.*/
enroll(turing, math480).
enroll(turing, cs421).
enroll(turing, physics301).

/*Galileo is enrolled in CS436, and CS421.*/
enroll(galileo, cs436).
enroll(galileo, cs421).

/*Lovelace is enrolled in PHYS301, and MATH372.*/
enroll(lovelace, physics301).
enroll(lovelace, math372).

/*Galileo has taken CS111, CS211, CS311, MATH270, PHYS201, MATH242, CS436 and passed all the courses.*/
taken(galileo, cs111).
taken(galileo, cs211).
taken(galileo, cs311).
taken(galileo, math270).
taken(galileo, physics201).
taken(galileo, math242).
taken(galileo, cs436).

/*Turing has taken CS111, CS211, CS311, MATH270, PHYS201, PHYS301, MATH372, and passed all the courses.*/
taken(turing, cs111).
taken(turing, cs211).
taken(turing, cs311).
taken(turing, math270).
taken(turing, physics201).
taken(turing, physics301).
taken(turing, math372).

/*For the rest of the students assume that they have taken CS111 and CS211.*/
taken(newton, cs111).
taken(newton, cs211).

taken(lovelace, cs111).
taken(lovelace, cs211).

/*A student satisfies the degree requirements if the student has: 
- completed the core courses of the department
- fulfilled the electives requirement.*/
degree(X) :-
complete(X, core),
fulfilled(X, elective).

/*Completed core courses is true if the student passed each of the core courses in the department with the minimum passing grade of C.*/
complete(X, core) :-
pass(X, cs111),
pass(X, cs211),
pass(X, cs311),
pass(X, math270),
pass(X, physics201).

pass(X, Y) :-
taken(X, Y).

pass(X, Y) :-
enroll(X, Y).

/*Fulfilled electives requirement is true if the student has passed three different courses, each course in a different department in the College of Science*/
fulfilled(X, elective) :-
finish(X, cs_electives),
finish(X, math_electives),
finish(X, physics_electives).

finish(X, cs_electives) :-
pass(X, cs111).

finish(X, cs_electives) :-
pass(X, cs211).

finish(X, cs_electives) :-
pass(X, cs311).

finish(X, cs_electives) :-
pass(X, cs315).

finish(X, cs_electives) :-
pass(X, cs421).

finish(X, cs_electives) :-
pass(X, cs436).

finish(X, math_electives) :-
pass(X, math270).

finish(X, math_electives) :-
pass(X, math242).

finish(X, math_electives) :-
pass(X, math372).

finish(X, math_electives) :-
pass(X, math480).

finish(X, physics_electives) :-
pass(X, physics201).

finish(X, physics_electives) :-
pass(X, physics301).
