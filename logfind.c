#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logfind.h"

#define LOGFILES "/Users/charlesfranzen/projects/learn_c_the_hard_way/.logfind"
#define MAX_LINE_LEN 256

char *readline(FILE *fp)
{
  char *line_buffer = malloc(sizeof(char) * MAX_LINE_LEN);

  char ch = getc(fp);

  int count = 0;

  while((ch != '\n') && (ch != EOF)) {
    if (count >= MAX_LINE_LEN - 1)
      perror("Line too long.");
    line_buffer[count] = ch;
    count ++;
    ch = getc(fp);
  }

  char *line = malloc(sizeof(char) * (count + 1));
  strncpy(line, line_buffer, count + 1);
  line[count + 1] = '\0';

  free(line_buffer);

  return line;
}

FILE *load_log_files(void)
{
  FILE *fp;

  fp = fopen(LOGFILES, "r");

  if (fp == NULL)
  {
    perror("Error while opening logfiles.\n");
    exit(-1);
  }

  return fp;
}

int or_bool_array(int *bool_array, int len_array) {
  int acc = 0;
  int i = 0;

  for (i = 0; i < len_array; i++){
    acc = acc || bool_array[i];
  }

  return acc;
}

int and_bool_array(int *bool_array, const int len_array) {
  int acc = 1;
  int i = 0;

  for (i = 0; i < len_array; i++) {
    acc = acc && bool_array[i];
    }

  return acc;
}

void search_log(char *logfile, char **keywords, const int n_kws, const int or) {
  printf("Searching file %s\n", logfile);

  FILE *fp;

  fp = fopen(logfile, "r");
  if (fp == NULL)
  {
    perror("Error while opening logfiles.\n");
    exit(-1);
  }

  char *logline;
  logline = readline(fp);
  int line_num = 0;
  int kw_present[n_kws - 1];
  int print_ln = 0;
  int i = 0;

  while (logline[0] != '\0') {
    print_ln = 0;
    for (i = 1; i < n_kws; i++) {
      if (strstr(logline, keywords[i]) != NULL) {
        kw_present[i - 1] = 1;
      } else {
        kw_present[i - 1] = 0;
      }
    }
    if (or) {
      print_ln = or_bool_array(kw_present, n_kws - 1);
    } else {
      print_ln = and_bool_array(kw_present, n_kws - 1);
    }
    if (print_ln > 0) {
      printf("%d \t %s\n", line_num, logline);
    }
    logline = readline(fp);
    line_num++;
  }
}
