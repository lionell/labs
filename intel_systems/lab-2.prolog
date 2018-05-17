% ----------------------------------------------------------------------------------------------------------------------
% This section contains some customizable predicates
% ----------------------------------------------------------------------------------------------------------------------

% Number of possible consecutive moves to check for making decision about next move.
% Be careful with this value since increasing it will significantly slow down the game.
look_ahead_on(4).

% Initial positions for all figures.
% You can change these two lists to start game from some specific combination.
initial_board(board(Black, White)) :-
    White = [fig(man, 0, 0), fig(man, 0, 2), fig(man, 1, 1), fig(man, 2, 0), fig(man, 2, 2), fig(man, 3, 1),
             fig(man, 4, 0), fig(man, 4, 2), fig(man, 5, 1), fig(man, 6, 0), fig(man, 6, 2), fig(man, 7, 1)],
    Black = [fig(man, 0, 6), fig(man, 1, 7), fig(man, 1, 5), fig(man, 2, 6), fig(man, 3, 7), fig(man, 3, 5),
             fig(man, 4, 6), fig(man, 5, 7), fig(man, 5, 5), fig(man, 6, 6), fig(man, 7, 7), fig(man, 7, 5)].

% This predicate is used to evaluate board state, i.e. how good is current combination for white.
% For now it's very simple, but you can tweak it as you want.
% Also negating Score will make computer to play "Anti-checkers" or giveaway checkers.
evaluate_board(board(Black, White), Score) :-
    list_count(Black, fig(man, _, _), BlackMans),
    list_count(Black, fig(king, _, _), BlackKings),
    list_count(White, fig(man, _, _), WhiteMans),
    list_count(White, fig(king, _, _), WhiteKings),
    Score is (WhiteMans + 2 * WhiteKings - BlackMans - 2 * BlackKings).


% ----------------------------------------------------------------------------------------------------------------------
% Some predicates working with lists (mainly aliases for built-in predicates). Just for convenience.
% ----------------------------------------------------------------------------------------------------------------------

list_member(List, Member)               :- member(Member, List).
list_append(List1, List2, Result)       :- append(List1, List2, Result).
list_delete_one(List, Element, NewList) :- select(Element, List, NewList).
list_length(List, Length)               :- length(List, Length).
list_absent(List, Element)              :- \+ (member(Element, List)).
list_subtract(List1, List2, Result)     :- subtract(List1, List2, Result).
list_last_element(List, Element)        :- last(List, Element).

% Count number of elements in a list which are unifiable with provided element.
list_count([], _, 0).
list_count([FirstElement | Tail], Element, Occurrences) :-
    unifiable(FirstElement, Element, _),
    list_count(Tail, Element, Tmp),
    Occurrences is (Tmp + 1), !.
list_count([_ | Tail], Element, Occurrences) :- list_count(Tail, Element, Occurrences).


% ----------------------------------------------------------------------------------------------------------------------
% Generic definitions
% ----------------------------------------------------------------------------------------------------------------------

% There are two sides: Black and White.
side(white).
side(black).
other_side(black, white).
other_side(white, black).

% Board is 8x8 cells (64 cells totally). Cells are numbered from 0 to 7. So valid coordinate is in range [0-7].
coordinate(X) :- list_member([0, 1, 2, 3, 4, 5, 6, 7], X).

% Any valid cell on the board.
cell(X, Y) :- coordinate(Y), coordinate(X).

% Any valid positions for man or king (man or king can stay only on black cell).
pos(X, Y) :-
    cell(X, Y),
    Z is ((X + Y) mod 2),
    Z = 0.

% There are two kinds of figures: man and king.
fig(man, X, Y)  :- pos(X, Y).
fig(king, X, Y) :- pos(X, Y).

% Helper predicate to check if diagonal is free from position (X1,Y1)(but not inclusive) to position (X2,Y2) inclusive.
% List1 and List2 are list with black and white figures (no matter which one is black and white).
% If start and destination is the same cell - it's degenerated case, will make it always true.
diagonal_is_free(_, _, X, Y, X, Y) :- !.

