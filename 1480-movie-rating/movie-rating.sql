# Write your MySQL query statement below
(
SELECT u.name AS results
FROM Users u
JOIN MovieRating m ON u.user_id = m.user_id
GROUP BY u.user_id
ORDER BY COUNT(*) DESC, u.name
LIMIT 1
)

UNION ALL

(
SELECT mv.title AS results
FROM Movies mv
JOIN MovieRating mr ON mv.movie_id = mr.movie_id
WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY mv.movie_id
ORDER BY AVG(mr.rating) DESC, mv.title
LIMIT 1
);