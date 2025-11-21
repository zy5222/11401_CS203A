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

**Solution:**
 The compiler failed to handle the temporary path with Chinese characters. I fixed this by redirecting the temporary directory to a simple ASCII path (C:\tmp).

**Steps taken in Terminal:**
1.Create a temp folder: mkdir C:\tmp
2.Set environment variables before compiling:
$env:TMP = "C:\tmp"
$env:TEMP = "C:\tmp"
3. Manual Compilation
To ensure the correct compiler was used, I used the absolute path for compilation:
& "C:\msys64\ucrt64\bin\gcc.exe" C/main.c C/hash_fn.c -o hash_function
& "C:\msys64\ucrt64\bin\g++.exe" CXX/main.cpp CXX/hash_fn.cpp -o hash_function_cpp