diagonal_is_free(List1, List2, X1, Y1, X2, Y2) :-
    % Make sure that the next cell is free
    Dx is sign(X2 - X1), Dy is sign(Y2 - Y1),
    NextX is (X1 + Dx), NextY is (Y1 + Dy),
    list_absent(List1, fig(_, NextX, NextY)),
    list_absent(List2, fig(_, NextX, NextY)),
    % And check the rest cells
    diagonal_is_free(List1, List2, NextX, NextY, X2, Y2).


% ----------------------------------------------------------------------------------------------------------------------
% Set of predicates used to print board with ASCII symbols
% ----------------------------------------------------------------------------------------------------------------------

% Print any symbol inside cell. Also prints separator and vertical cells numbering.
print_cell_symbol(X, Y, Symbol) :- X  = 7, write(' | '), write(Symbol), write(' | '), write(Y),
                                   write('\n  ---------------------------------\n').
print_cell_symbol(X, _, Symbol) :- X \= 7, X \= 0, write(' | '), write(Symbol).
print_cell_symbol(X, Y, Symbol) :- X  = 0, write(Y), write(' | '), write(Symbol).

% Print empty cell (for black and white cells).
print_empty_cell(X, Y) :- Sum is (X + Y), Reminder is (Sum mod 2), Reminder  = 0,
                          print_cell_symbol(X, Y, '.'). % Black cell
print_empty_cell(X, Y) :- Sum is (X + Y), Reminder is (Sum mod 2), Reminder \= 0,
                          print_cell_symbol(X, Y, ' '). % White cell

% Generic predicates to print cell with appropriate symbol inside.
print_cell(board(Black, _), X, Y)       :- (list_member(Black, fig(man,  X, Y)), print_cell_symbol(X, Y, 'o')) ;
                                           (list_member(Black, fig(king, X, Y)), print_cell_symbol(X, Y, 'O')).
print_cell(board(_, White), X, Y)       :- (list_member(White, fig(man,  X, Y)), print_cell_symbol(X, Y, 'x')) ;
                                           (list_member(White, fig(king, X, Y)), print_cell_symbol(X, Y, 'X')).
print_cell(board(_, _), X, Y)           :- \+ (pos(X, Y)), print_empty_cell(X, Y).
print_cell(board(Black, White), X, Y)   :- list_absent(Black, fig(_, X, Y)), list_absent(White, fig(_, X, Y)),
                                           print_empty_cell(X, Y).

% Recursive predicate to print all cells.
print_board_internal(board(Black, White), 0) :- print_cell(board(Black, White), 7, 0).
print_board_internal(board(Black, White), N) :-
    N > 0,
    Y is (N div 8),
    X is (7 - (N mod 8)),
    print_cell(board(Black, White), X, Y),
    Next is (N - 1),
    print_board_internal(board(Black, White), Next).

% Print whole board (64 cells)
print_board(Board) :-
    write('    0   1   2   3   4   5   6   7  \n'),
    write('  ---------------------------------\n'),
    print_board_internal(Board, 63),
    write('    0   1   2   3   4   5   6   7  \n'), !.


% ----------------------------------------------------------------------------------------------------------------------
% Definition of moves
% ----------------------------------------------------------------------------------------------------------------------

% Possible moves for man. (X1, Y1) - starting position, (X2, Y2) - destination position.
possible_move(white, fig(man, X1, Y1), fig(Type, X2, Y2)) :-
    Y2 is (Y1 + 1), Y2 =< 7,
    (X2 is X1 + 1 ; X2 is X1 - 1), X2 >= 0, X2 =< 7,
    ( (Y2 = 7, Type = king) ; (Y2 < 7, Type = man) ).

possible_move(black, fig(man, X1, Y1), fig(Type, X2, Y2)) :-
    Y2 is (Y1 - 1), Y2 >= 0,
    (X2 is X1 + 1 ; X2 is X1 - 1), X2 =< 7, X2 >= 0,
    ( (Y2 = 0, Type = king) ; (Y2 > 0, Type = man) ).

