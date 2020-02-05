% sum_list(): a fact that specifies that the sum of an empty list is 0
sum_list([], 0).

% sum_list(List, Sum): Sum is the sum of items in the List
sum_list([Ele | Tail], Sum) :- sum_list(Tail, Prevsum), Sum is Prevsum + Ele.
