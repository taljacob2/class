# Release Locally

There probably should be no reason for you to execute `release.bat` manually by yourself,
but this is how it works: 

## Build The Release Assets Locally

Builds the final static library and its header files to the `release` directory, and archives them (i.e. `.zip`, `.tar.gz`).

- ### **(THE RECOMMENDED WAY):** Build MSVC And GCC At Once

  If you own a Windows machine, **with** WSL installed, you may build both the GCC and MSVC releases at once, by opening CMD and running:
  ```
  release.bat
  ```

- ### Build Only MSVC 

  In case you have a Windows machine **without** WSL installed, then **you may
only build the MSVC release**, by opening CMD and running:
  ```
  release-msvc.bat
  ```

- ### Build Only GCC

  In case you have a *NIX machine, then **you may only build the GCC release**, by
 opening the terminal and running:
  ```
  ./release-gcc.sh
  ```
