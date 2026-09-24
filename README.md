# 42 Piscine — Piscine #4, 42 Penang (August 2026)

This repository contains my personal solutions for the 42 C Piscine at **42 Penang** (Piscine #4, August 2026). It covers the Shell, C, Rush, and exam exercises completed during the piscine.

**Level achieved:** `11.00`

> Extra exercises and exam preparation: [42PiscineExtra](https://github.com/Evan-Lim/42PiscineExtra)  
> *(repository not sufficiently maintained)*

---

## Repository Overview

The repository is organised by module. Each module directory contains the exercises required by the corresponding 42 subject.

- `Shell00/`, `Shell01/`
- `C00/` through `C13/`
- `Rush00/`, `Rush01/`
- Exam-related work and notes are tracked separately where applicable.

Unless otherwise stated, C projects are written in accordance with the **42 Norm** and compile with `cc -Wall -Wextra -Werror`. Shell exercises are executable with `/bin/sh`.

---

## Progress

| Module | Status | Score | Notes |
|---|---:|---:|---|
| Shell00 | Completed | 100% | |
| Shell01 | Completed | 92% | |
| C00 | Completed | 100% | |
| C01 | Completed | 100% | |
| C02 | Completed | 100% | |
| C03 | Completed | 100% | |
| C04 | Completed | 100% | |
| C05 | Completed | 100% | |
| C06 | Completed | 100% | |
| C07 | Completed | 100% | |
| C08 | Completed | 100% | |
| C09 | Completed | 100% | |
| C10 | Partial | 15% | File I/O and system calls |
| C11 | Completed | 100% | |
| C12 | Ungraded | — | Linked lists |
| C13 | Ungraded | — | Binary trees |
| Exam00 | Completed | 80% | |
| Exam01 | Completed | 100% | |
| Exam02 | Completed | 90% | |
| Final Exam | Completed | 72% | |
| Rush00 | Completed | 108% | Team project |
| Rush01 | Completed | 125% | Team project |
| Rush02 | Unreleased | — | Not released by bocal |
| BSQ | Unreleased | — | Not released by bocal |

---

## Module Descriptions

### Shell00

Focus: shell basics, file permissions, archives, Git, SSH, and magic files. Covers essential shell commands and concepts including file manipulation, permissions, tar archives, SSH keys, Git commit inspection, gitignore, diff/patch, file cleanup, and custom magic file creation.

### Shell01

Focus: environment variables, pipes, filters, text processing, and custom base arithmetic. Covers environment variables, text filtering and processing with pipes, finding files, counting files, MAC address retrieval, complex file naming, line skipping, passwd processing, and custom base addition.

### C00

Focus: basic C syntax, `write`, loops, and combinatorial output.

### C01

Focus: pointers, addresses, arrays, and basic memory manipulation.

### C02

Focus: string copying, validation, case conversion, and memory display.

### C03

Focus: reimplementation of standard string comparison and concatenation functions.

### C04

Focus: string length, output, number conversion, and base conversion.

### C05

Focus: recursion, mathematics, prime numbers, and the Ten Queens puzzle.

### C06

Focus: command-line arguments (`argc`, `argv`).

### C07

Focus: dynamic memory allocation, ranges, string joining, base conversion, and splitting.

### C08

Focus: header files, macros, structs, and tab display.

### C09

Focus: static library creation, Makefile, and string splitting.

### C10

Focus: file descriptors, system calls, and Makefile-based programs.

Status: partial completion (15%).

### C11

Focus: function pointers, array iteration, sorting, and `do-op`.

### C12

Focus: singly linked lists.

Status: ungraded.

### C13

Focus: binary trees.

Status: ungraded.

---

## Rushes

### Rush00

Team project: display rectangles using `ft_putchar` and a `rush` function.

- Files: `main.c`, `ft_putchar.c`, `rush0X.c`
- The assigned version depends on the team leader’s login modulo 5.
- Score: **108%**

### Rush01

Team project: solve a 4x4 Skyscraper puzzle.

- Program name: `rush01`
- Input: 16 view values as a single string.
- Output: first valid 4x4 grid or `Error`.
- Score: **125%**

---

## Exam Questions

### Exam00 — 80%

`only_z`, `ft_print_numbers`, `maff_revalpha`, `ft_inc`, `ft_putstr`, `print_interval`, `count_alen`, `ft_strcpy`, `ft_strcmp`, `???` *(probably `ft_atoi`)*

### Exam01 — 100%

`aff_e`, `ft_add`, `maff_alpha`, `occ_z`, `buzzfizz`, `ft_strrev`, `ft_atoi`, `ft_last_param`, `title`, `count_words`

### Exam02 — 90%

`aff_k`, `maff_alpha`, `first_word`, `ft_strlen`, `ft_putnbr`, `aff_last_param`, `inter`, `count_words`, `ft_rrange`, `ft_split`

### Final Exam — 72%

`aff_a`, `interval_space`, `ft_strcmp`, `count_len`, `ft_atoi`, `first_word`, `ft_putnbr`, `aff_first_param`, `inter`, `count_words`, `ft_rrange`, `ft_split`, `sort_list`

---

## Notes

- All C code follows the 42 Norm where applicable.
- Moulinette-style compilation uses `cc -Wall -Wextra -Werror`.
- Some modules were ungraded or unreleased during the piscine.
- This repository is intended as a record of my piscine work and as a reference for future students.

---

## Acknowledgements

Thanks to 42 Penang, the piscine staff, and all peers who contributed through peer-learning and evaluations.
