/*select name from people where id in (select person_id from stars where movie_id = (select id from movies where title = "Toy Story"));*/
select name from people
join stars on people.id = stars.person_id
join movies on movies.id = stars.movie_id
where title = "Toy Story"