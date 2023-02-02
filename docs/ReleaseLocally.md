# Release Locally

There probably should be no reason for you to execute `release.bat` manually by yourself,
but this is how it works: 

1. Builds the final static libraries (i.e. `oop.a`, `oop.lib`), and places them at the `release` directory.
2. Copies the header files (i.e. `.r`, `.h`), and places them at the `release` directory.
3. Creates archives (i.e. `.tar.gz`, `.zip`) for `gcc` and `msvc` compilers, that contain the static library and its header files (from steps 1 and 2), and places them at the `release` directory.

Screenshot example, after executing `release.bat`:

![image](https://user-images.githubusercontent.com/70590583/216243905-9afd8c5b-1e28-428b-bf3c-12854dd24fa4.png)


## Build The Release Assets Locally

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
