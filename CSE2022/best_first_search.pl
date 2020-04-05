% path(Start, End, Cost): Cost of reaching node End from node Start.
path(node1, node2, 20).
path(node1, node3, 30).
path(node2, node4, 100).
path(node3, node5, 120).
path(node4, node6, 20).
path(node4, node7, 10).
path(node5, node8, 60).

path_exists(Start, End) :-
    path(Start, End, _).

paths(Start, States) :-
    bagof(End, path_exists(Start, End), States); 
    States = [].

costs(Start, Costs) :-
    paths(Start, States),
    empty_heap(EmptyHeap),
    costs_recurse(Start, States, EmptyHeap, Costs).

costs_recurse(Start, [], InitHeap, FinalHeap) :-
    FinalHeap = InitHeap.

costs_recurse(Start, [State | RemainingStates], InitHeap, FinalHeap) :-
    path(Start, State, Cost),
    add_to_heap(InitHeap, Cost, State, ResHeap),
    costs_recurse(Start, RemainingStates, ResHeap, FinalHeap).

increase_heap(Heap, Cost, IncreasedHeap) :-
    (
        empty_heap(Heap), IncreasedHeap = Heap
    );
    (
        get_from_heap(Heap, Pri, Key, Heap1),
        Total is Cost + Pri,
        increase_heap(Heap1, Cost, Heap2),
        add_to_heap(Heap2, Total, Key, IncreasedHeap)
    ).

bfs(Start, Goal) :-
    write(Start), write('-->'),
    costs(Start, Costs),
    bfs_recurse(Goal, Costs).
    
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
            (   
                Start == Goal, 
                write(Start), write(', Total Cost:'), write(Cost)
            );
            (
                write(Start), write('-->'), 
                costs(Start, Heap2),
                increase_heap(Heap2, Cost, Heap3),
                merge_heaps(Heap1, Heap3, ResHeap),
                bfs_recurse(Goal, ResHeap)
            )
        )
    ).

