genrule(
		name = "mpi_compile",
		srcs = ["src/mpi.cc"],
		outs = ["mpi.a"],
		cmd = "mpic++ -L/usr/lib -lgflags -lglog -I/home/lionell/dev/labs/parallel_prog \
				-o $@ $< $(locations //lib:pagerank) $(locations //lib:io) $(locations //lib:math) \
				$(locations //lib:page) $(locations //lib:utils) $(locations //lib:benchmark)",
		tools = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:page",
				"//lib:utils",
				"//lib:benchmark",
				"//data",
		],
		executable = 1,
		output_to_bindir = 1,
)

genrule(
		name = "mpi",
		outs = ["mpi.sh"],
		cmd = "echo '#!/usr/bin/env sh' > $@; \
				echo 'mpirun -np 4 $(location :mpi_compile) $$@' >> $@",
		tools = [
				":mpi_compile",
		],
		executable = 1,
		output_to_bindir = 1,
)

cc_binary(
		name = "serial",
		srcs = ["src/serial.cc"],
		deps = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:page",
				"//lib:utils",
				"//lib:benchmark",
		],
		data = [
				"//data",
		],
		linkopts = [
				"-lgflags",
				"-lglog",
		],
)

cc_binary(
		name = "omp",
		srcs = ["src/omp.cc"],
		deps = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:page",
				"//lib:utils",
				"//lib:benchmark",
		],
		data = [
				"//data",
		],
		copts = [
				"-fopenmp",
		],
		linkopts = [
				"-lgflags",
				"-lglog",
				"-fopenmp",
		],
)
