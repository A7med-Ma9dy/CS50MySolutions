select title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where people.name = "Johnny Depp"
intersect
select title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where people.name = "Helena Bonham Carter";

--//another solution
/*
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = "Johnny Depp" AND movies.title IN(
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = "Helena Bonham Carter");
*/