% Possible moves for king.
possible_move(_, fig(king, X1, Y1), fig(king, X2, Y2)) :-
    fig(king, X2, Y2), X2 >= 0, X2 =< 7, Y2 >= 0, Y2 =< 7,  % New position should be correct (on black cell on board)
    X1 \= X2,  Y1 \= Y2,                                    % New position should differ from starting position
    % Can move diagonally (in any direction)
    DiagDiff1 is (X1 - Y1), DiagDiff2 is (X2 - Y2),
    DiagSum1 is (X1 + Y1), DiagSum2 is (X2 + Y2),
    (DiagDiff1 = DiagDiff2 ; DiagSum1 = DiagSum2).

% Predicate to check is the way is free for figure from its start position (X1,Y1) to its destination position (X2,Y2).
% For men only need to check that the destination cell is free.
way_is_free(ListWithMove, ListWithoutMove, fig(man, _, _), fig(_, X2, Y2)) :-
    list_absent(ListWithMove,    fig(_, X2, Y2)),
    list_absent(ListWithoutMove, fig(_, X2, Y2)).

% For king all cells on diagonal between (X1, Y1) and (X2, Y2) should be free.
way_is_free(ListWithMove, ListWithoutMove, fig(king, X1, Y1), fig(king, X2, Y2)) :-
    diagonal_is_free(ListWithMove, ListWithoutMove, X1, Y1, X2, Y2).

% Move figure of specified Side. ListWithMove - list containing figures of the side which is moving.
% ListWithoutMove - contains figures of the other side.
move_figure(Side, ListWithMove, ListWithoutMove, NewListWithMove) :-
    % Choose any figure (as starting position)
    list_delete_one(ListWithMove, StartingPosition, TmpListWithMove),
    % Make any possible move from this position
    possible_move(Side, StartingPosition, DestPosition),
    % Make sure the way to destination position is free
    way_is_free(ListWithMove, ListWithoutMove, StartingPosition, DestPosition),
    % Place figure to its new position
    list_append(TmpListWithMove, [DestPosition], NewListWithMove).

% Move figure of the specified 'Side' on board.
move_figure(black, board(Black, White), board(NewBlack, White)) :-
    move_figure(black, Black, White, NewBlack).

move_figure(white, board(Black, White), board(Black, NewWhite)) :-
    move_figure(white, White, Black, NewWhite).


% ------------------------------------------------------------------------------------------------------------------------
% Definition of captures
% ------------------------------------------------------------------------------------------------------------------------

% Helper predicate to get list of positions on diagonal, from starting position (X, Y) (inclusive) to the end of board.
% Diagonal direction is defined with (Dx, Dy) pair: (1, 1), (1, -1), (-1, -1), (-1, 1).
diagonal_positions(pos(X, Y), _, _, []) :- (X < 0 ; X > 7 ; Y < 0 ; Y > 7), !.
diagonal_positions(pos(X, Y), Dx, Dy, [pos(X, Y) | Tail]) :-
    NextX is (X + Dx), NextY is (Y + Dy),
    diagonal_positions(pos(NextX, NextY), Dx, Dy, Tail).

% Definition of allowable (single) capture for man.
% (X1, X2) - starting position, (X2, Y2) - cell with enemy figure, (X3, Y3) - destination position.
possible_capture(Side, fig(man, X1, Y1), fig(_, X2, Y2), fig(Type, X3, Y3)) :-
    Dx is (X2 - X1), Dy is (Y2 - Y1),
    AbsDx is abs(Dx), AbsDy is abs(Dy),
    AbsDx = 1, AbsDy = 1,
    X3 is (X2 + Dx), Y3 is (Y2 + Dy),
    X3 >= 0, X3 =< 7, Y3 >= 0, Y3 =< 7,
    % During capture man can become king:
    (
        ( Side = white, ((Y3 = 7, Type = king) ; (Y3 < 7, Type = man)) ) ;
        ( Side = black, ((Y3 = 0, Type = king) ; (Y3 > 0, Type = man)) )
    ).

