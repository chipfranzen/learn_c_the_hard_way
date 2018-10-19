#include <glob.h>
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
  int matched_glob_count;
  char *log_to_search;

  while (logfile[0] != '\0') {
    glob_t pglob;
    glob(logfile, 0, 0, &pglob);
    matched_glob_count = (int)pglob.gl_pathc;
    printf("Logfile: %s, Globs matched: %d\n", logfile, matched_glob_count);

    int i = 0;
    for (i = 0; i < matched_glob_count; i++){
      log_to_search = pglob.gl_pathv[i];
      search_log(log_to_search, argv, argc, oflag);
      ++logfile_count;
    }

    logfile = readline(fp);
    globfree(&pglob);
  }

  return 0;


}
