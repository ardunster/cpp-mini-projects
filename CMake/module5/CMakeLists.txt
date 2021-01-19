cmake_minimum_required(VERSION 3.0.0)

function(print_detail name_var)
    message("My ${name_var} is ${${name_var}}")
endfunction()

set(Name George)

print_detail(Name)

set(Seven Fred)
print_detail(Seven)

set("favorite nut" pistachio)
print_detail("favorite nut")

set(noun adjective)
print_detail(noun)

set(name2 Fred)

macro(macro_detail namevar)
    message("My name is ${namevar}.")
    set(namevar Steve)
    message("My name was ${namevar}....")
endmacro()

macro_detail(${name2})

macro_detail(${name2})

set(Name CMake)
 
macro(change_name1 temp_name)
    if(DEFINED ${temp_name})
        message("1: If block executed")
    endif()
endmacro()
 
macro(change_name2 temp_name)
    if(DEFINED ${temp_name})
        message("2: If block executed")
    endif()
endmacro()
 
 
change_name1(Name)
change_name2(CMake)