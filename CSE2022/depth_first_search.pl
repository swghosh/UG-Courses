% valid states are as follows:
% 1. one 
% 2. two
% 3. three
% 4. four
% 5. five
% 6. six
% 7. seven

path(one, two).
path(one, three).

path(two, four).
path(two, five).
path(three, six).
path(three, seven).

path(four, eight).
path(four, nine).
path(five, ten).
path(five, eleven).
path(six, twelve).
path(six, thirteen).
path(seven, fourteen).
path(seven, fifteen).

% all possible paths from a given state
paths(FromState, States) :-
    bagof(ToState, path(FromState, ToState), States);
    States = [].

% stack
empty([]).
pop([Popper | Stack], Stack, Popper).
push(Stack, Pusher, Result) :-
    append(Pusher, Stack, Result).

% depth first search of state space
dfs(Goal, Stack) :-
    % verbose
    write('Stack: '),
    write(Stack),
    write('\n'),

    not(empty(Stack)),
    (
        pop(Stack, NewStack, Start),
        (
            Start == Goal;
            (
                paths(Start, States),
                push(NewStack, States, ResultingStack),
                dfs(Goal, ResultingStack)
            )
        )
    ).
    