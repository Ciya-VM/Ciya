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
#include <stdbool.h>
#include "lexer/lexer.h"
#include "lexer/token.h"
#include <string.h>
#include "utils/repl.h"
#include "utils/getline.h"

static void debugToken(Token* token) {
  printf("==== Token ====\n");
  printf("Type: %d\n", token->type); // Note: This will print 9 for everything except for +.
  printf("Lexeme: %.*s\n\n", token->length, token->start);
}

static void debugTokens(Token** tokens) {
  while ((*tokens)->type != TOKEN_EOF) {
    debugToken(*tokens);
  }
  debugToken(*tokens);
}

static void run(Token** tokens) {
  debugTokens(tokens);
}

// See meaning on "utils/repl.h"
void REPL() {
  printf("Ciya v0.0.1 interactive REPL\n");
  // Following GNU rights
  printf("Copyright (C) 2026  Johnryzon Z. Abejero, Nguyễn Phước Thành Lâm\n");
  printf("License GPLv2: GNU GPL version 2 <http://gnu.org/licenses/gpl.html>\n");
  printf("This is entirely free software: you are free to modify and redistribute it.\n");
  printf("There is NO WARRANTY, by the law of the GPL\n");
  printf("Current commands: exit, linktosource, linktosource-html, freemem and ca\n");

  while (1) {
    // An repl uses an "infinite" number of chars in input which means that NO LIMIT 
    // to achieve this, I'll make a custom version of getline(). 
    printf(">>> "); // print the starting thing
    char* input = getLine(); // in here, we use a pointer to make it dynamically expandable
    if (strcmp(input, "exit") == 0){
      printf("Exiting...\n");
      free(input);
      input = NULL; //Don't forget the dangling pointers =)
      return;
    } else if (strcmp(input, "linktosource") == 0){ //I change link to source because the word code is broad, but source mean in where is it from 
      printf("link: https://github.com/johnryzon123/Ciya.git\n");

      #if defined(__linux__)
      system("xdg-open https://github.com/johnryzon123/Ciya.git"); 
      #elif defined(__APPLE__)
      system("open https://github.com/johnryzon123/Ciya.git");
      #elif defined(_WIN32) || defined(WIN64_)
      system("start https://github.com/johnryzon123/Ciya.git");
      #endif
      free(input);
      input = NULL;
    } else if (strcmp(input, "freemem") == 0){ //Add it to free memory (idk why)
      free(input);
      input = NULL;
      printf("Memory free!\n");
    }
    else if (strcmp(input, "linktosource-html") == 0){
      printf("link: https://github.com/Ciya-VM/Ciya-VM.github.io.git\n");

      #if defined(__linux__)
      system("xdg-open https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #elif defined(__APPLE__)
      system("open https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #elif defined(_WIN32) || defined(WIN64_)
      system("start https://github.com/Ciya-VM/Ciya-VM.github.io.git");
      #endif
      free(input);
      input = NULL;
    }
    else if (strcmp(input, "ca") == 0){
        printf("Commands: ca, linktosource, linktosource-html, freemem\n");
        free(input);
        input = NULL;
    }
    else{
      Lexer lexer = { // This line until
        .start = input, // ...
        .current = input // ...
      }; // here will be replaced by a function.
      Token temp = scanToken(&lexer);
      debugToken(&temp); // No support on multiple tokens for now
    }
    free(input); // make sure we free the pointer, we don't want any memory leaks
    input = NULL;
  }
}
