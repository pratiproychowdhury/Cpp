/* strrpl("qwerty", "qw", "az") -> "azerty" */


char *strrpl (const char *orig, const char *from, const char *to) {

  char* dest, match, ptr;
  int copied = 0;
  
  // allocate space for destination string
  dest = (char *)malloc(sizeof(char)*(strlen(orig)-strlen(from)+strlen(to)))
  ptr = dest;
  
  // determine start position of substring match
  match = strstr(orig, from);
  
  if (!match)
    return orig;
  
  // copy from start to position of match
  if (orig<match) {
    strncpy(dest, orig, (match-orig));
    orig += match-orig;
    ptr += match-orig;
    copied += match-orig;
  }
  
  // copy 'to' substring
  strncpy(ptr, to, (strlen(to));
  ptr += strlen(to);
  copied += strlen(to)
  
  // copy rest of original string
  strncpy(ptr, match+strlen(from), (strlen(orig)-copied));
  
  return dest;
}
