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
#include <stdio.h>
#include <stdlib.h>
#include "utils/getline.h"
#define STARTING_INPUT_SIZE 15

char* getLine() {
  int/*char*/ c;
  char* input;
  unsigned int capacity = STARTING_INPUT_SIZE;
  unsigned int count = 0;

  input = malloc(sizeof(char) * capacity);
  if (input == NULL) {
    exit(EXIT_FAILURE);
  }
  while ((c = getchar()) != '\n' && c != EOF) {
    if (count >= capacity) {
      input = realloc(input, capacity *= 2);
    }

     input[count++] = c;
  }
  input[count] = '\0';
  return input;
}
