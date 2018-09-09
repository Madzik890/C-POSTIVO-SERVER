#include "serverLogs.h"
#include <stdio.h>//files
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OPEN_MODE "ab+"

/// <members instance>
FILE * m_fileLog;//the file log
char * s_fileDir;//direction to the file log
/// <members instance>

/// <global instances>
logsLevel g_logsLevel = none;
/// <global instances>

/// <summary>
/// Creates the file which stores logs.
/// <summary>
/// <return> State of the operation. </return>
logsError createLogs()
{
  if(g_logsLevel != none)
  {
    time_t m_time = time(NULL);
    struct tm *m_tm = localtime(&m_time);
    char s_string[64];
    strftime(s_string, sizeof(s_string), "%c", m_tm);

    m_fileLog = fopen(s_string, OPEN_MODE);
  }
  if(fopen != NULL)
    return successful;
  else
    return noOpen;
}

/// <summary>
/// Prints log to the file.
/// </summary>
/// <param name = "line"> The line of log </param>
/// <result> State of the operation. </result>
logsError writeLogs(const char * line)
{
  if(m_fileLog != NULL && g_logsLevel != none)
  {
    time_t m_rawtime;
    struct tm * m_timeinfo;
    time ( &m_rawtime );
    m_timeinfo = localtime ( &m_rawtime );
    char * s_time = asctime (m_timeinfo);
    char * s_endLine  = " \n";

    fwrite(s_time, 1, strlen(s_time) - 1, m_fileLog);
    fwrite(line, 1, strlen(line), m_fileLog);
    fwrite(s_endLine, 1, strlen(s_endLine), m_fileLog);

    return successful;
  }
  else
    return cannotWrite;
}

/// <summary>
/// Closes the log files.
/// </summary>
void closeLogs()
{
  fclose(m_fileLog);
}
