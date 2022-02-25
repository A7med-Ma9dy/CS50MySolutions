select title from movies
join ratings on movies.id = ratings.movie_id
join stars on ratings.movie_id = stars.movie_id
join people on stars.person_id = people.id
where name = "Chadwick Boseman"
order by ratings.rating DESC limit 5;

/*
SELECT movies.title from people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings on movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;*/