#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


void procesy()
{
  printf("UID: %i ", getuid());
  printf("GID: %i ", getgid());
  printf("PID: %i ", getpid());
  printf("PPID: %i ", getppid());
  printf("PGID: %i ", getpgrp());
  printf ("\n");
}

int main()
{
  procesy();
  sleep(2);
  return 0;
}
