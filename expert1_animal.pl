% Expert system to identify animals based on characteristics

% Main rule to diagnose the animal
diagnose_animal :- 
    write('What is the animal?'), nl,
    identify_animal(Animal),
    write('The animal is: '), write(Animal), nl.

% Rules to identify animals based on characteristics
identify_animal(lion) :- lion, !.
identify_animal(tiger) :- tiger, !.
identify_animal(eagle) :- eagle, !.
identify_animal(shark) :- shark, !.
identify_animal(unknown).

% Animal rules
lion :- 
    mammal,
    carnivore,
    has_mane,
    verify(does_roar).

tiger :- 
    mammal,
    carnivore,
    has_stripes.

eagle :- 
    bird,
    carnivore,
    verify(can_fly),
    verify(has_sharp_beak).

shark :- 
    fish,
    carnivore,
    verify(has_fins),
    verify(has_gills).

% Basic features
mammal :- verify(has_fur).
bird :- verify(has_feathers).
fish :- verify(lives_in_water).

carnivore :- verify(eats_meat).

has_mane :- verify(has_mane).
has_stripes :- verify(has_stripes).

% Verification method for user input
verify(Characteristic) :- 
    write('Does the animal have the following characteristic: '),
    write(Characteristic), 
    write('? (yes/no): '), 
    read(Response), 
    Response = yes.

% Start the expert system
start :-
    write('Welcome to the animal diagnosis expert system!'), nl,
    write('Please answer the following questions about the animal.'), nl,
    diagnose_animal, nl,
    write('Thanks for using the system!'), nl.
