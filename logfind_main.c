#include <stdio.h>
#include <unistd.h>

#include "logfind.h"

int main(int argc, char *argv[])
{
  int oflag = 0;
  int c;

  while ((c = getopt(argc, argv, "o")) != -1)
  {
    switch(c)
    {
      case 'o':
        oflag = 1;
        break;
      default:
        oflag = 0;
    }
  }

  if (oflag == 1)
    printf("Or-ing query.");

  FILE *fp;
  char *logfile;

  fp = load_log_files();
  int logfile_count = 0;
  logfile = readline(fp);

  while (logfile[0] != '\0') {
    search_log(logfile, argv, argc, oflag);
    logfile = readline(fp);
    ++logfile_count;
  }

  return 0;


}
