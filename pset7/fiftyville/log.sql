-- Keep a log of any SQL queries you execute as you solve the mystery.
--All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.
select description from crime_scene_reports where day = 28 and month = 7 and year = 2020 and street = 'Chamberlin Street';
--description
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

select transcript from interviews where day = 28 and month = 7 and year = 2020 and transcript like '%courthouse%'';
/*transcript
-Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

-I don't know the thief's name, but it was someone I recognized.
Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

-As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone to purchase the flight ticket.*/


--1st transcript--get license_plate for people table
select license_plate from courthouse_security_logs
where day = 28 and month = 7 and year=2020 and hour = 10 and minute >= 15 and minute <=25 and activity = 'exit';

--2nd transcript--get account number for person_id for pepole table
select person_id from bank_accounts
join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
where day = 28 and month = 7 and year=2020 and atm_location = 'Fifer Street' and transaction_type = 'withdraw';

--to sum up -> 4 total suspects
select name from people
   ...> join bank_accounts on people.id = bank_accounts.person_id
   ...> join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
   ...> where people.license_plate in (select license_plate from courthouse_security_logs
   ...> where day = 28 and month = 7 and year=2020 and hour = 10 and minute >= 15 and minute <=25 and activity = 'exit')
   ...> and day = 28 and month = 7 and year=2020 and atm_location = 'Fifer Street' and transaction_type = 'withdraw';
name
Ernest
Russell
Elizabeth
Danielle


--3rd transcript--get phone number for caller --> 2 suspects
select name from people
   ...> join bank_accounts on people.id = bank_accounts.person_id
   ...> join atm_transactions on bank_accounts.account_number = atm_transactions.account_number

   ...> where people.license_plate in (select license_plate from courthouse_security_logs
   ...> where day = 28 and month = 7 and year=2020 and hour = 10 and minute >= 15 and minute <=25 and activity = 'exit')

   ...> and people.phone_number in (select caller from phone_calls
   ...> where day = 28 and month = 7 and year=2020 and duration < 60)

   ...> and day = 28 and month = 7 and year=2020 and atm_location = 'Fifer Street' and transaction_type = 'withdraw';
name
Ernest
Russell

--get passport number to complete people table to get thief name // we can also use intersect between queries
select name from people
   ...> join bank_accounts on people.id = bank_accounts.person_id
   ...> join atm_transactions on bank_accounts.account_number = atm_transactions.account_number

   ...> where people.license_plate in (select license_plate from courthouse_security_logs
   ...> where day = 28 and month = 7 and year=2020 and hour = 10 and minute >= 15 and minute <=25 and activity = 'exit')

   ...> and people.phone_number in (select caller from phone_calls
   ...> where day = 28 and month = 7 and year=2020 and duration < 60)

   ...> and people.passport_number in (select passport_number from passengers
   ...> where flight_id = (select id from flights
   ...> where year= 2020 and month = 7 and day = 29 order by hour, minute limit 1))

   ...> and day = 28 and month = 7 and year=2020 and atm_location = 'Fifer Street' and transaction_type = 'withdraw';
name
Ernest


--The thief ESCAPED TO
select city from airports
   ...> where id = (select destination_airport_id from flights
   ...> where year= 2020 and month = 7 and day = 29 order by hour, minute limit 1);
city
London


--The ACCOMPLICE
select name from people
   ...> join phone_calls on people.phone_number = phone_calls.receiver
   ...> where day = 28 and month = 7 and year=2020 and duration < 60
   ...> and caller = (select phone_number from people
   ...> where name = 'Ernest');
name
Berthold
