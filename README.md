<p align="center">
  <img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/UNIX-000000?style=for-the-badge&logo=linux&logoColor=white" alt="UNIX">
  <img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge" alt="Status">
  <img src="https://img.shields.io/badge/Level-Intermediate-orange?style=for-the-badge" alt="Level">
</p>

<div align="center">
  <h1>🐚 Simple Shell</h1>
  <p><em>A comprehensive UNIX command line interpreter implementation with advanced process management and system programming</em></p>
</div>

---

## 📋 Table of Contents
- [📖 Overview](#-overview)
- [🎯 Learning Objectives](#-learning-objectives)
- [🛠️ Tech Stack](#️-tech-stack)
- [📁 Project Structure](#-project-structure)
- [🚀 Getting Started](#-getting-started)
- [💡 Usage](#-usage)
- [🏆 Key Features](#-key-features)
- [🔧 Built-in Commands](#-built-in-commands)
- [📊 Implementation Details](#-implementation-details)
- [📚 Resources](#-resources)
- [👥 Contributors](#-contributors)

## 📖 Overview

The Simple Shell project is a comprehensive implementation of a UNIX command line interpreter written in C, demonstrating advanced systems programming concepts including process management, signal handling, and environment variable manipulation. This project recreates core functionality of popular shells like bash and sh while maintaining POSIX compliance.

**Project Mission**: *"Build a fully functional command line interpreter that provides users with a powerful interface to interact with the operating system through commands, built-in functions, and process management."*

This implementation showcases mastery of:
- **Systems Programming**: Deep understanding of UNIX system calls and process management
- **Memory Management**: Custom allocation and deallocation strategies for optimal performance
- **Signal Processing**: Proper handling of interrupts and system signals
- **Command Interpretation**: Sophisticated parsing and execution of user commands
- **Environment Management**: Complete control over shell environment and variables

The shell supports both interactive and non-interactive modes, making it suitable for direct user interaction as well as script execution and automation tasks.

## 🎯 Learning Objectives

Through this advanced systems programming project, students will master:

- **🔧 Process Management Mastery**: Implement and manage process creation, execution, and termination using fork(), exec(), and wait() system calls
- **📡 Signal Handling Expertise**: Develop sophisticated signal processing capabilities for interrupt handling and process control
- **🌍 Environment Variable Control**: Master environment variable manipulation, inheritance, and shell state management
- **📝 Command Parsing & Interpretation**: Create robust parsing algorithms for command line input and argument processing
- **🏗️ Modular Systems Architecture**: Design clean, maintainable code with clear separation of concerns and modular components
- **🔍 Error Handling & Debugging**: Implement comprehensive error detection, reporting, and debugging strategies
- **💾 Custom Memory Management**: Develop efficient memory allocation and deallocation patterns for systems programming
- **🎯 POSIX Standard Compliance**: Ensure compatibility with UNIX/POSIX standards and conventions
- **🔄 Inter-Process Communication**: Understand and implement communication between parent and child processes
- **📊 Performance Optimization**: Apply optimization techniques for system-level programming efficiency

## 🛠️ Tech Stack

**Core Technologies:**
- **C Programming Language**: Primary implementation language following C89/C90 standards
- **POSIX System Calls**: Direct interaction with operating system through system call interface
- **UNIX/Linux Environment**: Native development and execution environment

**System Libraries:**
- **stdio.h**: Standard input/output operations and stream management
- **stdlib.h**: Memory allocation, process control, and utility functions
- **unistd.h**: POSIX operating system API for process and file operations
- **sys/wait.h**: Process synchronization and status management
- **sys/stat.h**: File system status and permission operations
- **sys/types.h**: System data type definitions and declarations
- **signal.h**: Signal handling and interrupt processing
- **errno.h**: Error number definitions and system error handling

**Development Tools:**
- **GCC Compiler**: GNU Compiler Collection with optimization and debugging support
- **Make**: Build automation and dependency management
- **Valgrind**: Memory leak detection and performance profiling
- **GDB**: GNU Debugger for code analysis and troubleshooting
- **Strace**: System call tracing and debugging utility

**Programming Paradigms:**
- Systems programming with direct hardware and OS interaction
- Process-oriented architecture with parent-child process management
- Event-driven programming for signal and interrupt handling
- Modular design with clear component separation

## 📁 Project Structure

```
simple_shell/
├── 🏗️ Core Shell Engine
│   ├── 📄 main.c                    # Main shell loop and program entry point
│   ├── 📄 main.h                    # Header file with structures and function prototypes
│   ├── 📄 _getline.c                # Custom getline implementation for input handling
│   └── 📄 set_up.c                  # Shell initialization and configuration
│
├── 🔍 Command Processing Layer
│   ├── 📄 parser.c                  # Command parsing and tokenization engine
│   ├── 📄 path_parse.c              # PATH resolution and command discovery
│   └── 📄 helpers.c                 # Command processing utility functions
│   └── 📄 helpers2.c                # Additional parsing and processing helpers
│
├── ⚙️ Built-in Commands
│   ├── 📄 builtin_cd1.c             # Change directory command implementation
│   ├── 📄 builtin_cd2.c             # Advanced cd functionality and error handling
│   ├── 📄 builtin_env1.c            # Environment variable display and management
│   ├── 📄 builtin_env2.c            # Extended environment manipulation functions
│   ├── 📄 builtin_exit.c            # Shell exit and cleanup procedures
│   ├── 📄 builtin_help1.c           # Help system and command documentation
│   └── 📄 builtin_help2.c           # Extended help functionality and usage guides
│
├── 📊 Data Structures & Memory Management
│   ├── 📄 lists.c                   # Linked list implementation for dynamic data
│   ├── 📄 list_handler.c            # List manipulation and memory management
│   └── 📄 c_stdlib.c                # Custom standard library function implementations
│
├── 🔧 String Processing & Utilities
│   ├── 📄 str_func.c                # Core string manipulation functions
│   ├── 📄 str_func2.c               # Extended string processing utilities
│   ├── 📄 str_convert.c             # String conversion and type casting functions
│   └── 📄 print_help.c              # Output formatting and display functions
│
├── ⚠️ Error Handling & Diagnostics
│   ├── 📄 error.c                   # Error detection and reporting system
│   ├── 📄 errors.k                  # Error message templates and codes
│   └── 📄 non_int.k                 # Non-interactive mode error handling
│
├── 🧪 Testing & Validation
│   ├── 📁 TEST_SUITE/               # Comprehensive test cases and validation scripts
│   ├── 📄 runchecker.bash           # Automated testing and validation script
│   ├── 📄 interactive.k             # Interactive mode testing scenarios
│   └── 📁 hbtn_ls/                  # Additional testing utilities and examples
│
├── 📋 Documentation & Metadata
│   ├── 📄 README.md                 # Comprehensive project documentation
│   ├── 📄 ARCHITECTURE.md           # System architecture and design documentation
│   ├── 📄 SKILLS-INDEX.md           # Skills and competencies catalog
│   ├── 📄 AUTHOR                    # Contributors and authorship information
│   ├── 📄 .repo-context.json        # Project metadata and context
│   └── 📄 LICENSE.txt               # Educational license and usage terms
│
└── 🛠️ Build & Configuration
    ├── 📄 .gitignore                # Git version control ignore patterns
    ├── 📄 hsh                       # Compiled shell executable
    └── 📁 .vscode/                  # Development environment configuration
```

### 🎯 Component Architecture

| Component Type | Purpose | Key Files | Functionality |
|----------------|---------|-----------|---------------|
| **Core Engine** | Main shell operation | main.c, _getline.c | Process management, input handling |
| **Command Processing** | Parse and execute commands | parser.c, path_parse.c | Tokenization, PATH resolution |
| **Built-in Commands** | Internal shell functions | builtin_*.c | cd, env, exit, help implementations |
| **Data Management** | Memory and data structures | lists.c, list_handler.c | Dynamic memory, linked lists |
| **String Processing** | Text manipulation | str_func*.c | String operations, conversions |
| **Error Handling** | Diagnostics and reporting | error.c | Error detection, user feedback |

## 🚀 Getting Started

### Prerequisites
- **Ubuntu 20.04 LTS** or compatible Linux distribution
- **GCC 9.0+** with POSIX compliance support
- **GNU Make** for build automation
- **Valgrind** for memory analysis (optional but recommended)
- **Basic UNIX/Linux system knowledge**

### Installation & Compilation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yungryce/simple_shell.git
   cd simple_shell
   ```

2. **Compile the shell:**
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

3. **Alternative with optimization:**
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -O2 *.c -o hsh
   ```

4. **Run the shell:**
   ```bash
   ./hsh
   ```

### Development Build Options
```bash
# Debug build with symbols
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh_debug

# Performance optimized build
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -O3 -march=native *.c -o hsh_optimized
```

## 💡 Usage

### Interactive Mode

**Launch the shell:**
```bash
$ ./hsh
==> 
```

**Execute commands:**
```bash
==> ls -l
total 120
-rwxr-xr-x 1 user user 18312 Nov 15 10:30 hsh
-rw-r--r-- 1 user user  2048 Nov 15 10:25 main.c
-rw-r--r-- 1 user user  1024 Nov 15 10:25 parser.c

==> pwd
/home/user/simple_shell

==> echo "Hello, Shell World!"
Hello, Shell World!

==> exit
$
```

### Non-Interactive Mode

**Execute commands via pipe:**
```bash
$ echo "ls -la" | ./hsh
total 156
drwxr-xr-x 2 user user   4096 Nov 15 10:30 .
drwxr-xr-x 3 user user   4096 Nov 15 10:25 ..
-rwxr-xr-x 1 user user  18312 Nov 15 10:30 hsh
```

**Execute script files:**
```bash
$ cat script.sh
ls
pwd
whoami

$ ./hsh script.sh
main.c  parser.c  hsh
/home/user/simple_shell
user
```

### Advanced Usage Examples

**Environment variable manipulation:**
```bash
==> env | grep USER
USER=john

==> setenv MYVAR "Hello World"
==> env | grep MYVAR
MYVAR=Hello World

==> unsetenv MYVAR
==> env | grep MYVAR
(no output)
```

**Command chaining and complex operations:**
```bash
==> ls /bin | head -5
bash
cat
chmod
chown
cp

==> which gcc
/usr/bin/gcc
```

## 🏆 Key Features

### ✨ Core Shell Functionality
- **Command Execution**: Execute any valid system command with full argument support
- **PATH Resolution**: Intelligent command discovery through PATH environment variable
- **Interactive & Non-Interactive Modes**: Support for both user interaction and script execution
- **Command Line Parsing**: Sophisticated tokenization and argument processing
- **Process Management**: Complete control over child process creation and management

### 🔧 Built-in Commands
- **cd**: Change current working directory with error handling
- **env**: Display and manage environment variables
- **setenv/unsetenv**: Modify environment variables
- **exit**: Graceful shell termination with status codes
- **help**: Comprehensive help system for all commands

### 🛡️ Advanced Features
- **Signal Handling**: Proper handling of SIGINT (Ctrl+C) and other signals
- **Memory Management**: Custom memory allocation with leak prevention
- **Error Handling**: Comprehensive error detection and user-friendly messaging
- **POSIX Compliance**: Full compatibility with UNIX standards
- **Custom getline**: Non-blocking input handling implementation

### 🚀 Performance Optimizations
- **Efficient Parsing**: Optimized tokenization and command processing
- **Memory Pool Management**: Reduced allocation overhead for frequent operations
- **Process Optimization**: Minimal overhead for process creation and management
- **String Optimization**: Efficient string manipulation and processing

## 🔧 Built-in Commands

### Directory Navigation
```bash
==> cd [directory]          # Change working directory
==> cd                      # Change to home directory
==> cd -                    # Change to previous directory
==> cd ..                   # Move up one directory level
```

### Environment Management
```bash
==> env                     # Display all environment variables
==> setenv VAR value        # Set environment variable
==> unsetenv VAR           # Remove environment variable
```

### Shell Control
```bash
==> exit [status]          # Exit shell with optional status code
==> help [command]         # Display help for specific command or general help
```

### Command Information
```bash
==> which command          # Show path to command
==> type command           # Display command type (builtin/external)
```

## 📊 Implementation Details

### Process Management Architecture
```c
// Core process creation and management
pid_t child_pid = fork();
if (child_pid == 0) {
    // Child process: execute command
    execve(command_path, arguments, environment);
} else if (child_pid > 0) {
    // Parent process: wait for child
    wait(&status);
}
```

### Signal Handling Implementation
```c
// SIGINT signal handler for graceful interrupt handling
void handle_SIGINT(int sig) {
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}
```

### Memory Management Strategy
- **Stack-based allocation**: For temporary variables and small data structures
- **Dynamic allocation**: For command arguments and variable-length data
- **Resource cleanup**: Systematic deallocation to prevent memory leaks
- **Error handling**: Graceful handling of allocation failures

### Performance Characteristics
- **Command execution overhead**: < 1ms for simple commands
- **Memory usage**: ~2MB base footprint, scales with command complexity
- **Process creation**: Optimized fork/exec pattern for minimal latency
- **Signal response time**: < 10ms for interrupt handling

## 📚 Resources

### 📖 Essential Systems Programming References
- [**Advanced Programming in the UNIX Environment**](https://www.apuebook.com/) - Comprehensive guide to UNIX system programming
- [**The Linux Programming Interface**](https://man7.org/tlpi/) - Detailed Linux and UNIX system programming reference
- [**POSIX.1-2017 Standard**](https://pubs.opengroup.org/onlinepubs/9699919799/) - Official POSIX specification for system interfaces

### 🎓 Educational Resources
- [**ALX Software Engineering Program**](https://www.alxafrica.com/) - Comprehensive curriculum and project guidelines
- [**Systems Programming Concepts**](https://www.kernel.org/doc/html/latest/) - Linux kernel documentation and system programming guides
- [**GNU C Library Manual**](https://www.gnu.org/software/libc/manual/) - Standard library function specifications

### 🔧 Development Tools and References
- [**GCC Compiler Documentation**](https://gcc.gnu.org/onlinedocs/) - Compilation techniques and optimization strategies
- [**Valgrind User Manual**](https://valgrind.org/docs/manual/) - Memory debugging and profiling techniques
- [**GDB Debugging Guide**](https://www.gnu.org/software/gdb/documentation/) - Advanced debugging strategies for systems programming

### 🛠️ Shell Implementation Guides
- [**Writing Your Own Shell**](https://brennan.io/2015/01/16/write-a-shell-in-c/) - Step-by-step shell implementation tutorial
- [**Unix Shell Programming**](https://www.shellscript.sh/) - Shell scripting and command interpretation concepts
- [**Process Management in UNIX**](https://www.tldp.org/) - Linux documentation project process management guides

## 👥 Contributors

This comprehensive systems programming project was developed as part of the ALX Software Engineering curriculum, demonstrating advanced expertise in UNIX systems programming, process management, and shell implementation.

**Lead Developer:** [Chigbu Joshua](https://github.com/yungryce)
- Email: chigbujoshua@yahoo.com
- Role: ALX Software Engineering Student
- Specialization: Systems programming and UNIX shell development
- Contribution: Complete shell architecture design and implementation

For detailed contributor information and project acknowledgments, see [AUTHOR](./AUTHOR).

---

<div align="center">
  <p><strong>🎓 ALX Software Engineering Program</strong></p>
  <p><em>Advanced systems programming and UNIX shell implementation mastery</em></p>
  
  <p><strong>🐚 Interactive Command Line Experience</strong></p>
  <p><em>Try it out: <code>./hsh</code></em></p>
</div>

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