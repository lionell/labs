% [[x z x o x]
%  [o o o o x]
%  [x x x o x]
%  [o o x o x]
%  [o o o o x]]

%% move([u,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y], 108, [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y]).
%% move([z,o,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y], 114, [o,z,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y]).
%% move([z,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y], 117, [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y]).
%% move([z,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y], 100, [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y]).

%% lrud
%% move([A,B,C,D], 108, [A,B,C,D]).
%% move([A,B,C,D], 114, [A,B,C,D]).
%% move([A,B,C,D], 117, [A,B,C,D]).
%% move([A,B,C,D], 100, [A,B,C,D]).

%% move([z,B,C,D], 108, [A,B,C,D]).
move([z,o,C,D], 114, [o,z,C,D]).
%% move([z,B,C,D], 117, [A,B,C,D]).
move([z,B,o,D], 100, [o,B,z,D]).

move([o,z,C,D], 108, [z,o,C,D]).
%% move([A,z,C,D], 114, [A,z,C,D]).
%% move([A,B,C,D], 117, [A,B,C,D]).
move([A,z,C,o], 100, [A,o,C,z]).

%% move([A,B,z,D], 108, [A,B,C,D]).
move([A,B,z,o], 114, [A,B,o,z]).
move([o,B,z,D], 117, [z,B,o,D]).
%% move([A,z,C,o], 100, [A,o,C,z]).

move([A,B,o,z], 108, [A,B,z,o]).
%% move([A,B,z,o], 114, [A,B,o,z]).
move([A,o,z,D], 117, [A,z,o,D]).
%% move([A,z,C,o], 100, [A,o,C,z]).
move(Board, _, Board) :-
    write("Illegal move!"), nl.

win([q,z,C,D], 108, [z,o,C,D]).
win([A,B,q,z], 108, [A,B,z,o]).
win([z,q,C,D], 114, [o,z,C,D]).
win([A,B,z,q], 108, [A,B,o,z]).
win([q,B,z,D], 117, [z,B,o,D]).
win([A,q,C,z], 117, [A,z,C,o]).
win([z,B,q,D], 100, [o,B,z,D]).
win([A,z,C,q], 117, [A,o,C,z]).

disp([A,B,C,D]) :-
    write([A,B]), nl,
    write([C,D]), nl,
    nl.

moves(Board, [], Board).
moves(Board, [M], Result) :-
    win(Board, M, Result),
    write("You win!"), nl.
moves(Board, [H|T], Result) :-
    move(Board, H, NewBoard),
    moves(NewBoard, T, Result).

playFrom(Board) :-
    read(Input),
    string_to_list(Input, Moves),
    moves(Board, Moves, NewBoard),
    disp(NewBoard),
    playFrom(NewBoard).

start(Board) :-
    disp(Board),
    playFrom(Board).

play :- start([q,x,o,z]).
