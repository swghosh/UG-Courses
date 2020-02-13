display_even :- write('Your list is EVEN!').
display_odd :- write('Your list is ODD!').

% is_even(Remainder): when Remainder is 0, it states that as even
is_even(0).

% even_length(List): predicate to check if list has even number of elements or not
even_length(List) :- 
    length(List, Len),
    Remainder is mod(Len, 2),
    is_even(Remainder).

odd_length(List) :- 
    not(even_length(List)).

check_odd_even_length(List) :-
    even_length(List) ->
        display_even;
    display_odd.
