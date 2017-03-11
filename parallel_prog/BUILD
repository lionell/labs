genrule(
		name = "mpi_compile",
		srcs = ["src/mpi.cc"],
		outs = ["mpi.a"],
		cmd = "mpic++ -L/usr/lib -lgflags -lglog -lprotobuf -I/home/lionell/dev/labs/parallel_prog -I$(GENDIR) \
				-o $@ $< $(locations //lib:pagerank) $(BINDIR)/lib/libio.a $(locations //lib:math) \
				$(BINDIR)/proto/libpage_proto.a $(BINDIR)/proto/libchunk_proto.a $(BINDIR)/proto/libmetadata_proto.a \
				$(locations //lib:benchmark)",
		tools = [
				"//proto:page_cc_proto",
				"//proto:chunk_cc_proto",
				"//proto:metadata_cc_proto",
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
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
		name = "omp",
		srcs = ["src/omp.cc"],
		deps = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:benchmark",
		],
		data = ["//data"],
		copts = [
				"-fopenmp",
		],
		linkopts = [
				"-lgflags",
				"-lglog",
				"-fopenmp",
		],
)

cc_binary(
		name = "serial",
		srcs = ["src/serial.cc"],
		deps = [
				"//lib:pagerank",
				"//lib:io",
				"//lib:math",
				"//lib:benchmark",
		],
		data = ["//data"],
		linkopts = [
				"-lgflags",
				"-lglog",
		],
)

cc_binary(
		name = "test",
		srcs = ["src/test.cc"],
		deps = [
				"//lib:io",
		],
		linkopts = [
				"-lgflags",
		],
)
