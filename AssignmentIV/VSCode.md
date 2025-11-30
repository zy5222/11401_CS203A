# Connect to GitHub with VSCode

## Prerequisites
Before you begin, ensure you have the following:
- Visual Studio Code installed on your computer. [Download VS Code here](https://code.visualstudio.com/)
- Git installed and configured on your system. [Download Git here](https://git-scm.com/).
- A GitHub account.

## Steps to Connect to GitHub

1. **Install the GitHub Extension for VSCode**
    - Open VSCode.
    - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window.
    - Search for "GitHub Pull Requests and Issues" and install the extension.

2. **Sign in to GitHub**
    - Open the Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P` on macOS).
    - Type `GitHub: Sign in` and select the option.
    - Follow the prompts to authenticate with your GitHub account.

3. **Clone a Repository**
    - In VSCode, open the Command Palette.
    - Type `Git: Clone` and select the option.
    - Paste the URL of your GitHub repository when prompted.
    - Choose a local folder where the repository will be cloned.

4. **Open the Repository**
    - Once the repository is cloned, VSCode will prompt you to open it.
    - Click `Open` to start working on your project.

5. **Make Changes and Commit**
    - Edit files in the repository as needed.
    - Go to the Source Control view in VSCode.
    - Stage your changes, write a commit message, and commit the changes.

6. **Push Changes to GitHub**
    - After committing, click the `Sync Changes` button in the Source Control view.
    - This will push your changes to the GitHub repository.

## Additional Tips
- Use the built-in terminal in VSCode for advanced Git commands.
- Enable GitLens extension for enhanced Git insights.

By following these steps, you can easily connect and manage your GitHub repositories using Visual Studio Code.

## My Setup Experience & Troubleshooting

### 1. Compiler Environment Setup (MinGW)
I installed **MSYS2 (MinGW-w64)** to allow VS Code to compile C/C++ code.
- **Path Configuration**: I verified that `C:\msys64\ucrt64\bin` was added to the Windows System Environment Variables (**Path**) so that `make` and `gcc` commands could be recognized.

### 2. Issue with Chinese Username (Fatal Error)
**Problem:**
During compilation, I encountered the following error because my Windows username contains non-ASCII (Chinese) characters:
```text
Assembler messages:
Fatal error: can't create C:\Users\芷芸\...
```
**Solution:**
 The compiler failed to handle the temporary path with Chinese characters. I fixed this by redirecting the temporary directory to a simple ASCII path (`C:\tmp`).

**Steps taken in Terminal:**
  - Create a temp folder: `mkdir C:\tmp` 
  - Set environment variables before compiling:
```text
$env:TMP = "C:\tmp"
$env:TEMP = "C:\tmp"
```
### 3. Manual Compilation
To ensure the correct compiler was used, I used the absolute path for compilation:
```text
& "C:\msys64\ucrt64\bin\gcc.exe" C/main.c C/hash_fn.c -o hash_function
& "C:\msys64\ucrt64\bin\g++.exe" CXX/main.cpp CXX/hash_fn.cpp -o hash_function_cpp
```
## Assistive Tools
I utilized Artificial Intelligence (**Google Gemini**) to assist with the development of Assignment IV. The AI served as a technical assistant to overcome specific platform-related challenges and refine the project structure. 

Below is a summary of the assistance provided:
### 1.Environment Configuration & Troubleshooting
- Compiler Path Resolution: Diagnosed a `Fatal error: can't create C:\Users\芷芸\...` issue caused by Chinese characters in the Windows user path.
- Solution: Provided the PowerShell commands to redirect temporary directories (`$env:TMP`) to a safe path (`C:\tmp`), enabling successful compilation via MinGW.
### 2. Build Automation (Windows)
- **Custom Build Script**: Assisted in creating `Makefile.bat` to mimic GNU Make functionality on Windows.
- **Logic Fixes**: Corrected batch script logic (using `EXIT /B`) to ensure sequential compilation of both C and C++ targets.
- **Compatibility Adjustments**: Identified `unrecognized command line option` errors and advised downgrading compiler standards from `C23/C++23` to `C11/C++17` to match the installed MinGW version.
### 3. Code Implementation & Review
- **Hash Algorithms**: Verified the mathematical logic for the Division Method (`(key) % m`) and Polynomial Rolling Hash (using prime `P=31`).
- **Header Management**: Fixed linker errors caused by incorrect `#include` statements (changing `.c` includes to `.h`).
- **Edge Case Handling**: Suggested adding safety checks for `m <= 0` and empty strings.
### 4. Data Analysis & Documentation
- **Verification**: Verified that the experimental data (e.g.,` m=37 `indices starting at 21) aligned with the source code logic, ensuring the report reflected actual execution results rather than generic examples.
- **Collision Analysis**: Helped articulate the trade-offs between speed and collision resistance, and explained the mathematical significance of using prime numbers for table sizes.
### 5. Version Control
- **Git Workflow**: Guided the creation of a clean commit history (Initial -> Development -> Final) and resolved `non-fast-forward` push errors.
- **Cleanup**: Generated a `.gitignore` file to properly exclude build artifacts (`.exe`,` .o`) and IDE settings (`.vs/`).
