# Simple Shell Implementation

![Shell Logo](https://i.imgur.com/ZN8TaBE.png)

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](./LICENSE.txt) [![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

A lightweight Unix command line interpreter written in C that supports basic shell functionality, including command execution, path resolution, and built-in commands.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Architecture](#project-architecture)
- [Installation](#how-to-use)
- [Usage](#how-to-use)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Built-in Commands](#built-in-commands)
- [Implementation Details](#implementation-details)
- [Examples](#examples)
- [Troubleshooting](#troubleshooting)
- [Authors](#authors)
- [License](#license)

## Overview

This is a collaborative implementation of a shell in C that allows users to interact with the command line, execute commands, and manage processes. The shell supports built-in commands and external program execution with path handling similar to the standard Unix shell.

## Features

- **Command Execution:** Execute external programs by entering their names.
- **Path Resolution:** Find and execute commands in PATH directories.
- **Built-in Commands:** Support for built-in commands such as `cd`, `help`, `exit`, `env`, `setenv`, and `unsetenv`.
- **Input/Output Redirection:** Basic support for input (`<`) and output (`>`) redirection.
- **Process Management:** Creation and management of child processes using `fork()` and `exec()` system calls.
- **Environment Variables:** Handling of environment variables and their impact on shell behavior.
- **Error Handling:** Proper error handling for memory allocation, system calls, and other potential issues.
- **Signal Handling:** Handle signals such as SIGINT (Ctrl+C) gracefully.
- **Custom getline Implementation:** Non-blocking line reading implementation.

## Project Architecture

The project follows a modular design with clear separation of concerns:

- **Main Process:** Entry point that initializes the shell and manages the command loop
- **Input Processing:** Custom getline implementation and tokenization of input
- **Command Parsing:** Analyzing and categorizing input as builtins, paths, or directories
- **Execution:** Process spawning and environment management
- **Built-ins:** Internal commands implementation
- **Helpers:** String manipulation, memory management, and other utility functions

For detailed architecture information, see [ARCHITECTURE.md](ARCHITECTURE.md).

## How to Use

1. **Compilation:** Compile the shell source code using a C compiler.
   ```
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

2. **Running the Shell:** Run the compiled executable.
   ```
   ./hsh
   ```

3. **Interactive Mode:**
   ```
   $ ./hsh
   ==> ls -l
   ==> pwd
   ==> exit
   ```

4. **Non-Interactive Mode:**
   ```
   $ echo "ls -l" | ./hsh
   ```

## Built-in Commands

- **cd [DIRECTORY]** - Change the current directory
  ```
  ==> cd /usr/local
  ==> cd ..
  ==> cd ~
  ==> cd -
  ```

- **exit [STATUS]** - Exit the shell with optional status code
  ```
  ==> exit
  ==> exit 98
  ```

- **env** - Display the environment variables
  ```
  ==> env
  ```

- **setenv VARIABLE VALUE** - Set an environment variable
  ```
  ==> setenv NAME value
  ```

- **unsetenv VARIABLE** - Unset an environment variable
  ```
  ==> unsetenv NAME
  ```

- **help [COMMAND]** - Display help for built-in commands
  ```
  ==> help
  ==> help cd
  ==> help exit
  ```

## Implementation Details

- **Command Handling:** The shell uses the parser to categorize input as built-in commands, paths, or external programs.
- **Path Resolution:** Commands are searched in directories listed in the PATH environment variable.
- **Process Creation:** Child processes are created using `fork()` to execute external commands.
- **Environment Management:** Environment variables are stored and manipulated in the shell.
- **Error Handling:** Detailed error messages are provided for various error scenarios.
- **Memory Management:** All allocated memory is properly tracked and freed to prevent leaks.

For a detailed mapping of skills demonstrated in this project, see [SKILLS-INDEX.md](SKILLS-INDEX.md).

## Examples

1. **External Command Execution**
   ```
   ==> ls -l
   total 100
   -rw-r--r-- 1 user user  2345 Sep 15 12:34 main.c
   -rw-r--r-- 1 user user  1234 Sep 15 12:34 parser.c
   -rw-r--r-- 1 user user  3456 Sep 15 12:34 execute.c
   ...
   ```

2. **Change Directory**
   ```
   ==> cd /tmp
   ==> pwd
   /tmp
   ```

3. **Error Handling**
   ```
   ==> nonexistentcommand
   ./hsh: 1: nonexistentcommand: not found
   ==> cd /nonexistentdirectory
   ./hsh: 2: cd: can't cd to /nonexistentdirectory: No such file or directory
   ```

4. **Environment Variables**
   ```
   ==> setenv TEST_VAR example_value
   ==> env | grep TEST_VAR
   TEST_VAR=example_value
   ```

## Troubleshooting

### Common Issues

1. **Command Not Found**
   - Ensure the command exists in one of the PATH directories
   - Check for typos in the command name

2. **Permission Denied**
   - Verify execute permissions on the file you're trying to run
   - Run `chmod +x filename` to add execute permission

3. **Memory Issues**
   - If you encounter "Out of memory" errors, try breaking up complex commands

4. **Signal Handling**
   - Ctrl+C will display a new prompt rather than terminating the shell
   - To exit the shell, use the `exit` command

## Authors
See the list of [contributors](./AUTHORS) who participated in this project.

## License
This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](./LICENSE.txt) file for details.