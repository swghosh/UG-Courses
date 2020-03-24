
% stack facts and rules
empty([]).
pop([Popper | Stack], Stack, Popper).
push(Stack, Pusher, [Pusher | Stack]).

% edge(FromVertex, ToVertex): edge exists FromVertex ToVertex in graph
edge(a, b).
edge(a, c).
edge(b, d).
edge(c, e).
edge(c, f).

% edges(StartVertex, AllVertices): AllVertices is the list of all 
% vertices that is connected to StartVertex by an existent edge
edges(StartVertex, AllVertices):-
    bagof(ToVertex, edge(StartVertex, ToVertex), AllVertices); 
    AllVertices = [].

traverse_loop(Vertices, Stack, NewStack) :- 
    not(empty(Vertices)),
    [Head | Tail] = Vertices,
    push(Stack, Head, StackAgain),
    traverse_loop(Tail, StackAgain, X),
    NewStack is X.

search_loop(Stack) :- 
    not(empty(Stack)),
    pop(Stack, NewStack, Vertex),
    edges(Vertex, Vertices),
    traverse_loop(Vertices),
    search_loop(StackAgain).

dfs(StartVertex, SetOfVertices) :-
    Stack = [], Visited = [],
    push(Stack, StartVertex, NewStack),
    append(Visited, StartVertex, VisitedAgain),
    search_loop(NewStack),
    SetOfVertices = [].
