/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
  char *buf, *p;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  char header[MAXLINE] = "";
  int n1=0, n2=0;

  if ((buf = getenv("QUERY_STRING")) != NULL) {
    p = strchr(buf, '&');
    *p = '\0';
    strcpy(arg1, buf);
    strcpy(arg2, p+1);
    p = strchr(arg1, '=');
    *p = '\0';
    strcpy(arg1, p+1);
    p = strchr(arg2, '=');
    *p = '\0';
    strcpy(arg2, p+1); 
    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }
  sprintf(content, "QUERY_STRING=%s", buf);
  strcat(header, content);
  sprintf(content, "Welconme to add.com: ");
  strcat(header, content);
  sprintf(content, "%sTHE Internet addition portal. \r\n<p>", content);
  strcat(header, content);
  sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1+n2);
  strcat(header, content);
  sprintf(content, "%sThanks for visiting!\r\n", content);
  strcat(header, content);

  printf("Connection: close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(header));
  printf("Content-type: text/html\r\n\r\n");
  printf("%s", header);
  fflush(stdout);

  exit(0);
}
/* $end adder */