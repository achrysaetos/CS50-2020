SELECT title FROM movies WHERE year=2018;

SELECT birth FROM people WHERE name="Emma Stone";

SELECT title FROM movies WHERE year>2017 ORDER BY title;

SELECT COUNT(*) FROM ratings WHERE rating=10;

SELECT title,year FROM movies WHERE title 
LIKE "Harry Potter%" ORDER BY year;

SELECT AVG(rating) FROM movies 
INNER JOIN ratings ON movies.id=ratings.movie_id 
WHERE year=2012;

SELECT title,rating FROM movies 
INNER JOIN ratings ON movies.id=ratings.movie_id 
WHERE year=2010 
ORDER BY rating,title;

SELECT name FROM movies 
INNER JOIN stars ON movies.id=stars.movie_id 
INNER JOIN people ON stars.person_id=people.id 
WHERE title="Toy Story";

SELECT DISTINCT name FROM movies 
INNER JOIN stars ON movies.id=stars.movie_id 
INNER JOIN people ON stars.person_id=people.id 
WHERE year=2004
ORDER BY birth;

SELECT name FROM movies 
INNER JOIN ratings ON movies.id=ratings.movie_id
INNER JOIN directors ON movies.id=directors.movie_id 
INNER JOIN people ON directors.person_id=people.id 
WHERE rating>=9;

SELECT title FROM movies 
INNER JOIN stars ON movies.id=stars.movie_id 
INNER JOIN people ON stars.person_id=people.id 
INNER JOIN ratings ON movies.id=ratings.movie_id
WHERE name="Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;

SELECT title FROM movies 
INNER JOIN stars ON movies.id=stars.movie_id 
INNER JOIN people ON stars.person_id=people.id 
WHERE name="Johnny Depp" OR name="Helena Bonham Carter"
GROUP BY title
HAVING COUNT(*)>1;

SELECT name FROM people
WHERE id IN (
    SELECT person_id FROM stars
    WHERE movie_id IN (
        SELECT movie_id FROM movies 
        INNER JOIN stars ON movies.id=stars.movie_id 
        INNER JOIN people ON stars.person_id=people.id 
        WHERE name="Kevin Bacon" AND birth=1958
        )
    )
;