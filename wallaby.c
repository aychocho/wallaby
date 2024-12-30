#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include "nvml.h"  // nvml headers for typing

typedef void* (*real_dlsym_t)(void*, const char*);

typedef nvmlReturn_t (*nvmlDeviceGetName_t)(nvmlDevice_t device, char* name, unsigned int length);

// fake nvmlDeviceGetName function
nvmlReturn_t wallaby(unsigned int device, char* name, unsigned int length) {
    printf("[Interception] Spoofing GPU name\n");
    fflush(stdout);
    snprintf(name, length, "PWNED! I OWN you now."); // replace gpu name
    return NVML_SUCCESS; // return NVML success
}

// dlsym intercept
void* dlsym(void* handle, const char* symbol) {

    printf("[DEBUG] symbol: %s\n", symbol);
    fflush(stdout);
    // check if symbol is nvmldevicegetname
    if (strcmp(symbol, "nvmlDeviceGetName") == 0) {
        printf("[Interception] Intercepted nvmlDeviceGetName!\n");
        fflush(stdout);
        // return addr of fake nvmldevicegetname
        return (void*)wallaby;
    } else {
        // call create a real call to dlsym to redirect requests we don't care about
        static real_dlsym_t realDlsym = NULL;
        //link realdlsym to dlvsym, which is the same thing, but needs a version
        realDlsym = (real_dlsym_t)dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.2.5");
        //call realdlsym for all non-nvmldevicegetname requests
        return realDlsym(handle, symbol);
    }

}


