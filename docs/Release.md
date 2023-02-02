# Release

This doc tells how to create a new release, and push it to GitHub Releases
at https://api.github.com/repos/taljacob2/oop/releases

## Upload A Release With Assets To GitHub

Uploads a Release to GitHub, and attaches the assets at the `release` directory to it.

- ### THE RECOMMENDED WAY (Currently The ONLY Way To Do So):

  If you own a Windows machine, **with** WSL installed, you may build both the GCC and MSVC releases at once, by opening CMD and running:
  ```
  push-release.bat -token <YOUR-TOKEN> -tagname <EXISTING-TAG-NAME> [-name <"RELEASE-NAME">] [-prerelease <true/false>] [-body <"RELEASE-BODY">] [-draft <true/false>]
  ```
  > NOTE: This script executes `release.bat` for creating the local releases builds at the `release` directory.
  >> For further information about `release.bat` see [ReleaseLocally.md](ReleaseLocally.md).

  For more information about `push-release.bat` and how to use it, run:
  ```
  push-release.bat help
  ```
