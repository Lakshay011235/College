% Win conditions
win(Board, Player) :- rowwin(Board, Player).
win(Board, Player) :- colwin(Board, Player).
win(Board, Player) :- diagwin(Board, Player).

rowwin([Player,Player,Player,_,_,_,_,_,_], Player).
rowwin([_,_,_,Player,Player,Player,_,_,_], Player).
rowwin([_,_,_,_,_,_,Player,Player,Player], Player).

colwin([Player,_,_,Player,_,_,Player,_,_], Player).
colwin([_,Player,_,_,Player,_,_,Player,_], Player).
colwin([_,_,Player,_,_,Player,_,_,Player], Player).

diagwin([Player,_,_,_,Player,_,_,_,Player], Player).
diagwin([_,_,Player,_,Player,_,Player,_,_], Player).

% Helping predicate for alternating play in a "self" game:
other(x,o).
other(o,x).

game(Board, Player) :- 
    win(Board, Player), 
    !, 
    write([player, Player, wins]).
game(Board, Player) :- 
    other(Player,Otherplayer), 
    move(Board,Player,Newboard),
    !,
    displayer(Newboard),
    game(Newboard,Otherplayer).

move([-,B,C,D,E,F,G,H,I], Player, [Player,B,C,D,E,F,G,H,I]).
move([A,-,C,D,E,F,G,H,I], Player, [A,Player,C,D,E,F,G,H,I]).
move([A,B,-,D,E,F,G,H,I], Player, [A,B,Player,D,E,F,G,H,I]).
move([A,B,C,-,E,F,G,H,I], Player, [A,B,C,Player,E,F,G,H,I]).
move([A,B,C,D,-,F,G,H,I], Player, [A,B,C,D,Player,F,G,H,I]).
move([A,B,C,D,E,-,G,H,I], Player, [A,B,C,D,E,Player,G,H,I]).
move([A,B,C,D,E,F,-,H,I], Player, [A,B,C,D,E,F,Player,H,I]).
move([A,B,C,D,E,F,G,-,I], Player, [A,B,C,D,E,F,G,Player,I]).
move([A,B,C,D,E,F,G,H,-], Player, [A,B,C,D,E,F,G,H,Player]).

displayer([A,B,C,D,E,F,G,H,I]) :- 
    write([A,B,C]),nl,
    write([D,E,F]),nl,
    write([G,H,I]),nl,nl.

% Predicates to support playing a game with the user:
x_can_win_in_one(Board) :- move(Board, x, Newboard), win(Newboard, x).

 
% The predicate orespond generates the computer's (playing o) response
% from the current Board.
orespond(Board,Newboard) :- 
    move(Board, o, Newboard),
    win(Newboard, o),
    !.
orespond(Board,Newboard) :-
    move(Board, o, Newboard), 
    \+ x_can_win_in_one(Newboard).
orespond(Board,Newboard) :-
    move(Board, o, Newboard).
orespond(Board,Newboard) :-
    \+ member(b,Board),
    !, 
    write('Cats game!'), nl,
    Newboard = Board.

% The following translates from an integer description
% of x's move to a board transformation.
xmove([-,B,C,D,E,F,G,H,I], 1, [x,B,C,D,E,F,G,H,I]).
xmove([A,-,C,D,E,F,G,H,I], 2, [A,x,C,D,E,F,G,H,I]).
xmove([A,B,-,D,E,F,G,H,I], 3, [A,B,x,D,E,F,G,H,I]).
xmove([A,B,C,-,E,F,G,H,I], 4, [A,B,C,x,E,F,G,H,I]).
xmove([A,B,C,D,-,F,G,H,I], 5, [A,B,C,D,x,F,G,H,I]).
xmove([A,B,C,D,E,-,G,H,I], 6, [A,B,C,D,E,x,G,H,I]).
xmove([A,B,C,D,E,F,-,H,I], 7, [A,B,C,D,E,F,x,H,I]).
xmove([A,B,C,D,E,F,G,-,I], 8, [A,B,C,D,E,F,G,x,I]).
xmove([A,B,C,D,E,F,G,H,-], 9, [A,B,C,D,E,F,G,H,x]).
xmove(Board, _, Board) :- write('Illegal move.'), nl.

% The 0-place predicate playo starts a game with the user.
playo :- explain, playfrom([-,-,-,-,-,-,-,-,-]).

explain :-
    write('You play X by entering integer positions followed by a period.'),
    nl,
    displayer([1,2,3,4,5,6,7,8,9]).

playfrom(Board) :- 
    win(Board, x), 
    write('You win!').
playfrom(Board) :- 
    win(Board, o), 
    write('I win!').
playfrom(Board) :- 
    read(N),
    xmove(Board, N, Newboard), 
    displayer(Newboard),
    orespond(Newboard, Newnewboard), 
    displayer(Newnewboard),
    playfrom(Newnewboard).
