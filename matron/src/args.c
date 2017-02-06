#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_BUF_SIZE 64

struct args {
  char loc_port[ARG_BUF_SIZE];
  char rem_port[ARG_BUF_SIZE];
  char monome_path[ARG_BUF_SIZE];
};

static struct args a = {
  .loc_port = "8888",
  .rem_port = "57120",
  .monome_path = "/dev/ttyUSB0"
};

int args_parse(int argc, char** argv)
{
  int flags, opt;
  while( (opt = getopt(argc, argv, "r:l:m:")) != -1 ) {
	switch(opt) {
	case 'l':
	  strncpy(a.loc_port, optarg, ARG_BUF_SIZE);
	  break;
	case 'r':	   
	  strncpy(a.rem_port, optarg, ARG_BUF_SIZE);
	  break;
	case 'm':	   
	  strncpy(a.monome_path, optarg, ARG_BUF_SIZE);
	  break;
	default:
	  ;;
	}
  }
  //  printf("local port: %s ; remote port: %s \n", a.loc_port, a.rem_port);
}


const char* args_local_port(void) {
  return a.loc_port;
}

const char* args_remote_port(void) {
  return a.rem_port;
}


const char* args_monome_path(void) {
  return a.monome_path;
}
