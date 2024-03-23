![ProjectLogo](/logo-&-screenshots/Minesweeperfield_generator.png)

## Overview

Simple c program that creates the field for the minesweeper game.

## Contents

- [How it works](#How-it-works)
- [Screenshots](#Screenshots)
- [How to install](#How-to-install)
- [How to compile and run](How-to-compile-and-run)
- [License](#License)


## How it works

User gives rows , cols and number of mines and the program generates the field and outputs in terminal and as a file.

## Screenshots

Here are some screenshots of the program in action:

![screenshot-1](/logo-&-screenshots/Screenshot_1.png)


## How to install

1. **Clone the repository to your local machine:**
  ```bash
    git clone https://github.com/marioskam3/minesweeper-field-generator
  ```

2. **Navigate to the project directory:**
  ```bash
    cd minesweeper-field-generator
  ```

## How to compile and run

1. **You will need a c compiler:**

    -I am using gcc.
    -Download gcc with:
  ```bash
    sudo apt install gcc
  ```

2. **Compile program:**
  ```bash
    gcc -o minesweeper-field-gen minesweeper-field-gen.c
  ```

3. **Run program:**
  ```bash
    ./minesweeper-field-gen
  ```
## License

This project is licensed under the MIT License
