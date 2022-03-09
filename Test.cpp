#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include<string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

//Good input 
TEST_CASE("basic case ") {
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));}

TEST_CASE("odd number ") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces( "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(5, 9, '$', '#')) == nospaces("$$$$$\n"
													"$###$\n"
													"$#$#$\n"
													"$#$#$\n"
                                                    "$#$#$\n"
                                                    "$#$#$\n"
													"$#$#$\n"
													"$###$\n"
													"$$$$$"));
    CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@\n"));


    CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                    "@-@\n"
                                                    "@@@"));}                                                

TEST_CASE("Various signs") {
	CHECK(nospaces(mat(1, 5, '+', '-')) == nospaces( "@\n"
													 "@\n"
													 "@\n"
                                                     "@\n"
                                                     "@\n"));
    CHECK(nospaces(mat(3, 3, '@', '@')) == nospaces("@@@\n"
                                                    "@@@\n"
                                                    "@@@"));}

TEST_CASE("Same length") {
    string a = nospaces(mat(3, 5, '$', '+'));
	CHECK(a.length() == 15);                                                        
}

//Bad input

TEST_CASE("not char") {
    CHECK_THROWS(mat(10, 10, 1, 4));
    CHECK_THROWS(mat(2, 1, '$', 2));
    CHECK_THROWS(mat(1, 2, 4, '%'));                                                        
}
TEST_CASE("non positive numbers") {
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(-1, 2, '$', '%'));
    CHECK_THROWS(mat(0, -8, '$', '%'));
    CHECK_THROWS(mat(-1, -8, '$', '%'));                                                      
}
TEST_CASE("not numbers") {
    CHECK_THROWS(mat( '$', '%', '$', '%'));
    CHECK_THROWS(mat( '$', 1, '$', '%'));
    CHECK_THROWS(mat( 1, '%', '$', '%'));                                                      
}
TEST_CASE("even numbers") {
    CHECK_THROWS(mat(8, 8, '$', '%'));
    CHECK_THROWS(mat(2, 1, '$', '%'));
    CHECK_THROWS(mat(1, 2, '$', '%'));                                                        
}
TEST_CASE("Difrent length") {
    string a = nospaces(mat(3, 5, '$', '+'));
	CHECK(a.length() == 16 );                                                        
}

