#include "booking.h"
#include <cassert>
#include <iostream>

class Test {
public:
    Test() {
        reset();
    }
    void reset() {
        test_system = System{};
        test_system.add_user("user1");
        test_system.add_user("user2");
        test_system.add_movie("movie1", 10);
        test_system.add_movie("movie2", 15);
        test_system.book_tickets("movie1", 5, "user1");
        test_system.book_tickets("movie2", 10, "user2");
    }
    static Test &get_instance() {
        static Test instance;
        return instance;
    }

    void test_add_booking() {
        assert(test_system.book_tickets("movie1", 5, "user1") == true);
        assert(test_system.book_tickets("movie1", 5, "user2") == false);
        assert(test_system.book_tickets("movie1", 5, "user2") == false);
        assert(test_system.book_tickets("movie2", 5, "user2") == true);
        assert(test_system.book_tickets("movie2", 5, "user1") == false);
        assert(test_system.book_tickets("movie2", 10, "user2") == false);
        std::cout << "Test booking tickets" << std::endl;
        reset();
    }

    void test_cancel_booking() {

        assert(test_system.cancel_tickets("movie1", 5, "user1") == true);
        assert(test_system.cancel_tickets("movie1", 5, "user1") == false);
        assert(test_system.cancel_tickets("movie2", 5, "user2") == true);
        assert(test_system.cancel_tickets("movie2", 7, "user2") == false);
        std::cout << "Test cancel tickets" << std::endl;
        reset();
    }

    void test_get_seats() {
        assert(test_system.book_tickets("movie1", 5, "user1") == true);
        assert(test_system.get_seats("movie1") == 0);
        assert(test_system.book_tickets("movie2", 5, "user2") == true);
        assert(test_system.get_seats("movie1") == 0);
        assert(test_system.cancel_tickets("movie1", 5, "user1") == true);
        assert(test_system.get_seats("movie1") == 5);
        std::cout << "Test booking tickets" << std::endl;
        reset();
    }

private:
    System test_system{};
};

int main() {
    Test::get_instance().test_add_booking();
    Test::get_instance().test_cancel_booking();
    Test::get_instance().test_get_seats();
    return 1;
}