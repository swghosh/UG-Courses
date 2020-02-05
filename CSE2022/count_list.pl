% count_list(): a fact that specifies that the count of an empty list is 0
count_list([], 0).

% count_list(List, Count): Count is the count of items in the List
count_list([Ele | Tail], Count) :- count_list(Tail, Prevcount), Count is Prevcount + 1.
