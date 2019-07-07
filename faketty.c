#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <utmp.h>


int main(int argc, char *argv[]) {
  struct utmp entry;
  entry.ut_type = USER_PROCESS;
  entry.ut_pid = 1;
  strcpy(entry.ut_line, "tty12");
  strcpy(entry.ut_id, "");
  time(&entry.ut_time);
  strcpy(entry.ut_user, getpwuid(getuid())->pw_name);
  memset(entry.ut_host, 0, UT_HOSTSIZE);
  entry.ut_addr = 0;
  setutent();

  memset(entry.ut_addr_v6, 0, 4 * sizeof(int32_t));

  pututline(&entry);
  endutent();
  exit(EXIT_SUCCESS);

}
