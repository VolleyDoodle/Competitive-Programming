# Competitive Programming

Practice solutions, contest attempts, training notes, and local learning tools.
Some solutions are incomplete or assisted; file presence does not imply an
accepted or independent solve.

| Directory | Contents |
| --- | --- |
| `CSES/` | CSES practice |
| `Codeforces/` | Codeforces and other problem sets |
| `USACO/` | USACO practice and older contest projects |

Historical problem folders retain their original names and locations. Some
older USACO folders contain Visual Studio `.sln` and `.vcxproj` definitions;
these are project configuration, so they are preserved alongside the sources.

## Working locally

Keep source files and useful test inputs. Compiled programs, generated editor
caches, and runtime `.out` files are ignored. Existing extensionless executable
names have explicit ignore entries; use `build/` or `/tmp` for new binaries.
Ignoring a path does not untrack a file already recorded in Git.

For example, compile a solution to a temporary executable:

```sh
g++ -std=c++17 -O2 -Wall Codeforces/round1039Div2/d.cpp -o /tmp/cp-d
```

Check the solution's input setup before running it. Many older files use
`freopen` and expect input/output files in their working directory.

The local workspace also contains `training/`, `tools/state-lens/`, and a root
`.vscode/` setup. These are separate work and are not published by the cleanup
commit.

## October 17, 2026 cleanup

Removed generated Visual Studio `.vs` caches, personal `.vcxproj.user` files,
compiled programs, and generated build trees. Source files, test inputs,
existing output files, and shared editor configurations were preserved.

`.vs/repos` was Visual Studio's generated state for the old `repos` project:
file indexes, locks, and user settings. It was not another Git repository.
The old `MachineLearning/`, `gameDev/`, and root `repos.pyproj` were already
absent from disk before this cleanup; their existing Git deletions were left
intact. Git history still contains those projects until history is explicitly
rewritten; no history was changed here.

Removed artifacts are backed up under ignored `.local-backup/`. The
`latest-summary.json` file identifies the archive and its per-file manifest,
including hashes. Restore individual files, if needed, from the repository
root with:

```sh
tar -xzf .local-backup/cleanup-TIMESTAMP.tar.gz -- path/from/manifest
```

Replace the archive and file names with the recorded paths. The backup stays
on this machine and is not included in Git.
