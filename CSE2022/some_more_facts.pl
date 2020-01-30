% downtown(X): place Downtown exists in in city X.
downtown(manhattan, newyork).
downtown(newtown, kolkata).

% bigger(X, Y): X is bigger than Y
bigger(elephant, ant).
bigger(ant, fly).

% is_bigger(X, Y): X is bigger than Y or not
is_bigger(AnimalX, AnimalY) :- bigger(AnimalX, AnimalZ), bigger(AnimalZ, AnimalY).

likes(john,mary).
likes(john,trains).
likes(peter,fast_cars). 
likes(Person1,Person2):- hobby(Person1,Hobby), hobby(Person2,Hobby).
hobby(john,trainspotting). 
hobby(tim,sailing). 
hobby(helen,trainspotting). 
hobby(simon,sailing).