#!/bin/bash
pushd ../

# Check if Doxyfile exists
if [ ! -f "Doxyfile" ]; then
    echo "Doxyfile not found! Please make sure you're in the correct directory."
    exit 1
fi

# Check if the docs folder exists
if [ ! -d "docs" ]; then
    echo "Docs folder not found. Running Doxygen normally."
    
    # Determine if running in WSL or Linux
    if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null; then
        # We're running in WSL (Windows Subsystem for Linux)
        echo "Running in Windows Subsystem for Linux (WSL)"
        
        # Path to the Windows Doxygen executable
        WIN_DOXYGEN_EXEC="./3rdparties/windows/doxygen/doxygen.exe"
        
        # Check if the Windows Doxygen executable exists
        if [ ! -f "$WIN_DOXYGEN_EXEC" ]; then
            echo "Please run Setup before trying to generate docs!"
            exit 1
        fi
        
        # Run the Windows version of Doxygen in WSL
        "$WIN_DOXYGEN_EXEC" Doxyfile
    else
        # We're running in Linux
        echo "Running in Linux"
        
        # Path to the Linux Doxygen executable
        DOXYGEN_EXEC="./3rdparties/linux/doxygen/doxygen"
        
        # Check if the Linux Doxygen executable exists
        if [ ! -f "$DOXYGEN_EXEC" ]; then
            echo "Please run Setup before trying to generate docs!"
            exit 1
        fi
        
        # Run the native Linux Doxygen binary
        "$DOXYGEN_EXEC" Doxyfile
    fi
    
    exit 0  # Exit after running Doxygen normally
fi

# Determine if running in WSL or Linux
if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null; then
    # We're running in WSL (Windows Subsystem for Linux)
    echo "Running in Windows Subsystem for Linux (WSL)"
    
    # Path to the Windows Doxygen executable
    WIN_DOXYGEN_EXEC="./3rdparties/windows/doxygen/doxygen.exe"
    
    # Check if the Windows Doxygen executable exists
    if [ ! -f "$WIN_DOXYGEN_EXEC" ]; then
        echo "Please run Setup before trying to generate docs!"
        exit 1
    fi
    
else
    # We're running in Linux
    echo "Running in Linux"
    
    # Path to the Linux Doxygen executable
    DOXYGEN_EXEC="./3rdparties/linux/doxygen/doxygen"
    
    # Check if the Linux Doxygen executable exists
    if [ ! -f "$DOXYGEN_EXEC" ]; then
        echo "Please run Setup before trying to generate docs!"
        exit 1
    fi
fi

# Find modified files in the src directories since the last commit
MODIFIED_FILES=$(git diff --name-only HEAD | grep -E "^(Corylium/src|Sandbox/src)/.*\.(cpp|h)$")

# Check if there are any modified files
if [ -z "$MODIFIED_FILES" ]; then
    echo "No changes detected in source files since the last commit. Skipping documentation generation."
    exit 0
fi

echo "Generating documentation for modified files:"
echo "$MODIFIED_FILES"

# Create a temporary Doxygen file with only modified files as input
cp Doxyfile Doxyfile.tmp

# Replace the INPUT line in the temporary Doxyfile to include only modified files
sed -i '/^INPUT/c\INPUT = '"$MODIFIED_FILES" Doxyfile.tmp

# Run Doxygen with the appropriate executable based on the platform
if grep -qEi "(Microsoft|WSL)" /proc/version &> /dev/null; then
    # Run the Windows version of Doxygen in WSL using the Windows path
    "$WIN_DOXYGEN_EXEC" Doxyfile.tmp
else
    # Run the native Linux Doxygen binary
    "$DOXYGEN_EXEC" Doxyfile.tmp
fi

# Remove the temporary Doxyfile
rm Doxyfile.tmp

# Notify the user that the process is complete
echo "Documentation generation complete."
popd
