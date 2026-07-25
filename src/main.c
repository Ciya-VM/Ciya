/*
Ciya: a future programming language VM that is hoped to be more successful than the successor, "CRy"
    Copyright (C) 2026  Johnryzon Z. Abejero, <please put your name here>

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

typedef struct Var {
  char Testing[LIMIT_TEST];
} Var; // Typedef name

void call(const char *string) { //Function to call
  printf("%s", string);
}

int main() {
  // Use Variable1 (or struct Variables1)
  Var writing = {"Testing...testing\n"};
  Var *ptr = &writing;

  call(ptr->Testing);
  return 0;
}
