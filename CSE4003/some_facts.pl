% downtown(X): place Downtown exists in in city X.
downtown(manhattan).
downtown(newtown).

% student(Name, Ext): student has Name and Ext phone number
student(swarup, 1024).
student(shubham, 1023).
student(smahi, 1022).

father(tom, sam).
father(mi, tom).

grandfather(Grandfather, Grandchildren) :- father(Grandfather, Child), father(Child, Grandchildren).