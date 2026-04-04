# Simple C++ Spell Corrector

This project is a beginner-friendly C++ application that works like an auto-correction system. You enter a word, and if the word is misspelled (not found in the loaded dictionary), the program will identify the closest correctly spelled word and suggest it. 

## How it Works

The spell corrector utilizes two main concepts: a **Dictionary** and **Edit Distance**.

### 1. The Dictionary (`dictionary.cpp`)
The program reads a large list of words directly from a file called `words.csv`. Because the CSV file contains hundreds of thousands of words formatted with quotation marks (e.g. `"apple"`), the program:
- Strips out the extra quotation marks and empty lines.
- Saves the parsed words inside a `static vector<string> dict`.
- Uses caching (the `static` keyword) to ensure it only reads the dictionary file the *first* time you try to spellcheck a word, preventing massive slow-downs on subsequent checks.

### 2. Levenshtein Edit Distance (`edit_distance.cpp`)
When you type a word that isn't in the dictionary, the program needs to figure out which word is "closest" to what you typed. It does this by scoring how many single-character edits it takes to turn your input into a dictionary word.

An edit can be:
- **Insertion**: Adding a letter (e.g., *aple* $\to$ *ap**p**le*)
- **Deletion**: Removing a letter (e.g., *appple* $\to$ *apple*)
- **Substitution**: Changing a letter (e.g., *applz* $\to$ *appl**e***)

The program loops through the `words.csv` dictionary, calculates the edit distance between your input and every single word, and proposes the word with the lowest score as the suggestion!

## File Structure

- **`main.cpp`**: The primary entry point. It handles asking the user for a word, interacting with the dictionary checking functions, and printing out the final correction and edit distance explanation.
- **`dictionary.cpp`**: Contains the logic to load `words.csv`, clear out formatting fluff, and search through the resulting list for matches and closest words.
- **`edit_distance.cpp`**: Contains the algorithm (Dynamic Programming) used to calculate the edit distance mathematically between two strings. 
- **`Makefile`**: A set of compilation instructions that automatically bundle your `.cpp` source files together into a runnable `.exe` file without needing complex commands.

## How to Build and Run

If you have your compiler (`g++` and `make`) active on your terminal's `PATH`:

1. Open your terminal in this folder.
2. Type `make` (or `mingw32-make` on MSYS2 Windows setups) to build the program.
3. Run it via `./corrector.exe`.
4. Type in your word when prompted! 

*(Alternatively, you can just import the three `.cpp` files into your favorite C++ IDE like Visual Studio, CodeBlocks, or CLion and hit the 'Run' button!)*
