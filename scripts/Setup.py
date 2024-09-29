import os
import re
import requests
import shutil
import zipfile
import sys

# Function to download a file
def download_file(url, dest_folder, tool_name):
    try:
        # Get the content of the URL
        response = requests.get(url)
        response.raise_for_status()  # Check for HTTP errors

        # Create folder for the tool if it doesn't exist
        os.makedirs(dest_folder, exist_ok=True)

        # Determine the file name (the name from the URL)
        file_name = url.split("/")[-1]
        file_path = os.path.join(dest_folder, file_name)

        # Write content to file
        with open(file_path, "wb") as file:
            file.write(response.content)

        print(f"{tool_name} downloaded and saved to {file_path}")
        return file_path
    except requests.exceptions.RequestException as e:
        print(f"Failed to download {tool_name}: {e}")
        return None

# Function to extract an archive and move its contents up one level
def extract_and_cleanup(file_path, dest_folder, tool_name):
    try:
        # Check if the file is a zip archive
        if zipfile.is_zipfile(file_path):
            with zipfile.ZipFile(file_path, 'r') as zip_ref:
                zip_ref.extractall(dest_folder)

            # Delete the zip file
            os.remove(file_path)
            # Find the only folder in the destination directory
            extracted_items = os.listdir(dest_folder)
            subfolders = [item for item in extracted_items if os.path.isdir(os.path.join(dest_folder, item))]
            if len(subfolders) == 1 and subfolders[0].lower().startswith(tool_name):
                extracted_folder = os.path.join(dest_folder, subfolders[0])

                # Move contents up one level
                for item in os.listdir(extracted_folder):
                    s = os.path.join(extracted_folder, item)
                    d = os.path.join(dest_folder, item)
                    shutil.move(s, d)

                # Remove the now-empty extracted folder
                os.rmdir(extracted_folder)

                print(f"Extracted and cleaned up archive: {file_path}")
            else:
                print(f"Error: Expected one folder in {dest_folder}, found {len(subfolders)}")
        else:
            print(f"File is not a valid zip archive: {file_path}")
    except Exception as e:
        print(f"Failed to extract and clean up {file_path}: {e}")

# Function to read the document and download tools
def download_tools(document_path):
    with open(document_path, "r") as file:
        for line in file:
            # Skip the header or separator lines
            if line.startswith("Tool Name") or line.startswith("---"):
                continue
            
            # Skip lines that don't end with ".zip"
            if not line.rstrip().endswith(".zip"):
                continue

            # Extract tool name and URL
            parts = re.split(r'\s{2,}', line.strip())
            print(parts)
            if len(parts) == 3:
                tool_name = parts[0]
                url = parts[2]

                # Create a folder named after the tool name
                tool_folder = os.path.join(os.path.dirname(document_path), f"{tool_name}")
                
                # Download the tool from the URL
                file_path = download_file(url, tool_folder, tool_name)
                
                # If download succeeded and it's an archive, extract and clean up
                if file_path and file_path.endswith(".zip"):
                    extract_and_cleanup(file_path, tool_folder, tool_name)

if __name__ == "__main__":
    # Check if a document path was provided
    if len(sys.argv) != 2:
        print("Usage: python script.py <document_path>")
        sys.exit(1)

    # Get the document path from command line arguments
    document_path = sys.argv[1]
    
    download_tools(document_path)
