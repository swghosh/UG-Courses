% (C) https://www.cpp.edu/~jrfisher/www/prolog_tutorial/2_15.html

% edge(Start, End, Cost): The edge connecting Start to End has a Cost
edge(node1, node2, 10).
edge(node1, node4, 35).
edge(node1, node3, 25).
edge(node2, node3, 10).
edge(node2, node5, 25).
edge(node3, node4, 10).
edge(node3, node5, 20).
edge(node4, node5, 10).

% connected(Start, End, Cost): The edge from Start to End
% or from End to Start has same Cost
connected(Start, End, Cost) :- 
    edge(Start, End, Cost); 
    edge(End, Start, Cost).

% path(Start, End, Path, Cost): The Path from Start
% to End and has a Cost of travel
path(Start, End, Path, Cost) :-
    travel(Start, End, [Start], Res, Cost), 
    reverse(Res, Path).

% base case for use with path
travel(From, To, Visited, [To | Visited], Cost) :- 
    connected(From, To, Cost).
% recursive case for use with path
travel(From, To, Visited, Path, Cost) :-
    connected(From, Inter, InitCost1),    

    not(Inter == To),
    not(member(Inter, Visited)),

    travel(Inter, To, [Inter|Visited], Path, InitCost2),
    Cost is InitCost1 + InitCost2.