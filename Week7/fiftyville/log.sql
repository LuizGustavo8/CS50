-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get the Description of the crimes scene report that match with the initial information (July 28 and Humphrey Street)

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- INFO:
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- – each of their interview transcripts mentions the bakery.

-- Get the name and the transcprit of the interview that transcripts that mentions the bakery in the date
SELECT name, transcript
FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

--INFO:

--Ruth: Sometime within ten minutes of the theft,
-- I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot,
-- you might want to look for cars that left the parking lot in that time frame.

-- Get the licence_plate of the bakery security logs in the time frame within 10 min (10:15~10:25)
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15;

--INFO: license_plate

--Eugene: I don't know the thief's name,
-- but it was someone I recognized. Earlier this morning,
-- before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street
-- and saw the thief there withdrawing some money.

-- Get account_number of the atm_tansactions in the date, local and type known
SELECT account_number
FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';

--INFO: account_number

--Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
-- I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- he thief then asked the person on the other end of the phone to purchase the flight ticket.

--Find the destination of the earliest flight out of Fiftyville tomorrow.
SELECT *
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2023 AND month = 7 AND day = 29
    ORDER BY hour, minute LIMIT 1
    );

--INFO: NEW YORK CITY


-- Get the passport_number of the thief
SELECT passport_number
FROM passengers
WHERE flight_id =
    (
    SELECT id
    FROM flights
    WHERE year = 2023 AND month = 7 AND day = 29
    ORDER BY hour, minute LIMIT 1
    );


--Get the number of the caller(thief) and the reciever(accomplience) info about the phone call to buy the ticket
SELECT caller, reciever
FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28 AND duration <=60;


-- FIND THE NAME OF THE THIEF: Bruce (In just One Query ;)
SELECT name
FROM people JOIN bank_accounts ON id = person_id
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28 AND duration <=60)
AND passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
        (
        SELECT id
        FROM flights
        WHERE year = 2023 AND month = 7 AND day = 29
        ORDER BY hour, minute LIMIT 1
        ))
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15)
AND account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2023 AND month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street');



-- FIND THE NAME OF THE ACCOMPLICE: Robin (In on Query too)
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28 AND duration <=60
    AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);

