#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

enum TokenType {
  KEYWORD,
  IDENTIFIER,
  CONSTANT,
  SYMBOL
};

char token[MAX_TOKEN_LENGTH];
enum TokenType tokenType;

void getToken(char *line) {
  int i = 0;
  while (isspace(line[i])) {
    i++;
  }

  int j = 0;
  if (isalpha(line[i]) || line[i] == '_') {
    while (isalnum(line[i]) || line[i] == '_') {
      token[j++] = line[i++];
    }
    token[j] = '\0';
    tokenType = IDENTIFIER;

    // Check if the token is a keyword
    if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0 || strcmp(token, "void") == 0) {
      tokenType = KEYWORD;
    }
  } else if (isdigit(line[i])) {
    while (isdigit(line[i])) {
      token[j++] = line[i++];
    }
    token[j] = '\0';
    tokenType = CONSTANT;
  } else if (ispunct(line[i])) {
    token[j++] = line[i++];
    token[j] = '\0';
    tokenType = SYMBOL;
  }
}

int main() {
  char line[1000];

  while (fgets(line, 1000, stdin) != NULL) {
    int i = 0;
    while (line[i] != '\0') {
      getToken(line + i);
      printf("Token: %s\n", token);
      printf("Type: %d\n", tokenType);
      i += strlen(token);
    }
  }

  return 0;
}
