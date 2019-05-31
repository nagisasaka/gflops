# gflops
Simple GFLOPS measurement tool for ARM53 with NEON

### Overview

This simple tool can estimate single core GFLOPS with using GEMM calculation. Note that it's very simple but NOT accurate.
You can also use this tool for x86_64 architecture.

### Build

``````````.sh
$ make -f Makefile.arm53
``````````

You can use `Makefile.x86_64` for x86_64 architecture.

### Test

``````````.sh
$ ./p1.arm53
``````````

You can use `p1.x86_64` for x86_64 architecture.

### Sample Result

##### Raspberry Pi CM3

``````````.sh
DGEMM: 0.886263 GFLOPS ( 677 [ms] )
SGEMM: 2.18978 GFLOPS ( 274 [ms] )
IGEMM: 2.47934 GFLOPS ( 242 [ms] )
``````````

DGEMM uses double-precision floating point, SGEMM uses single-precision floating point and IGEMM uses int32_t integer. In Raspberry Pi CM3, NEON is enabled only for SGEMM because the OS is 32bit.

##### MacBook Pro 2018 ( 2.7 GHz Intel Core i7 )

``````````.sh
DGEMM: 33.3333 GFLOPS ( 18 [ms] )
SGEMM: 75 GFLOPS ( 8 [ms] )
IGEMM: 22.2222 GFLOPS ( 27 [ms] )
``````````
