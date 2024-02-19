--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE p.id IN (
    SELECT DISTINCT s2.person_id
    FROM stars s1
    JOIN stars s2 ON s1.movie_id = s2.movie_id
    JOIN people p1 ON s1.person_id = p1.id
    JOIN people p2 ON s2.person_id = p2.id
    WHERE p1.name = 'Kevin Bacon' AND p1.birth = '1958' --Check for 1958 Kevin
)
AND p.name != 'Kevin Bacon'; -- Exclude Kevin Bacon from the result
