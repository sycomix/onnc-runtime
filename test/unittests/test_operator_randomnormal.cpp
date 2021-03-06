#include <skypat/skypat.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdio.h>

#define restrict __restrict__
extern "C"{
#include <operator/randomnormal.h>
}
#undef restrict

SKYPAT_F(Operator_RandomNormal, non_broadcast){
    // Prepare
    //rand the seed
    srand(time(NULL));

    float seed = rand() % 10;
    srand(seed);
    int32_t ndim = rand() % 3 + 1;
    int32_t dims[ndim];
    int32_t dataSize = 1;
    int32_t shape[ndim];
    int32_t number_of_shape = ndim;
    
    printf("ndim:%d\ndims:\n", ndim);

    for(int32_t i = 0; i < ndim; ++i){
        dims[i] = rand() % 100 + 1;
        shape[i] = dims[i];
        dataSize *= dims[i];
        printf("%d ", dims[i]);
    }
    printf("\nSamples:\n");

    float Output[dataSize], Ans[dataSize];

    // Run
    ONNC_RUNTIME_randomnormal_float(NULL
        ,Output
        ,ndim,dims
        ,0
        ,0
        ,1
        ,seed
        ,shape
        ,number_of_shape
    );

    // Check
    // ONNC_runtime_randomuniform_float runs its own rand() , 
    // So it doesnt match with the rand() outside the funtion call
    for(int32_t i = 0; i < dataSize; ++i){
        printf("%10f\n", Output[i]);
    }
    printf("data size : %d", dataSize);
}

int main(int argc, char *argv[]){
    skypat::Test::Initialize(argc, argv);
    skypat::Test::RunAll();
    return (skypat::testing::UnitTest::self()->getNumOfFails() == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}