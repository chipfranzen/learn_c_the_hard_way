#ifndef LOGFIND
#define LOGFIND

char *readline(FILE *fp);

FILE *load_log_files(void);

void search_log(char *logfile, char **keywords, int n_kws, int or);

#endif
