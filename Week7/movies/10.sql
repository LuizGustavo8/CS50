--write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0
SELECT DISTINCT p.name
FROM people p
JOIN directors d ON p.id = d.person_id
JOIN movies m ON m.id = d.movie_id
JOIN ratings r ON m.id = r.movie_id
WHERE r.rating >= 9.0;
