% stack facts and rules
empty([]).
pop([Popper | Stack], Stack, Popper).
push(Stack, Pusher, [Pusher | Stack]).

do_something(Input, Output) :-
    write(Input),
    write(' '),
    Output is Input + 1.

loop_entry(Input):-
    Input < 10,
    do_something(Input, Output),
    loop_entry(Output).

run_loop :- 
    loop_entry(0).