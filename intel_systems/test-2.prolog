zip([X|Xs], [Y|Ys], [Z|Zs], [X,Y,Z|Ws]) :- zip(Xs,Ys,Zs,Ws).
zip([], [Y|Ys], [Z|Zs], [Y,Z|Ws]) :- zip([],Ys,Zs,Ws).
zip([X|Xs], [], [Z|Zs], [X,Z|Ws]) :- zip(Xs,[],Zs,Ws).
zip([X|Xs], [Y|Ys], [], [X,Y|Ws]) :- zip(Xs,Ys,[],Ws).
zip([], [], [Z|Zs], [Z|Ws]) :- zip([],[],Zs,Ws).
zip([], [Y|Ys], [], [Y|Ws]) :- zip([],Ys,[],Ws).
zip([X|Xs], [], [], [X|Ws]) :- zip(Xs,[],[],Ws).
zip([], [], [], []).

stairs([X], [X]).
stairs([X|Xs], [X|[Rs]]) :-
    stairs(Xs, Rs).

rev([], A, A).
rev([X|Xs], As, Rs) :-
    is_list(X),
    norev(X, A),
    rev(Xs, [A|As], Rs).
rev([X|Xs], As, Rs) :-
    rev(Xs, [X|As], Rs).

norev([], []).
norev([X|Xs], [A|Rs]) :-
    is_list(X),
    rev(X, [], A),
    norev(Xs, Rs).
norev([X|Xs], [X|Rs]) :-
    norev(Xs, Rs).

pillow([], [], _).
pillow([X|Xs], [[X]|Rs], 1) :-
    pillow(Xs, Rs, 0).
pillow([X|Xs], [X|Rs], 0) :-
    pillow(Xs, Rs, 1).

remove([X|Xs], [A|Rs]) :-
    is_list(X),
    remove(X, A),
    remove(Xs, Rs).
remove([X|Xs], [X|Rs]) :-
    X mod 2 =:= 1,
    remove(Xs, Rs).
remove([X|Xs], Rs) :-
    X mod 2 =\= 1,
    remove(Xs, Rs).
remove([], []).

remove_el([X|Xs], E, [A|Rs]) :-
    is_list(X),
    remove_el(X, E, A),
    remove_el(Xs, E, Rs).
remove_el([X|Xs], E, [X|Rs]) :-
    X =\= E,
    remove_el(Xs, E, Rs).
remove_el([E|Xs], E, Rs) :-
    remove_el(Xs, E, Rs).
remove_el([], _, []).
