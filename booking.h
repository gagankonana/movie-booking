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
class Movie {
public:
    Movie(const std::string& _name, const int _total_seats) 
        : name{_name}, total_seats{_total_seats}, seats_left{_total_seats} {}
    std::string get_name() { return name; }
    int get_seats_left() { return seats_left; }
    int get_total_seats() { return total_seats; }
    void book_seats(int x) { seats_left -= x; }
    void cancel_seats(int x) {seats_left += x; }
private:
    std::string name;
    int total_seats;
    int seats_left;
};

class User {
public:
    User(const std::string& _name) : name{_name} {}
    void add_booking(const std::string& movie_name, const int tickets) { bookings[movie_name] += tickets; }
    void cancel_booking(const std::string& movie_name, const int tickets) {
        bookings[movie_name] -= tickets;
    }
    const int get_booking(const std::string& movie_name) { return bookings[movie_name]; }
    const std::string get_name() { return name; }
private:
    std::string name;
    std::unordered_map<std::string, int> bookings;

};

class System {
public:
    System(){}
    void add_movie(const std::string& name, const int total_seats) {
        std::shared_ptr<Movie> movie = std::make_shared<Movie>(name, total_seats);
        movies[name] = movie;
    }
    void add_user(const std::string& name) {
        std::shared_ptr<User> user = std::make_shared<User>(name);
        users[name] = user;
    }
    [[nodiscard]] const bool book_tickets(const std::string& movie_name, const int tickets, const std::string& user_name) {
        if (movies[movie_name]->get_seats_left() < tickets) return false;
        users[user_name]->add_booking(movie_name, tickets);
        movies[movie_name]->book_seats(tickets);
        return true;
    }
    [[nodiscard]] const bool cancel_tickets(const std::string& movie_name, const int tickets, const std::string user_name) {
        if (users[user_name]->get_booking(movie_name) < tickets) return false;
        users[user_name]->cancel_booking(movie_name, tickets);
        movies[movie_name]->cancel_seats(tickets);
        return true;
    }
    const int get_seats(std::string movie_name) {return movies[movie_name]->get_seats_left(); }

private:
    std::unordered_map<std::string, std::shared_ptr<Movie>> movies;
    std::unordered_map<std::string, std::shared_ptr<User>> users;

};

#endif