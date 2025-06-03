# 🔗 Pipex – 42 Project

Recreating the UNIX pipe system to better understand process creation, input/output redirection, and file descriptors in C.

---

## 📌 Description

**Pipex** is a 42 project focused on reproducing the shell behavior of piping commands.  
The goal is to execute a series of commands connected via UNIX pipes (e.g. `< infile cmd1 | cmd2 > outfile`), managing multiple processes and file descriptors manually.

---

## 🛠️ Features

- Execute two or more shell commands linked by a pipe
- Handle input from a file (`infile`) and redirect output to another (`outfile`)
- Manage child processes using `fork()`, `execve()`, `pipe()`, and `waitpid()`
- Support for:
  - Absolute or relative command paths
  - Environment variable `$PATH` parsing
  - Error handling for file access, commands, or permissions

---

## 📂 Project Structure

pipex/
├── src/ # Source files
│ ├── pipex.c
│ ├── exec.c
│ ├── path_utils.c
│ └── ...
├── include/ # Header files
│ └── pipex.h
├── Makefile
└── README.md

yaml
Copier
Modifier

---

## 🔧 Build

```bash
make        # Compiles the project
make clean  # Removes object files
make fclean # Cleans everything
make re     # Full rebuild
## 🧪 Usage
Basic usage (2 commands):
bash
Copier
Modifier
./pipex infile "cmd1" "cmd2" outfile
Is equivalent to:

bash
Copier
Modifier
< infile cmd1 | cmd2 > outfile
Example:
bash
Copier
Modifier
./pipex input.txt "grep error" "wc -l" output.txt
## 🧠 What I Learned
Process creation with fork()

File descriptor manipulation and redirection

Piping data between commands

Parsing and executing commands with execve()

Handling environment variables and $PATH

## 👨‍💻 Author
**Mehdi Adel Achouba**  
**42 Paris – Login: machouba**