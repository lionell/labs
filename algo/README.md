# Parallel RNG

All examples are using Bazel as a main build system.

Let's generate 10,000,000 random numbers.

```
$ bazel run :random -- --n 2500000 --k 4 --output $(pwd)/out/10m_4t
INFO: Found 1 target...
Target //:random up-to-date:
  bazel-bin/random
INFO: Elapsed time: 0.041s, Critical Path: 0.00s

INFO: Running command line: bazel-bin/random --n 2500000 --k 4 --output /home/lionell/dev/labs/algo/out/10m_4t
I0318 13:38:44.870348  3702 random.cc:58] R=4294967295, M=10019, M^k=262120981
I0318 13:38:44.872545  3702 random.cc:31] [0]: u0=1234
I0318 13:38:44.872555  3705 random.cc:31] [3]: u0=3487891871
I0318 13:38:44.872545  3704 random.cc:31] [2]: u0=3610281214
I0318 13:38:44.872545  3703 random.cc:31] [1]: u0=12363446
I0318 13:38:45.205608  3702 benchmark.h:37] Generation took 1.304133s cpu, 0.335000s wall.
```

Now, we have generated 4 chunks of random data.

```
$ ls -lh out/
total 103M
-rw-r--r-- 1 lionell lionell 26M бер 18 13:39 10m_4t.0
-rw-r--r-- 1 lionell lionell 26M бер 18 13:39 10m_4t.1
-rw-r--r-- 1 lionell lionell 26M бер 18 13:39 10m_4t.2
-rw-r--r-- 1 lionell lionell 26M бер 18 13:39 10m_4t.3
```

Let's concatenate them into one huge file containing 10M random numbers.

```
$ bazel run :concat $(pwd)/out/10m_4t 4
INFO: Found 1 target...
Target //:concat up-to-date:
  bazel-bin/concat
INFO: Elapsed time: 0.050s, Critical Path: 0.00s

INFO: Running command line: bazel-bin/concat /home/lionell/dev/labs/algo/out/10m_4t 4
```

Now we have one file containing all generated random numbers.

```
$ ls -lh out/
total 205M
-rw-r--r-- 1 lionell lionell 103M бер 18 13:40 10m_4t
-rw-r--r-- 1 lionell lionell  26M бер 18 13:39 10m_4t.0
-rw-r--r-- 1 lionell lionell  26M бер 18 13:39 10m_4t.1
-rw-r--r-- 1 lionell lionell  26M бер 18 13:39 10m_4t.2
-rw-r--r-- 1 lionell lionell  26M бер 18 13:39 10m_4t.3
```

Let's generate another one file running `:generate` in just one thread.

```
$ bazel run :random -- --n 10000000 --k 1 --output $(pwd)/out/10m_1t
INFO: Found 1 target...
Target //:random up-to-date:
  bazel-bin/random
INFO: Elapsed time: 0.061s, Critical Path: 0.00s

INFO: Running command line: bazel-bin/random --n 10000000 --k 1 --output /home/lionell/dev/labs/algo/out/10m_1t
I0318 13:46:10.093510 13557 random.cc:58] R=4294967295, M=10019, M^k=10019
I0318 13:46:10.093595 13557 random.cc:31] [0]: u0=1234
I0318 13:46:10.783151 13557 benchmark.h:37] Generation took 0.689168s cpu, 0.689000s wall.
```

Finally, let's make sure that files are the same. We can just run `diff out/10m_4t out/10m_1t`.
