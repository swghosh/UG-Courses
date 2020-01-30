% Animals = [elephant, fox, deer, dog, cat, rishab].

f(X, Y) :- Y is (X + 3) * 2.

list_sum([], 0).
list_sum([Ele|Tail], Sum) :- list_sum(Tail, Prevsum), Sum is Prevsum + Ele.

list_length([], 0).
list_length([X|Y], Length) :- list_length(Y, L), Length is L + 1. 
