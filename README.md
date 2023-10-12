# Simple Shell Implementation

This is a collaborative implementation of a shell in C that allows users to interact with the command line, execute commands, and manage processes. The shell supports some built-in commands and external program execution.

## Contributors

- [Chigbu Joshua](https://github.com/yungryce)
- [Jeremiah Adetunji](https://github.com/Jerryseun)

## Features

- **Command Execution:** Execute external programs by entering their names.
- **Built-in Commands:** Support for built-in commands such as `cd`, `help`, and `exit`.
- **Input/Output Redirection:** Basic support for input (`<`) and output (`>`) redirection.
- **Process Management:** Creation and management of child processes using `fork()` and `exec()` system calls.
- **Environment Variables:** Basic handling of environment variables and their impact on shell behavior.
- **Error Handling:** Proper error handling for memory allocation, system calls, and other potential issues.

## How to Use

1. **Compilation:** Compile the shell source code using a C compiler (e.g., GCC).
   ```
   gcc -o shell shell.c
   ```

2. **Running the Shell:** Run the compiled executable.
   ```
   ./shell
   ```

3. **Interacting with the Shell:**
   - Enter commands just like you would in a regular terminal.
   - Supported built-in commands: `cd`, `help`, `exit`.
   - Example usage:
     ```
     $ ls -l                # Execute an external program (ls)
     $ cd /path/to/directory # Change directory
     $ help                 # Display help information
     $ exit                 # Exit the shell
     ```

4. **Input/Output Redirection:** You can use basic input and output redirection.
   ```
   $ ls -l > output.txt    # Redirect output to a file
   $ cat < input.txt       # Redirect input from a file
   ```

## Implementation Details

- The shell uses `fork()` to create child processes for executing commands.
- Built-in commands are implemented using custom functions.
- Memory management is handled using `malloc()` and `free()`.
- Basic input processing is performed using functions like `fgets()` and `strtok()`.
- The shell maintains a simple environment variable mechanism.

## Acknowledgments

- We would like to acknowledge our fellow contributors and the open-source community for their valuable insights and contributions to this project.

## Note

This is a basic shell implementation meant for educational purposes. It may not cover all edge cases, and there might be potential areas for improvement and optimization.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For questions or feedback, please contact us at [chigbujoshua@yahoo.com](mailto:chigbujoshua@yahoo.com) and  [email@example.com](mailto:email@example.com).

---

