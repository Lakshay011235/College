sort_sentence([], []).

% Base case: Empty list remains empty after sorting
sort_sentence(Sentence, [Min | Sorted]) :-
  find_min(Sentence, Min),
  remove_from_list(Sentence, Min, Remaining),
  sort_sentence(Remaining, Sorted).

% Base case: Minimum of a single word list is the word itself
find_min([Word], Word).

% Recursive case: Compare first two words
find_min([Word1, Word2 | Rest], Min) :-
  Word1 @=< Word2, % If Word1 is less than or equal to Word2
  find_min([Word1 | Rest], Min).

find_min([Word1, Word2 | Rest], Min) :-
  Word1 @> Word2, % If Word1 is greater than Word2
  find_min([Word2 | Rest], Min).

% Base case: Empty list after removing element
remove_from_list([], _, []).

% Element found at head, return remaining list
remove_from_list([X | Xs], X, Xs).

% Recursive case: Element not found at head, continue searching
remove_from_list([Y | Ys], X, [Y | Zs]) :-
  remove_from_list(Ys, X, Zs).

