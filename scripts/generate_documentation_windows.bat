@echo off
wsl --list >nul 2>&1
if %errorlevel% neq 0 (
    echo WSL is not installed. Please install WSL to continue.
) else (
    wsl -e bash -c "cp ./generate_documentation_bash.sh ./temp_generate_documentation_bash.sh; dos2unix ./temp_generate_documentation_bash.sh; ./temp_generate_documentation_bash.sh; rm temp_generate_documentation_bash.sh;"
) 