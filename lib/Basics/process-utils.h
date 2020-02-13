////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2016 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Esteban Lombeyda
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_BASICS_PROCESS__UTILS_H
#define ARANGODB_BASICS_PROCESS__UTILS_H 1

#include <string>
#include <vector>

#include "Basics/Common.h"
#include "Basics/threads.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief invalid process id
////////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
#define TRI_INVALID_PROCESS_ID (0)
#else
#define TRI_INVALID_PROCESS_ID (-1)
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief returns information about the process
////////////////////////////////////////////////////////////////////////////////

struct ProcessInfo {
  uint64_t _minorPageFaults;
  uint64_t _majorPageFaults;
  uint64_t _userTime;
  uint64_t _systemTime;
  int64_t _numberThreads;
  int64_t _residentSize;  // resident set size in number of bytes
  uint64_t _virtualSize;
  uint64_t _scClkTck;

  ProcessInfo();
};

////////////////////////////////////////////////////////////////////////////////
/// @brief status of an external process
////////////////////////////////////////////////////////////////////////////////

typedef enum {
  TRI_EXT_NOT_STARTED = 0,  // not yet started
  TRI_EXT_PIPE_FAILED = 1,  // pipe before start failed
  TRI_EXT_FORK_FAILED = 2,  // fork failed
  TRI_EXT_RUNNING = 3,      // running
  TRI_EXT_NOT_FOUND = 4,    // unknown pid
  TRI_EXT_TERMINATED = 5,   // process has terminated normally
  TRI_EXT_ABORTED = 6,      // process has terminated abnormally
  TRI_EXT_STOPPED = 7,      // process has been stopped
  TRI_EXT_TIMEOUT = 9       // waiting for the process timed out
} TRI_external_status_e;

////////////////////////////////////////////////////////////////////////////////
/// @brief identifier of an external process
////////////////////////////////////////////////////////////////////////////////

#ifndef _WIN32
struct ExternalId {
  TRI_pid_t _pid;
  int _readPipe;
  int _writePipe;
  ExternalId();
};
#else
struct ExternalId {
  DWORD _pid;
  HANDLE _readPipe;
  HANDLE _writePipe;

  ExternalId();
  virtual ~ExternalId() {}
};
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief external process description
////////////////////////////////////////////////////////////////////////////////

struct ExternalProcess : public ExternalId {
  std::string _executable;
  size_t _numberArguments;
  char** _arguments;

#ifdef _WIN32
  HANDLE _process;
#endif

  TRI_external_status_e _status;
  int64_t _exitStatus;

  ~ExternalProcess();
  ExternalProcess();
};

////////////////////////////////////////////////////////////////////////////////
/// @brief external process status
////////////////////////////////////////////////////////////////////////////////

extern std::vector<ExternalProcess*> ExternalProcesses;

////////////////////////////////////////////////////////////////////////////////
/// @brief external process status
////////////////////////////////////////////////////////////////////////////////

struct ExternalProcessStatus {
  TRI_external_status_e _status;
  int64_t _exitStatus;
  std::string _errorMessage;

  ExternalProcessStatus();
};

////////////////////////////////////////////////////////////////////////////////
/// @brief converts usec and sec into seconds
////////////////////////////////////////////////////////////////////////////////

#ifdef ARANGODB_HAVE_GETRUSAGE
uint64_t TRI_MicrosecondsTv(struct timeval* tv);
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief returns information about the current process
////////////////////////////////////////////////////////////////////////////////

ProcessInfo TRI_ProcessInfoSelf(void);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns information about the process
////////////////////////////////////////////////////////////////////////////////

ProcessInfo TRI_ProcessInfo(TRI_pid_t pid);

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the process name
////////////////////////////////////////////////////////////////////////////////

void TRI_SetProcessTitle(char const* title);

////////////////////////////////////////////////////////////////////////////////
/// @brief starts an external process
////////////////////////////////////////////////////////////////////////////////

void TRI_CreateExternalProcess(char const* executable,
                               std::vector<std::string> const& arguments,
                               std::vector<std::string> additionalEnv,
                               bool usePipes, ExternalId* pid);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the status of an external process
////////////////////////////////////////////////////////////////////////////////

ExternalProcessStatus TRI_CheckExternalProcess(ExternalId pid, bool wait, uint32_t timeout);

////////////////////////////////////////////////////////////////////////////////
/// @brief kills an external process
////////////////////////////////////////////////////////////////////////////////

ExternalProcessStatus TRI_KillExternalProcess(ExternalId pid, int signal, bool isTerminal);

////////////////////////////////////////////////////////////////////////////////
/// @brief suspends an external process, only on Unix
////////////////////////////////////////////////////////////////////////////////

bool TRI_SuspendExternalProcess(ExternalId pid);

////////////////////////////////////////////////////////////////////////////////
/// @brief continue an external process, only on Unix
////////////////////////////////////////////////////////////////////////////////

bool TRI_ContinueExternalProcess(ExternalId pid);

////////////////////////////////////////////////////////////////////////////////
/// @brief shut downs the process components
////////////////////////////////////////////////////////////////////////////////

void TRI_ShutdownProcess();

#endif
