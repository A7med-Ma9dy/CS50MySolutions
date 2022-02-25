/*select distinct name from people where id in (select person_id from directors where movie_id in (select movie_id from ratings where rating >= 9.0));*/
select distinct name from people
join directors on people.id = directors.person_id
join movies on movies.id = directors.movie_id
join ratings on movies.id = ratings.movie_id
where rating >= 9.0;