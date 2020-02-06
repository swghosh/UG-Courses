% car(Person, Color): person Person has a car of Color color.
car(john, white).
car(luna, red).
car(ben, black).

% downtown(X): place Downtown exists in in city X.
downtown(manhattan, newyork).
downtown(newtown, kolkata).

% bigger(X, Y): X is bigger than Y
bigger(elephant, ant).
bigger(ant, fly).

% is_bigger(X, Y): X is bigger than Y or not
is_bigger(AnimalX, AnimalY) :- bigger(AnimalX, AnimalZ), bigger(AnimalZ, AnimalY).

% likes(X, Y): X is liked by Y
likes(john, mary).
likes(john, trains).
likes(peter, fast_cars). 

% Person1 like Person2 if they have a common hobby
likes(Person1, Person2):- 
    hobby(Person1 ,Hobby), hobby(Person2, Hobby).

% hobby(X, Y): person X has hobby Y
hobby(john,trainspotting). 
hobby(tim,sailing). 
hobby(helen,trainspotting). 
hobby(simon,sailing).