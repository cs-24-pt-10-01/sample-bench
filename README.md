# sample-bench

Test for fibonacci head recursive.

Assuming thor repository is cloned in the current directory.

Run with:

```sh
gcc fibhead.c -O3 -L./thor/target/release -lthor_local_client -Wl,-rpath=./thor/target/release -finstrument-functions
./a.out 47
```

```sh
clang fibhead.c -O3 -L./thor/target/release -lthor_local_client -Wl,-rpath=./thor/target/release -finstrument-functions
```
