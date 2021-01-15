cmake_minimum_required(VERSION 3.0.0)

# project(module4 VERSION 0.0.1)

message("Hello ....'world'")

set(NAME "Fred Jones")
# set(NAME Fred Jones)
set(HEIGHT 17)

message("Hello, my name is ${NAME}, my height is ${HEIGHT}, and I am ${AGE} years old")

set(VAR aa bb cc)

message(${VAR})
message("${VAR}")

set(VAR2 "aa" "bb" "cc")
message(${VAR2})
message("${VAR2}")

set(VAR3 "aa bb cc")
message(${VAR3})
message("${VAR3}")

set(VAR4 "aa;bb;cc")
message(${VAR4})
message("${VAR4}")