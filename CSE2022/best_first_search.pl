% path(Start, End, Cost): Cost of reaching 
% node End from node Start
path(node1, node2, 20).
path(node1, node3, 30).
path(node2, node4, 100).
path(node3, node5, 120).
path(node4, node6, 20).
path(node4, node7, 10).
path(node5, node8, 60).


% path_exists(Start, End): Whether there exists a path 
% between node Start and End
path_exists(Start, End) :-
    path(Start, End, _).

% paths(Start, States): States is the is list of all 
% nodes reachable from node Start
paths(Start, States) :-
    bagof(End, path_exists(Start, End), States); 
    States = [].


% costs(Start, Costs): Costs is a min-heap (priority Q) of 
% respective costs to each possible node from Start
costs(Start, Costs) :-
    paths(Start, States),
    empty_heap(EmptyHeap),
    costs_recurse(Start, States, EmptyHeap, Costs).
% rule helps costs(Start, Costs) to be used recursively
costs_recurse(Start, [State | RemainingStates], InitHeap, FinalHeap) :-
    path(Start, State, Cost),
    add_to_heap(InitHeap, Cost, State, ResHeap),
    costs_recurse(Start, RemainingStates, ResHeap, FinalHeap).
% base case for recursion
costs_recurse(Start, [], InitHeap, FinalHeap) :-
    FinalHeap = InitHeap.

% increase_heap(Heap, Cost, IncreasedHeap): IncreasedHeap is a heap 
% containing all elements in Heap such that each element is 
% increased by Cost
increase_heap(Heap, Cost, IncreasedHeap) :-
    % base case
    (
        empty_heap(Heap), IncreasedHeap = Heap
    );
    % recursive case
    (
        get_from_heap(Heap, InitCost, Node, Heap1),
        TotalCost is Cost + InitCost,
        increase_heap(Heap1, Cost, Heap2),
        add_to_heap(Heap2, TotalCost, Node, IncreasedHeap)
    ).


% bfs(Start, Goal): Best First Search based on heuristic
% for reaching node Goal from node Start
bfs(Start, Goal) :-
    % verbose
    write(Start), write('-->'),

    costs(Start, Costs),
    bfs_recurse(Goal, Costs).
% rule helps bfs(Start, Goal) to be used recursively
bfs_recurse(Goal, Heap) :- 
    % verbose
    write('Priority Q: '),
    heap_to_list(Heap, HeapList),
    write(HeapList),
    write('\n'),

    not(empty_heap(Heap)),
    (
        get_from_heap(Heap, Cost, Start, Heap1),
        (
            % base case
            (   
                Start == Goal, 

                % verbose
                write(Start), 
                write(', Total Cost:'), write(Cost)
            );
            % recursive case
            (
                % verbose
                write(Start), write('-->'), 

                costs(Start, Heap2),
                increase_heap(Heap2, Cost, Heap3),
                merge_heaps(Heap1, Heap3, ResHeap),
                bfs_recurse(Goal, ResHeap)
            )
        )
    ).
