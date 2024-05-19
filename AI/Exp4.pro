/* Define the graph with nodes and their neighbors */
connected(1, 7). connected(1, 8). connected(1, 3).
connected(7, 4). connected(7, 20). connected(7, 17).
connected(8, 6). 
connected(3, 9). connected(3, 12).
connected(4, 42). connected(20, 28).
connected(17, 10). connected(9, 19).
neighbors(Node, Neighbors) :-
    findall(Neighbor, connected(Node, Neighbor), Neighbors).

/* Breadth First Search Traversal */
bfs(Graph, Start, End) :-
    bfs(Graph, [Start], [Start], End).

bfs(_, _, VisitedNodes, End) :-
    last(VisitedNodes, LastNode),
    LastNode = End,
    write('End node reached: '), write(LastNode), nl.

bfs(Graph, [CurrentNode|Rest], VisitedNodes, End) :-
    neighbors(CurrentNode, Neighbors),
    subtract(Neighbors, VisitedNodes, NewNeighbors),
    append(Rest, NewNeighbors, Queue),
    append(VisitedNodes, NewNeighbors, NewVisited),
    bfs(Graph, Queue , NewVisited , End).
