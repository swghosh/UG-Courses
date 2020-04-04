% path(Start, End, Cost): Cost of reaching node End from node Start.
path(node1, node2, 30).
path(node1, node3, 20).
path(node2, node4, 100).
path(node4, node5, 150).

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

add(A,B,[A|B]).

bfs(Start, Goal) :-
    costs(Start, Costs),
    bfs_recurse(Goal, Costs).
    
bfs_recurse(Goal, Heap) :- 
    % verbose
    write('Priority Q: '),
    heap_to_list(Heap, HeapList),
    write(HeapList),
    write('\n'),

    list_to_heap(HeapList, Heap),
    not(empty_heap(Heap)),
    (
        get_from_heap(Heap, Cost, Start, Heap1),
        (
            Start == Goal;
            (
                costs(Start, Heap2),
                merge_heaps(Heap1, Heap2, ResultingHeap),
                bfs_recurse(Goal, ResultingHeap)
            )
        )
    ).
