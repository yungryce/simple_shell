# Skills Demonstrated in Simple Shell Project

This document maps specific skills demonstrated in the Simple Shell project to code components and features.

## Systems Programming

### Process Management
- **Process Creation**: [`main.c:execute`](main.c) - Fork and execute processes
- **Process Control**: [`main.c`](main.c) - Wait for child processes to complete
- **Signal Handling**: [`main.c:handle_SIGINT`](main.c) - Handle interrupt signals

### Memory Management
- **Dynamic Allocation**: [`lists.c`](lists.c) - Memory allocation for shell structures
- **Resource Cleanup**: [`main.c:clean_up`](main.c) - Free allocated memory
- **Buffer Management**: [`_getline.c`](_getline.c) - Manage input buffers

### System Calls
- **File Operations**: [`path_parse.c`](path_parse.c) - File access and permissions
- **Directory Operations**: [`parser.c`](parser.c) - Directory handling
- **Process Control**: [`main.c:execute`](main.c) - Fork, exec, and wait calls

## Command Interpretation

### Input Processing
- **Line Reading**: [`main.c:readline`](main.c) - Read command lines
- **Tokenization**: [`main.c:tokenizer`](main.c) - Split input into tokens
- **Command Parsing**: [`parser.c`](parser.c) - Parse and interpret commands

### Command Execution
- **Builtin Commands**: [`builtin_help1.c`](builtin_help1.c), [`builtin_help2.c`](builtin_help2.c) - Implement shell builtins
- **External Commands**: [`main.c:execute`](main.c) - Execute external programs
- **Path Resolution**: [`path_parse.c`](path_parse.c) - Resolve command paths

### Environment Handling
- **Environment Variables**: [`env_handlers.c`](env_handlers.c) - Manage environment
- **Working Directory**: Commands for changing and tracking working directory
- **Shell State**: Maintain shell state across command invocations

## Error Handling

### Error Detection
- **Command Validation**: [`parser.c`](parser.c) - Validate command syntax
- **Path Checking**: [`path_parse.c`](path_parse.c) - Verify command existence
- **Permission Checking**: [`main.c:execute`](main.c) - Check execution permissions

### Error Reporting
- **Error Messages**: [`error.c`](error.c) - Generate appropriate error messages
- **Status Codes**: Return appropriate exit status codes
- **Diagnostics**: Display diagnostic information for debugging

## Data Structures

### Linked Lists
- **List Creation**: [`lists.c`](lists.c) - Create and initialize lists
- **List Manipulation**: [`list_handler.c`](list_handler.c) - Add, remove, and traverse list nodes
- **Memory Management**: [`lists.c`](lists.c) - Allocate and free list structures

### Command Structure
- **Command Info**: Maintain command state and arguments
- **Argument Vector**: Handle command arguments
- **Environment Array**: Manage environment variable array

## String Manipulation

### Custom String Functions
- **String Comparison**: Custom implementations of string comparison functions
- **String Copying**: Functions for string duplication and copying
- **String Parsing**: Custom tokenization and parsing functions

### Standard Library Replacements
- **Custom printf**: Implementation of standard output formatting
- **Custom getline**: Custom implementation of the getline function
- **Memory Functions**: Custom malloc, realloc, and free wrappers

## Shell Features

### Input/Output Redirection
- **Output Redirection**: Redirect command output to files
- **Input Redirection**: Read command input from files
- **Stream Management**: Handle different input/output streams

### Command Chaining
- **Command Separation**: Handle multiple commands on a single line
- **Exit Status Checking**: Check command success for conditional execution
- **Pipeline Support**: Basic implementation of command pipelines

## Testing and Debugging

### Error Simulation
- **Edge Case Handling**: Test with malformed inputs
- **Resource Limitations**: Handle resource exhaustion scenarios
- **Error Injection**: Test error handling paths

### Runtime Diagnostics
- **Status Reporting**: Report command execution status
- **Error Reporting**: Clear error messages for troubleshooting
- **Debug Information**: Optional debug output for development
