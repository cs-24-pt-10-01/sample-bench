# sample-bench

Assuming thor repository is cloned in the current directory.

Run with:

```sh
gcc fibh.c -O3 -L./thor/target/release -lthor_local_client -Wl,-rpath=./thor/target/release
./a.out 47
```
