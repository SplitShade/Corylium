call Setup.py ../3rdparties\windows\vendor_versions_project_windows.txt
pushd ..
call 3rdparties\windows\premake\premake5.exe vs2022
popd