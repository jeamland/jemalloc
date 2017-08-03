#define JEMALLOC_TESTING_C_
#include "jemalloc/internal/jemalloc_preamble.h"
#include "jemalloc/internal/jemalloc_internal_includes.h"

#include "jemalloc/internal/testing.h"

static malloc_mutex_t	testing_mtx;

int	testing_malloc_fail = 0;

int
testing_malloc_fail_get(tsdn_t *tsdn) {
	int testing_malloc_fail_current;

	malloc_mutex_lock(tsdn, &testing_mtx);
	testing_malloc_fail_current = testing_malloc_fail;
	malloc_mutex_unlock(tsdn, &testing_mtx);
	return testing_malloc_fail_current;
}

int
testing_malloc_fail_set(tsdn_t *tsdn, int code) {
	int testing_malloc_fail_old;

	malloc_mutex_lock(tsdn, &testing_mtx);
	testing_malloc_fail_old = testing_malloc_fail;
	testing_malloc_fail = code;
	malloc_mutex_unlock(tsdn, &testing_mtx);
	return testing_malloc_fail_old;
}

int
testing_malloc_fail_get_and_clear(tsdn_t *tsdn) {
	int testing_malloc_fail_current;

	malloc_mutex_lock(tsdn, &testing_mtx);
	testing_malloc_fail_current = testing_malloc_fail;
	testing_malloc_fail = 0;
	malloc_mutex_unlock(tsdn, &testing_mtx);
	return testing_malloc_fail_current;
}
