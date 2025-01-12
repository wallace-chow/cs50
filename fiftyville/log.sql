-- check info from interviews that happen in "Humphery Street"
SELECT transcript FROM interviews
WHERE year = 2024 AND month = 7 AND day = 28;
SELECT description FROM crime_scene_reports
WHERE year = 2024 AND month = 7 AND day = 28 AND street = "Humphrey Street";
-- theft happened at 1015am
-- car with thief drove off within 10 minutes of the theft from bakery parking lot
-- thief withdrew money from atm at Leggett Street
-- called someone for less than a minute to take the earliest flight out of fiftyville tommorow EARLY IN THE MORNING.
-- left diana and bruce, I should check if either of them flew.

SELECT name, passport_number, phone_number FROM people
WHERE people.license_plate IN
(
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2024 AND month = 7 AND day = 28
    AND
    hour = 10 AND minute <=25 AND minute >=15
    AND
    activity = "exit"
)
AND
people.id IN
(
    SELECT person_id FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number FROM atm_transactions
        WHERE year = 2024 AND month = 7 AND day = 28
        AND
        transaction_type = 'withdraw'
        AND
        atm_location = 'Leggett Street'
    )
)
AND
people.phone_number IN
(
    SELECT caller FROM phone_calls
    WHERE year = 2024 AND month = 7 AND day = 28
    AND
    duration <=60
)
AND
people.passport_number IN
(
    SELECT passport_number FROM passengers
    WHERE passengers.flight_id IN
    (
        SELECT id FROM flights
        WHERE year = 2024 AND month = 7 AND day = 29 AND hour <= 12
        AND origin_airport_id IN
        (
            SELECT id FROM airports
            WHERE city = "Fiftyville"
        )
    )
);
-- bruce is the thief, phone_number (367) 555-5533
-- checking destination
SELECT city FROM airports
WHERE airports.id IN
(
    SELECT destination_airport_id FROM flights
    WHERE flights.id =
    (
        SELECT flight_id FROM passengers
        WHERE passport_number = 5773159633
    )
    AND
    year = 2024 AND month = 7 AND day = 29
);
-- new york city
-- now checking for accomplice
SELECT name FROM people
WHERE phone_number IN
(
    SELECT receiver FROM phone_calls
    WHERE year = 2024 AND month = 7 AND day = 28
    AND
    duration <= 60
    AND
    caller = "(367) 555-5533"
)
-- robin is the accomplice LOL
