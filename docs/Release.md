# Release

This doc tells how to create a new release, and push it to GitHub Releases
at https://api.github.com/repos/taljacob2/oop/releases

## Build The Release Assets Locally (Probably there should be no reason for you to use this)

Builds the final static library and its header files to the `release` directory, and archives them (i.e. `.zip`, `.tar.gz`).

- ### The recommended way:

  If you own a Windows machine, **with** WSL installed, you may build both the GCC and MSVC releases at once, by opening CMD and running:
  ```
  release.bat
  ```

- In case you have a Windows machine **without** WSL installed, then you may
only build the MSVC release, by opening CMD and running:
  ```
  release-msvc.bat
  ```

- In case you have a *NIX machine, then you may only build the GCC release, by
 opening the terminal and running:
  ```
  ./release-gcc.sh
  ```

## Upload A Release With Assets To GitHub

Uploads a Release to GitHub, and attaches the assets in the `release` directory to it.

- ### The recommended way (currently the ONLY way to do so):

  If you own a Windows machine, **with** WSL installed, you may build both the GCC and MSVC releases at once, by opening CMD and running:
  ```
  push-release.bat -token <YOUR-TOKEN> -tagname <EXISTING-TAG-NAME> [-name <"RELEASE-NAME">] [-prerelease <true/false>] [-body <"RELEASE-BODY">] [-draft <true/false>]
  ```
  > NOTE: This script executes `release.bat` for creating the local releases builds at the `release` directory.

  For more information about `push-release.bat` and how to use it, run:
  ```
  push-release.bat help
  ```
