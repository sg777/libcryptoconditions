make
gcc test.c -o test -Iinclude -Isrc/asn -Isrc/include -Isrc -L/home/sarat/libcryptoconditions/.libs -lcryptoconditions
./test