% Defines allowable (single) capture for king.
possible_capture(_, fig(king, X1, Y1), fig(_, X2, Y2), fig(king, X3, Y3)) :-
    % King and enemy figure should be on the same diagonal
    Sum1 is (X1 + Y1), Sum2 is (X2 + Y2),
    Dif1 is (X1 - Y1), Dif2 is (X2 - Y2),
    (Sum1 = Sum2 ; Dif1 = Dif2),
    % Allowable position of king after capture: any position on the capture diagonal after enemy figure
    Dx is sign(X2 - X1), Dy is sign(Y2 - Y1),
    NextX is (X2 + Dx), NextY is (Y2 + Dy),
    diagonal_positions(pos(NextX, NextY), Dx, Dy, AllowableDestPositions),
    list_member(AllowableDestPositions, pos(X3, Y3)).

% Helper predicate to check if the way is free for the capture (no figures on the way).
% For capture using man we only need to check if the destination cell is free.
way_for_capture_is_free(CapturingList, CapturedList, fig(man, _, _), fig(_, _, _), fig(_, X3, Y3)) :-
    list_absent(CapturingList, fig(_, X3, Y3)),
    list_absent(CapturedList,  fig(_, X3, Y3)).

% For capture using king we need to check that there are no figures on diagonal from current king's position (X1, Y2)
% to the enemy figure position (X2, Y2), and from enemy figure position to the destination position (X3, Y3).
way_for_capture_is_free(CapturingList, CapturedList, fig(king, X1, Y1), fig(_, X2, Y2), fig(_, X3, Y3)) :-
    Dx is sign(X2 - X1), Dy is sign(Y2 - Y1),
    PrevX is (X2 - Dx), PrevY is (Y2 - Dy),
    % No figures between king and enemy figure
    diagonal_is_free(CapturingList, CapturedList, X1, Y1, PrevX, PrevY),
    % No figures between enemy figure and destination position
    diagonal_is_free(CapturingList, CapturedList, X2, Y2, X3, Y3).

% Helper predicate used to get position (X3, Y3) which king on cell (X1, Y1)
% can take after capturing enemy figure on cell (X2, Y2)
potential_intermediate_king_pos(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), pos(X3, Y3)) :-
    % There is should be an enemy figure on cell (X2, Y2)
    list_member(CapturedList, fig(_, X2, Y2)),
    % Possible capture for king
    possible_capture(Side, fig(king, X1, Y1), fig(_, X2, Y2), fig(king, X3, Y3)),
    way_for_capture_is_free(CapturingList, CapturedList, fig(king, X1, Y1), fig(_, X2, Y2), fig(king, X3, Y3)),
    % Such figure is not captured already
    list_absent(CapturedFiguresList, fig(_, X2, Y2)).

% Helper predicate, similar to potential_intermediate_king_pos, but with additional constraint:
% king should be able to capture another figure from position (X3, Y3) (i.e. continue capture)
potential_intermediate_king_pos_with_capture(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), pos(X3, Y3)) :-
    potential_intermediate_king_pos(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), pos(X3, Y3)),
    list_delete_one(CapturingList, fig(king, X1, Y1), TmpCapturingList),
    list_append(TmpCapturingList, [fig(king, X3, Y3)], NewCapturingList),
    list_append(CapturedFiguresList, [fig(man, X2, Y2)], NewCapturedFiguresList),
    potential_intermediate_king_pos(Side, NewCapturingList, CapturedList, NewCapturedFiguresList, pos(X3, Y3), _, _).

% Helper predicate which builds a list of positions, from which king (initially placed on cell (X1, Y1))
% can continue capture, after capturing figure on cell (X2, Y2)
potential_intermediate_king_pos_list(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), List) :-
    findall(Position, potential_intermediate_king_pos_with_capture(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), Position), List).

% Helper predicate used to check, if an intermediate capture position for king is allowable.
% The main rule here is that king should continue capture, if he can. I.e. after capturing enemy figure,
% king should take position from which it can continue capture (if there are any possibility to continue capture).

% No need to check this for man.
allowable_intermediate_capture_pos(_, _, _, _, fig(man, _, _), _, _) :- !.

allowable_intermediate_capture_pos(Side, CapturingList, CapturedList, CapturedFiguresList, fig(king, X1, Y1), fig(_, X2, Y2), fig(king, X3, Y3)) :-
    % Build list of cells from which king can continue capture
    potential_intermediate_king_pos_list(Side, CapturingList, CapturedList, CapturedFiguresList, pos(X1, Y1), pos(X2, Y2), IntermediatePositionsWithCapture),
    (
        % If this list is empty, king can take any cell
        (IntermediatePositionsWithCapture = [], true, !) ;
        % Otherwise, it should only take one of  cells from which it can continue capture
        (list_member(IntermediatePositionsWithCapture, pos(X3, Y3)), !)
    ).

