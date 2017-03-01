#ifndef MPI_TYPES_H_
#define MPI_TYPES_H_

#include <mpi.h>
#include "page.h"

MPI_Datatype MPI_Page;

MPI_Datatype GetPageDatatype() {
	int blocks[] = {1, 1, kPageMaxLinkCnt};
	MPI_Datatype types[] = {MPI_INT, MPI_INT, MPI_INT};

	MPI_Aint intex;
	MPI_Type_extent(MPI_INT, &intex);

	MPI_Aint displacements[3];
	displacements[0] = static_cast<MPI_Aint>(0);
	displacements[1] = intex;
	displacements[2] = 2 * intex;

	MPI_Datatype page_type;
	MPI_Type_struct(3, blocks, displacements, types, &page_type);
	return page_type;
}

void RegisterMpiDatatypes() {
	MPI_Page = GetPageDatatype();
	MPI_Type_commit(&MPI_Page);
}

void FreeMpiDatatypes() {
	MPI_Type_free(&MPI_Page);
}

MPI_Datatype kMpiIntIntPair;

#endif // MPI_TYPES_H_
