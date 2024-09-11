/*
You are required to design a simple library for a Movie Ticket Booking System. The system should support the following functionalities:

Adding Movies: Add new movies to the system.
Booking Tickets: Book tickets for a specific movie.
Canceling Tickets: Cancel previously booked tickets.
Viewing Available Seats: View the available seats for a specific movie.


Questions:
are there mutiple halls? No just one hall
Adding movies: Timings? Particular hall? From date? To date? no from date, just add, available all day
Booking tickets: Timings, hall, date? No timings or date, just ticket
Cancel tickets: What are the conditions? Results? Like refund, seat opening up No conditions, just open up
Available seats: Hall, speicfic movie, date, time? just based on movie


Nouns and verbs:
Movie
System
User

Book, 
cancel
check seats
add movie
*/

#ifndef _LIBRARY_MOVIE_BOOKING_BOOKING_H
#define _LIBRARY_MOVIE_BOOKING_BOOKING_H

#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>
