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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils/repl.h"
#include "utils/getline.h"

// See meaning on "utils/repl.h"
void REPL() {
  while (1) {
    // An repl uses an "infinite" number of chars in input which means that NO LIMIT 
    // to achieve this, I'll make a custom version of getline(). 
    char* input = getLine(); // in here, we use a pointer to make it dynamically expandable
    printf(">>> "); // print the starting thing
    if (strcmp(input, "exit\n") == 0){
        free(input);
        input = NULL;
        exit(0);
    }
    else if (strcmp(input, "linktocode\n") == 0){
        printf("https://github.com/johnryzon123/Ciya.git");
    }
    else{
        printf("%s\n", input);
    }
    free(input); // make sure we free the pointer, we don't want any memory leaks
    input = NULL;
  }
}
