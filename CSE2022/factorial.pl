% fact that says that the factorial of 0 is 1.
factorial(0, 1).

% factorial(N, Fact): Fact is the factorial of integer N.
factorial(N, Fact) :- 
    Lower is N - 1, 
    factorial(Lower, Lowfact), 
    Fact is Lowfact * N.
