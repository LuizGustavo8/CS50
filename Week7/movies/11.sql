--write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT m.title
FROM movies m
JOIN ratings r ON m.id = r.movie_id
WHERE m.id IN (
    SELECT s.movie_id
    FROM stars s
    WHERE s.person_id = (
        SELECT p.id
        FROM people p
        WHERE p.name = 'Chadwick Boseman'
    )
)
ORDER BY r.rating DESC
LIMIT 5;
