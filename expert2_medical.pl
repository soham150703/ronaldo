% Facts: Symptoms associated with specific diseases
symptom(fever, malaria).
symptom(headache, malaria).
symptom(chills, malaria).
symptom(sore_throat, common_cold).
symptom(runny_nose, common_cold).
symptom(cough, common_cold).
symptom(chest_pain, pneumonia).
symptom(shortness_of_breath, pneumonia).
symptom(fatigue, anemia).

% Rules: Disease diagnosis based on symptoms
diagnosis(Disease) :- 
    symptom(S1, Disease), 
    ask(S1),
    symptom(S2, Disease), 
    ask(S2).

diagnosis(Disease) :- 
    symptom(S1, Disease), 
    ask(S1).

% User interaction to check symptoms
ask(Symptom) :- 
    format("Do you have ~w? (yes/no): ", [Symptom]),
    read(Reply),
    Reply = yes.

% Fallback if no disease is diagnosed
diagnosis(unknown) :- 
    write("No diagnosis could be made based on the given symptoms."), nl.

% Main predicate to start the system
start :- 
    write("Welcome to the Medical Diagnosis Expert System!"), nl,
    write("Please answer the following questions:"), nl,
    diagnosis(Disease),
    (Disease \= unknown -> 
        format("You may have: ~w", [Disease]), nl; 
        true).
