/*select name from people where id in
(select person_id from stars where movie_id in
(select movie_id from stars where person_id in
(select id from people where name = "Kevin Bacon" and birth = 1958)))
and name != "Kevin Bacon";*/


--another solution

select name from people
join stars on people.id = stars.person_id
where stars.movie_id in (select stars.movie_id from people
JOIN stars on people.id = stars.person_id
where people.name = "Kevin Bacon" and people.birth = 1958) and people.name != "Kevin Bacon";