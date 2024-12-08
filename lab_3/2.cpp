#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Request send_request, recv_request;
    MPI_Status status;
    int BUFF_SIZE = 128;
    if (size < 4) {
        if (rank == 0) {
            printf("Must have at least 4 processes");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            char send_buf[BUFF_SIZE];
            snprintf(send_buf, sizeof(send_buf), "From 0 to P:%d", i);
            MPI_Isend(send_buf, strlen(send_buf) + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD, &send_request);
            MPI_Wait(&send_request, &status);
            printf("Info: Process 0 sent message to P:%d.\n", i);
        }

        for (int i = 1; i < size; i++) {
            char recv_buf[BUFF_SIZE];
            MPI_Irecv(recv_buf, sizeof(recv_buf), MPI_CHAR, i, 0, MPI_COMM_WORLD, &recv_request);
            MPI_Wait(&recv_request, &status);
            printf("Info: Process 0 got message: %s\n", recv_buf);
        }
    } else {
        char recv_buf[BUFF_SIZE];
        MPI_Irecv(recv_buf, sizeof(recv_buf), MPI_CHAR, 0, 0, MPI_COMM_WORLD, &recv_request);
        MPI_Wait(&recv_request, &status);
        printf("Info: Process %d got message: %s\n", rank, recv_buf);

        char send_buf[BUFF_SIZE];
        snprintf(send_buf, sizeof(send_buf), "Return message from P%d to P0", rank);
        MPI_Isend(send_buf, strlen(send_buf) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &send_request);
        MPI_Wait(&send_request, &status);
    }

    MPI_Finalize();
    return 0;
}
