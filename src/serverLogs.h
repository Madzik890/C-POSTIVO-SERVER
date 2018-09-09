#ifndef SERVERLOGS_H
#define SERVERLOGS_H

typedef enum logsError logsError;
enum logsError
{
  successful, //successful
  noOpen,      //cannot read a file
  cannotWrite  //cannot write to a file
};

typedef enum logsLevel logsLevel;
enum logsLevel
{
  none,       //no logs
  minimal,    //only functions called by users
  normal,     //functions called by the user, some date
  high,
  all         //writes logins, password and all date
};

/// <global instances>
extern logsLevel g_logsLevel;
/// <global instances>

logsError createLogs();
logsError writeLogs(const char * line);
void closeLogs();

#endif
