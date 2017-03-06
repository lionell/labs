genrule(
		name = "mpi_compile",
		srcs = ["src/mpi.cc"],
		outs = ["mpi.a"],
		cmd = "mpic++ -L/usr/lib -lgflags -I/home/lionell/dev/labs/parallel_prog \
				-o $@ $< $(locations //lib:pagerank) $(locations //lib:io) $(locations //lib:math) \
				$(locations //lib:page) $(locations //lib:utils) $(locations //lib:logging)",
		tools = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:page",
				"//lib:utils",
				"//lib:logging",
				"//data",
		],
		executable = 1,
		output_to_bindir = 1,
)

genrule(
		name = "mpi",
		outs = ["mpi.sh"],
		cmd = "echo '#!/usr/bin/env sh' > $@; \
				echo 'mpirun -np 1 $(location :mpi_compile) $$@' >> $@",
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
				"//lib:logging",
		],
		data = [
				"//data",
		],
		linkopts = [
				"-L/usr/lib",
				"-lgflags"
		],
)