% Predicate defining a capture of single figure. CapturingList - list containing figures of 'Side'.
% CapturedList contains list of figures of other side. CapturedFiguresList - list of already captured figures.
% CapturingFigure - figure from CapturingList which is making a capture.
capture_single_figure(Side, CapturingList, CapturedList, NewCapturingList, CapturedFiguresList, NewCapturedFiguresList, CapturingFigure, NewCapturingFigure) :-
    list_delete_one(CapturingList, CapturingFigure, TmpCapturingList),
    list_member(CapturedList, CapturedFigure),
    possible_capture(Side, CapturingFigure, CapturedFigure, NewCapturingFigure),
    way_for_capture_is_free(CapturingList, CapturedList, CapturingFigure, CapturedFigure, NewCapturingFigure),
    CapturedFigure = fig(_, X2, Y2),
    allowable_intermediate_capture_pos(Side, CapturingList, CapturedList, CapturedFiguresList, CapturingFigure, CapturedFigure, NewCapturingFigure),
    list_absent(CapturedFiguresList, fig(_, X2, Y2)),
    list_append(TmpCapturingList, [NewCapturingFigure], NewCapturingList),
    list_append(CapturedFiguresList, [CapturedFigure], NewCapturedFiguresList).

% Recursive predicates used to define a full capture (i.e. always continue capture, when it's possible)
capture_figures(Side, CapturingList, CapturedList, NewCapturingList, CapturedFiguresList, NewCapturedFiguresList, CapturingFigure, NewCapturingFigure) :-
    capture_single_figure(Side, CapturingList, CapturedList, TmpCapturingList, CapturedFiguresList, TmpCapturedFiguresList, CapturingFigure, TmpCapturingFigure),
    capture_multiple_figures(Side, TmpCapturingList, CapturedList, NewCapturingList, TmpCapturedFiguresList, NewCapturedFiguresList, TmpCapturingFigure, NewCapturingFigure).

capture_multiple_figures(Side, CapturingList, CapturedList, NewCapturingList, CapturedFiguresList, NewCapturedFiguresList, CapturingFigure, NewCapturingFigure) :-
    capture_single_figure(Side, CapturingList, CapturedList, _, CapturedFiguresList, _, CapturingFigure, _), !,
    capture_figures(Side, CapturingList, CapturedList, NewCapturingList, CapturedFiguresList, NewCapturedFiguresList, CapturingFigure, NewCapturingFigure).
capture_multiple_figures(_, CapturingList, _, CapturingList, CapturedList, CapturedList, CapturingFigure, CapturingFigure).

% Generic predicates defining any capture on the board
capture(black, board(Black, White), board(NewBlack, NewWhite)) :-
    capture_figures(black, Black, White, NewBlack, [], CapturedList, _, _),
    % Remove captured figures from the board
    list_subtract(White, CapturedList, NewWhite).

capture(white, board(Black, White), board(NewBlack, NewWhite)) :-
    capture_figures(white, White, Black, NewWhite, [], CapturedList, _, _),
    list_subtract(Black, CapturedList, NewBlack).


% ----------------------------------------------------------------------------------------------------------------------
% Common definition of move
% ----------------------------------------------------------------------------------------------------------------------

% Common definition of any possible move:
% If we can capture - then we have to capture (make any possible capture).
move_capture(Side, Board1, Board2) :- capture(Side, Board1, Board2).
move(Side, Board1, Board2) :- capture(Side, Board1, _), !, move_capture(Side, Board1, Board2).

% Otherwise we can make any allowable move.
move(Side, board(Black, White), board(NewBlack, NewWhite)) :-
    move_figure(Side, board(Black, White), board(NewBlack, NewWhite)).


% ----------------------------------------------------------------------------------------------------------------------
% Minimax algorithm for making 'smart' moves
% ----------------------------------------------------------------------------------------------------------------------

% There are two types of nodes in a decision tree: min and max. This predicate just swaps node type.
swap_node_type(min, max).
swap_node_type(max, min).

% Helper predicate to get board with best score. For max node 'best' is maximal score. For min node - minimal.
best_score_and_board(max, Board1, Score1, Board2, Score2, BestBoard, BestScore) :-
    (Score1 >= Score2, !, BestBoard = Board1, BestScore = Score1) ;
    (Score1  < Score2, BestBoard = Board2, BestScore = Score2).
best_score_and_board(min, Board1, Score1, Board2, Score2, BestBoard, BestScore) :-
    (Score1 =< Score2, !, BestBoard = Board1, BestScore = Score1) ;
    (Score1  > Score2, BestBoard = Board2, BestScore = Score2).

%% alpha_beta_prune(max, _, Beta, Value)  :- Value > Beta.
%% alpha_beta_prune(min, Alpha, _, Value) :- Value < Alpha.

%% update_alpha_beta(max, Alpha, Beta, Value, NewAlpha, Beta) :- (Value > Alpha, !, NewAlpha = Value) ; (NewAlpha = Alpha).
%% update_alpha_beta(min, Alpha, Beta, Value, Alpha, NewBeta) :- (Value < Beta,  !, NewBeta = Value) ; (NewBeta = Beta).

% Build list of all possible moves for the 'Side' on provided board.
possible_moves_list(Side, Board, List) :- findall(NewBoard, move(Side, Board, NewBoard), List).

% Get best move from the list of possible moves.
% If depth is zero (leaf node), choose board by the best score.
find_best_move(_, _, [BestBoard], BestBoard, BestScore, 0, _, _) :-
    evaluate_board(BestBoard, BestScore), !.

%% find_best_move(Side, NodeType, [Board1 | Tail], BestBoard, BestScore, 0, Alpha, Beta) :-
%%     evaluate_board(Board1, Score1),
%%     (
%%         (alpha_beta_prune(NodeType, Alpha, Beta, Score1), !, BestBoard = Board1, BestScore = Score1) ;
%%         (
%%             find_best_move(Side, NodeType, Tail, Board2, Score2, 0, Alpha, Beta),
%%             best_score_and_board(NodeType, Board1, Score1, Board2, Score2, BestBoard, BestScore)
%%         )
%%     ).

find_best_move(Side, NodeType, [Board1 | Tail], BestBoard, BestScore, 0, Alpha, Beta) :-
    evaluate_board(Board1, Score1),
    find_best_move(Side, NodeType, Tail, Board2, Score2, 0, Alpha, Beta),
    best_score_and_board(NodeType, Board1, Score1, Board2, Score2, BestBoard, BestScore).

% If depth is not zero - evaluate each node with minmax predicate, and chose the best.
find_best_move(Side, NodeType, [BestBoard], BestBoard, BestScore, Depth, Alpha, Beta) :-
    Depth > 0,
    NewDepth is (Depth - 1),
    swap_node_type(NodeType, NextNodeType),
    other_side(Side, OtherSide),
    minmax(OtherSide, NextNodeType, BestBoard, _, BestScore, NewDepth, Alpha, Beta), !.

%% find_best_move(Side, NodeType, [Board1 | Tail], BestBoard, BestScore, Depth, Alpha, Beta) :-
%%     Depth > 0,
%%     NewDepth is (Depth - 1),
%%     swap_node_type(NodeType, NextNodeType),
%%     other_side(Side, OtherSide),
%%     minmax(OtherSide, NextNodeType, Board1, _, Score1, NewDepth, Alpha, Beta),
%%     (
%%         (alpha_beta_prune(NodeType, Alpha, Beta, Score1), !, BestBoard = Board1, BestScore = Score1) ;
%%         (
%%             update_alpha_beta(NodeType, Alpha, Beta, Score1, NewAlpha, NewBeta),
%%             find_best_move(Side, NodeType, Tail, Board2, Score2, Depth, NewAlpha, NewBeta),
%%             best_score_and_board(NodeType, Board1, Score1, Board2, Score2, BestBoard, BestScore)
%%         )
%%     ).

find_best_move(Side, NodeType, [Board1 | Tail], BestBoard, BestScore, Depth, Alpha, Beta) :-
    Depth > 0,
    NewDepth is (Depth - 1),
    swap_node_type(NodeType, NextNodeType),
    other_side(Side, OtherSide),
    minmax(OtherSide, NextNodeType, Board1, _, Score1, NewDepth, Alpha, Beta),
    %% update_alpha_beta(NodeType, Alpha, Beta, Score1, NewAlpha, NewBeta),
    find_best_move(Side, NodeType, Tail, Board2, Score2, Depth, NewAlpha, NewBeta),
    best_score_and_board(NodeType, Board1, Score1, Board2, Score2, BestBoard, BestScore).

% If there are no more possible moves: this is a leaf node. Only need to evaluate it.
minmax(Side, _, Board, Board, Score, _, _, _) :-
    possible_moves_list(Side, Board, []),
    evaluate_board(Board, Score), !.

% Otherwise get list of all possible moves and choose the best.
minmax(Side, NodeType, Board, BestBoard, BestScore, Depth, Alpha, Beta) :-
    possible_moves_list(Side, Board, PossibleMoves),
    find_best_move(Side, NodeType, PossibleMoves, BestBoard, BestScore, Depth, Alpha, Beta).

% Predicate for 'smart move' for each side.
smart_move(white, Board, NewBoard) :-
    look_ahead_on(Depth), minmax(white, max, Board, NewBoard, _, Depth, -100000, 100000).
smart_move(black, Board, NewBoard) :-
    look_ahead_on(Depth), minmax(black, min, Board, NewBoard, _, Depth, -100000, 100000).


% ----------------------------------------------------------------------------------------------------------------------
% Interaction with player
% ----------------------------------------------------------------------------------------------------------------------

% Helper predicate to extract lists of figures from the board. Lists order depends on side.
board_lists(black, board(Black, White), Black, White).
board_lists(white, board(Black, White), White, Black).

% Helper predicate to get list intermediate positions on diagonal starting from (X1, Y1) (inclusive)
% to (X2, Y2) (not inclusive).
intermediate_diagonal_positions(pos(X, Y), pos(X, Y), []) :- !.
intermediate_diagonal_positions(pos(X1, Y1), pos(X2, Y2), [pos(X1, Y1) | Tail]) :-
    NextX is (X1 + sign(X2 - X1)), NextY is (Y1 + sign(Y2 - Y1)),
    pos(NextX, NextY),
    intermediate_diagonal_positions(pos(NextX, NextY), pos(X2, Y2), Tail).

% Helper predicate to get list of all intermediate positions for provided capture path.
intermediate_positions_from_path([], []) :- !.
intermediate_positions_from_path([pos(_, _)], []) :- !.
intermediate_positions_from_path([pos(X1, Y1), pos(X2, Y2) | T1], List) :-
    intermediate_diagonal_positions(pos(X1, Y1), pos(X2, Y2), [_ | Positions]),
    list_append(Positions, Rest, List),
    intermediate_positions_from_path([pos(X2, Y2) | T1], Rest).

% Helper predicate to remove figures on specified positions.
subtract_figures_list(FiguresList, [], FiguresList) :- !.
subtract_figures_list(FiguresList, [pos(X, Y) | Tail], NewFiguresList) :-
    list_subtract(FiguresList, [fig(_, X, Y)], TmpFiguresList),
    subtract_figures_list(TmpFiguresList, Tail, NewFiguresList).

% Same as subtract_figures_list but for board.
subtract_figures(board(Black, White), board(NewBlack, NewWhite), PositionsList) :-
    subtract_figures_list(Black, PositionsList, NewBlack),
    subtract_figures_list(White, PositionsList, NewWhite).

% Helper predicate to deduce final type of figure by its path. I.e. if man became king while traveling this path.
deduce_final_figure_type(_, Type, Type, []) :- !.
deduce_final_figure_type(_, king, king, _) :- !.
deduce_final_figure_type(white, man, king, [pos(_, 7) | _]) :- !.
deduce_final_figure_type(black, man, king, [pos(_, 0) | _]) :- !.
deduce_final_figure_type(Side, man, Type, [_ | Tail]) :-
    deduce_final_figure_type(Side, man, Type, Tail).

% Check is specified side can move. If it can't - it is considered as the end of the game.
can_move(Side, Board) :- move(Side, Board, _), !.
can_move(Side, _) :- other_side(Side, OtherSide), write('\n'), write(OtherSide), write(' wins!\n'), !, fail.

% Select side for human (black or white).
player_select_side(Side) :-
    write('Select your side (black/white): '), nl,
    read(UserSide),
    (
        (side(UserSide), Side = UserSide, !);
        (write('Invalid side, please type \'black.\' or \'white.\'\n'), player_select_side(Side))
    ).

% Input any position as 'X-Y'.
player_input_position(pos(X, Y)) :-
    read(A-B),
    (
        (pos(A, B), X = A, Y = B, !);
        (write('Invalid position. Retry: '), player_input_position(pos(X, Y)))
    ).

% Input list of positions, until user input something that is not a position (by convenience - 'end.').
player_input_pos_list(pos(X, Y), [pos(X, Y) | Tail]) :- player_input_pos_list(Tail).
player_input_pos_list(L) :-
    (read(A-B), pos(A, B), !, player_input_pos_list(pos(A, B), L));
    (L = []).

% Let human make move.
player_input_move(Side, board(Black, White), NewBoard) :-
    write('Your move: '),
    player_input_position(pos(X1, Y1)), player_input_position(pos(X2, Y2)),
    board_lists(Side, board(Black, White), ListWithMove, ListWithoutMove),
    (
        (
            list_delete_one(ListWithMove, fig(Type, X1, Y1), TmpListWithMove),
            deduce_final_figure_type(Side, Type, NewType, [pos(X1, Y1), pos(X2, Y2)]),
            list_append(TmpListWithMove, [fig(NewType, X2, Y2)], NewListWithMove),
            board_lists(Side, NewBoard, NewListWithMove, ListWithoutMove),
            move(Side, board(Black, White), NewBoard)
        );
        (write('Invalid move. Retry: '), player_input_move(Side, board(Black, White), NewBoard))
    ), !.

% Let human make capture.
player_input_capture(Side, B1, B2) :-
    write('Please input your capture path (type \'end.\' to finish): '),
    (
        (
            player_input_pos_list(CapturePath), CapturePath = [pos(X1, Y1) | _], % Read capture path
            list_last_element(CapturePath, pos(X2, Y2)),
            intermediate_positions_from_path(CapturePath, IntermediatePositionsList),
            subtract_figures(B1, BoardWithCapturedFigures, IntermediatePositionsList),
            board_lists(Side, BoardWithCapturedFigures, CapturingList, CapturedList),
            list_delete_one(CapturingList, fig(Type, X1, Y1), TmpCapturingList),
            deduce_final_figure_type(Side, Type, NewType, CapturePath),
            list_append(TmpCapturingList, [fig(NewType, X2, Y2)], NewCapturingList),
            board_lists(Side, B2, NewCapturingList, CapturedList),
            capture(Side, B1, B2)

        );
        (write('Invalid capture. Retry:\n'), player_input_capture(Side, B1, B2))
    ).

% Generic predicate to let human make it move (move or capture).
play_input_move_common(Side, B1, B2) :- capture(Side, B1, _), player_input_capture(Side, B1, B2), !.
play_input_move_common(Side, B1, B2) :- can_move(Side, B1), player_input_move(Side, B1, B2).

% Recursive predicate to play moves turn by turn, starting from human move.
play_move(Side, B1) :-
    other_side(Side, OtherSide),
    print_board(B1),
    play_input_move_common(Side, B1, B2),
    write('\n'), write(Side), write(' moving:\n'),
    print_board(B2),
    can_move(OtherSide, B2),
    smart_move(OtherSide, B2, B3),
    write('\n'), write(OtherSide), write(' moving:\n'),
    play_move(Side, B3).

% Main goal to start the game.
play :-
    player_select_side(Side),
    initial_board(B1),
    (
        (Side = black, smart_move(white, B1, B2), !, play_move(Side, B2));
        (Side = white, play_move(Side, B1))
    ).
