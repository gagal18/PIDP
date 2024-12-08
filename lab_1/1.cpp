#include <mpi.h>
#include <iostream>

using namespace std;
void initializeMPI(int &argc, char **&argv) {
    MPI_Init(&argc, &argv);
}

void finalizeMPI() {
    MPI_Finalize();
}

int main(int argc, char **argv) {
    initializeMPI(argc, argv);

    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);

    int worldRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);

    cout << "Process with rank " << worldRank << " from " << worldSize << " processes" << std::endl;

    finalizeMPI();
    return 0;
}

