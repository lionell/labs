del(_, [], []).

del(X, [X|T], Z) :-
    del(X, T, Z).

del(X, [H|T], [H|Z]) :-
    del(X, T, Z).

rev(L, R) :- rev_h(L, [], R).

rev_h([], A, A).

rev_h([H|T], A, R) :-
    is_list(H),
    rev_h(H, [], X),
    rev_h(T, [X|A], R).

rev_h([H|T], A, R) :-
    rev_h(T, [H|A], R).

fib(0) :- write('()').
fib(1) :- write('()').
fib(N) :-
    write('('),
    X is N - 1,
    fib(X),
    Y is N - 2,
    fib(Y),
    write(')').
