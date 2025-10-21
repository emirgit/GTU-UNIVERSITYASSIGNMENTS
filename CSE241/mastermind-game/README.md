# Mastermind Game

## Description
This project is an implementation of the classic Mastermind game in C++. The game involves one player (the program) holding a secret code, and the other player (the user) trying to guess it. The program provides hints after each guess, indicating how many digits are correct in both value and position, and how many are correct in value but in the wrong position.

### Game Rules:
- The secret code consists of N digits, where N is between 1 and 15.
- Digits can be any character from `0-9` and `a-e`.
- The first digit of the secret code cannot be `0`.
- All digits in the secret code must be unique.

### Program Functionality:
- The program can generate a random secret code of a specified length (`-r N`).
- Alternatively, the user can provide a secret code (`-u <secret_code>`).
- The user makes guesses, and the program responds with two counts:
    - **Cexact**: The number of digits in the guess that match the secret code in both value and position.
    - **Cmisplaced**: The number of digits in the guess that are present in the secret code but are in the wrong position.
- The game ends when the user guesses the secret code (Cexact = N) or after 100 iterations.

## How to Compile and Run

To compile the program, navigate to the `muhammed_emir_kara_PA1` directory and use the following command:

```bash
g++ -std=c++11 muhammed_emir_kara_PA1.cpp -o mastermind
```

To run the program, use one of the following formats:

### Random Secret Code Generation:
```bash
./mastermind -r <N>
```
Replace `<N>` with the desired number of digits for the secret code (e.g., `./mastermind -r 6`).

### User-Defined Secret Code:
```bash
./mastermind -u <secret_code>
```
Replace `<secret_code>` with your desired secret code (e.g., `./mastermind -u 12345`).

## Error Handling
The program includes error checking for various scenarios:
- **E0**: Missing, wrong, or undefined parameters in the command line arguments. Also, if the secret number provided with `-u` is invalid (e.g., non-unique digits, invalid characters, first digit is '0', or incorrect length).
- **E1**: User's guess has a different number of digits than the secret code.
- **E2**: User's guess contains invalid characters or non-unique digits.

## Example Usage

Assuming the program generated a secret code `130456` for `./mastermind -r 6`:

```
mastermind -r 6
12345a
3 1
13245a
5 0
130456
FOUND 3
```

If the user fails to guess the number within 100 iterations:

```
FAILED
```