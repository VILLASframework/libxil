# Packaging

## Archlinux

The `PKGBUILD` script describes the Archlinux package and will download a git
snapshot of the project (fixed hash). If you want to update the package, please
adjust the `COMMIT=...` line to the commit hash of your liking.

```bash
$ cd packaging/
$ makepkg
$ sudo pacman -U libxil-0.1-1-x86_64.pkg.tar.xz
```
