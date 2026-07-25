/*
Ciya: a future programming language VM that is hoped to be a bigger leap than the successor, "CRy"
    Copyright (C) 2026  Johnryzon Z. Abejero, Nguyễn Phước Thành Lâm

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <stdio.h> //For printf()

#define LIMIT_TEST 19 // Added a char limit for the project

typedef struct Var{ 
  char Testing[LIMIT_TEST];//The char
} Var; // Typedef name

void callstr(const char *string) { //Function to call string
  printf("%s", string);//Use printf for compatiable purposes
}

int main() { //The main function
  // Use Var (or struct Var)
  Var writing = {"Testing...testing\n"};
  Var *ptr = &writing;//To point ptr to writing

  callstr(ptr->Testing);//Call the function variable
  return 0;//It didn't fail, hopefully
}
