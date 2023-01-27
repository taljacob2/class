# Release

This doc tells how to create a new release, and push it to GitHub Releases
at https://api.github.com/repos/taljacob2/oop/releases

## Building The Release Assets Locally

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

## Uploading A Release To GitHub

