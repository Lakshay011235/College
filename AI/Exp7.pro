remove_punctuation(InputString, CleanedString) :-
    atom_chars(InputString, InputChars), % Convert input string to a list of characters
    \+ no_punctuation(InputChars), % Check if there is no punctuation
    remove_punctuation_chars(InputChars, CleanedChars), % Remove punctuation characters
    atom_chars(CleanedString, CleanedChars). % Convert cleaned characters back to a string

% Define a predicate to check if there is no punctuation in a list of characters
no_punctuation(InputChars) :-
    \+ (member(Char, InputChars), punct(Char)). % Check if any character is a punctuation mark

% Define a predicate to remove punctuation characters from a list of characters
remove_punctuation_chars([], []). % Base case: empty list
remove_punctuation_chars([Char|RestChars], CleanedChars) :-
    % Check if the character is a punctuation mark
    punct(Char),
    !, % Cut to prevent backtracking
    remove_punctuation_chars(RestChars, CleanedChars). % Continue with the rest of the list
remove_punctuation_chars([Char|RestChars], [Char|CleanedRest]) :-
    % If the character is not a punctuation mark, keep it in the cleaned list
    remove_punctuation_chars(RestChars, CleanedRest).


% Define predicate to check if a character is a punctuation mark
punct(Char) :-
    member(Char, ['.', ',', ';', ':', '!', '?', '"', '\'', '(', ')', '[', ']', '{', '}']).

