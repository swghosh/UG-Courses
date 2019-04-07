CREATE TYPE location (
    latitude FLOAT,
    longitude FLOAT
);
CREATE TABLE note (
    id INT,
    place location,
    reminder TIMESTAMP,
    contents TEXT,
    done BOOLEAN,
    PRIMARY KEY(id)
);

SELECT * FROM note;

INSERT INTO note (id, place, reminder, contents, done) VALUES (
    1, {latitude: 20.3, longitude: 28.1},
    '2019-04-08', 'Submit file to Shivani Maam',
    false
);
INSERT INTO note (id, place, reminder, contents, done) VALUES (
    2, {latitude: 20.3, longitude: 28.1},
    '2019-04-07', 'Request classmates to attend workshop',
    true
);
INSERT INTO note (id, place, reminder, contents, done) VALUES (
    3, {latitude: 20.3, longitude: 28.1},
    '2019-04-10', 'Complete PCA assignment',
    false
);
INSERT INTO note (id, place, reminder, contents, done) VALUES (
    4, {latitude: 20.3, longitude: 28.1},
    '2019-03-29', 'Write another GCET Essay',
    false
);
INSERT INTO note (id, place, reminder, contents, done) VALUES (
    5, {latitude: 20.3, longitude: 28.1},
    '2019-04-07', 'Email Maam with running code',
    true
);

SELECT * FROM note;

SELECT * FROM note WHERE done = true ALLOW FILTERING;

UPDATE note SET done = true WHERE id = 2;

SELECT * FROM note WHERE id = 2;

DELETE FROM note WHERE id = 2;

SELECT * FROM note;

DROP TABLE note;

DROP TYPE location;