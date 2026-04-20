# C++ Spell Corrector

A beginner-friendly spell checker written in C++. Enter a word, and the program will:

1. Check if the word exists in the dictionary.
2. If not, suggest the closest word using Levenshtein edit distance.

It is simple, readable, and a good mini project for learning strings, vectors, file I/O, and dynamic programming.

## What Algorithms Are Used?

### 1. Dictionary Lookup (Linear Search)
The dictionary is loaded from `words.csv` into a `vector<string>`.

- To check correctness, the program scans words one by one and compares with the input.
- This is a linear search, so the lookup cost is $O(D)$ where $D$ is dictionary size.

### 2. Levenshtein Edit Distance (Dynamic Programming)
For misspelled words, the program computes edit distance against dictionary words and picks the minimum.

- Insert, delete, and substitute each count as 1 operation.
- DP table size is $(m+1) \times (n+1)$ for words of lengths $m$ and $n$.
- Per comparison cost is $O(mn)$ time and $O(mn)$ memory.

### Overall Suggestion Cost
If dictionary size is $D$, and average word lengths are small, finding the closest suggestion is roughly:

$$
O\left(\sum_{i=1}^{D} m \cdot n_i\right) \approx O(D \cdot m \cdot \bar{n})
$$

This is fine for learning, but can be slow on very large dictionaries.

## Project Structure

- `main.cpp`
	- CLI loop.
	- Converts user input to lowercase.
	- Calls `isWordCorrect(...)` and `getClosestWord(...)`.

- `dictionary.cpp`
	- Loads and caches dictionary in a static vector (`getDictionary()`).
	- Cleans CSV lines:
		- removes trailing `\r` (Windows line endings)
		- strips surrounding quotes (`"word"` -> `word`)
		- lowercases words
	- Implements:
		- `bool isWordCorrect(string word)`
		- `string getClosestWord(string word, int& bestDistance)`

- `edit_distance.cpp`
	- Implements `calculateEditDistance(string s1, string s2)` using DP.

- `words.csv`
	- Source dictionary file.

- `Makefile`
	- Builds executable `corrector` from all `.cpp` files.

## Requirements

- C++ compiler with C++11 support (e.g., `g++`)
- `make` (or `mingw32-make` on many Windows setups)

## How to Build and Run

### Option A: Using Make

From the project folder:

#### Windows (PowerShell / CMD)
```bash
mingw32-make
./corrector.exe
```

If `make` is available instead of `mingw32-make`, use:
```bash
make
./corrector.exe
```

#### Linux / macOS
```bash
make
./corrector
```

### Option B: Compile Directly with g++

#### Windows
```bash
g++ -Wall -std=c++11 -o corrector.exe main.cpp dictionary.cpp edit_distance.cpp
./corrector.exe
```

#### Linux / macOS
```bash
g++ -Wall -std=c++11 -o corrector main.cpp dictionary.cpp edit_distance.cpp
./corrector
```

## Usage

1. Run the executable.
2. Type a word.
3. Read the result:
	 - Correct word -> confirmation message.
	 - Incorrect word -> closest suggestion + edit distance.
4. Type `exit` to quit.

Example:
```text
Type a word to spell-check (or type 'exit' to quit): appl
Oops! 'appl' is not in the dictionary.
Did you mean: 'apple'?
Explanation: 'apple' was chosen because it has an edit distance of 1 from your input.
```

## Notes and Limitations

- Input is normalized to lowercase in `main.cpp`.
- The dictionary is loaded once and cached, which improves repeated checks.
- Current search method is brute force over the full dictionary for suggestions.
- If `words.csv` is missing or empty, behavior is undefined (closest-word logic expects at least one dictionary word).

## Possible Improvements

- Use `unordered_set` for faster exact-word checks.
- Add length-based filtering before edit distance to reduce comparisons.
- Use BK-tree or trie-based approaches for faster nearest-word queries.
- Handle empty/missing dictionary with explicit error messages.
- Add unit tests for dictionary parsing and edit distance correctness.
